#include "bloomfilter.h"

#define HASH_CONSTANT 0x124fa274


// Murmurhash implementation from https://github.com/aappleby/smhasher/blob/master/src/MurmurHash2.cpp.
// Under the public domain.
uint32_t _MurmurHash2 ( const void * key, int len, uint32_t seed )
{
  // 'm' and 'r' are mixing constants generated offline.
  // They're not really 'magic', they just happen to work well.

  const uint32_t m = 0x5bd1e995;
  const int r = 24;

  // Initialize the hash to a 'random' value

  uint32_t h = seed ^ len;

  // Mix 4 bytes at a time into the hash

  const unsigned char * data = (const unsigned char *)key;

  while(len >= 4)
  {
    uint32_t k = *(uint32_t*)data;

    k *= m;
    k ^= k >> r;
    k *= m;

    h *= m;
    h ^= k;

    data += 4;
    len -= 4;
  }

  // Handle the last few bytes of the input array

  switch(len)
  {
  case 3: h ^= data[2] << 16;
  case 2: h ^= data[1] << 8;
  case 1: h ^= data[0];
      h *= m;
  };

  // Do a few final mixes of the hash to ensure the last few
  // bytes are well-incorporated.

  h ^= h >> 13;
  h *= m;
  h ^= h >> 15;

  return h;
} 


// Allocate new bloomfilter
struct cdsc_bloomfilter* cdsc_bloomfilter_create(int elements, double fpr){
    struct cdsc_bloomfilter* ret = malloc(sizeof(struct cdsc_bloomfilter));
    ret->size = cdsc_bloomfilter_getoptsize(elements, fpr);
    ret->bitarray = calloc(ret->size/32 + 1, sizeof(int32_t));
    ret->numhfuncs = cdsc_bloomfilter_getnumhfuncs(ret->size, elements);
    ret->hashfunc = _MurmurHash2;

    return ret;
}

// Nuke and free bloom filter
void cdsc_bloomfilter_nuke(struct cdsc_bloomfilter* bf){
    free(bf->bitarray);
    free(bf);
}

// Add data to the bloom filter
void cdsc_bloomfilter_add(struct cdsc_bloomfilter* bf, void* data, int32_t len){

    // We make two hashes and differentiate them for each hash function, then set the bit at each hash's index to 1

    uint32_t hash = bf->hashfunc(data, len,  HASH_CONSTANT);
    uint32_t hash2 = bf->hashfunc(data, len, hash);
    for (int i = 0;  i < bf->numhfuncs; i++){
        cdsc_bitarray_set1(bf->bitarray, (hash + hash2*i) % bf->size);
    }
}

int cdsc_bloomfilter_check(struct cdsc_bloomfilter* bf, void* data, int32_t len){

    
    // We make two hashes and differentiate them for every hash function, if one of the obtained indexes fall on a 0 then 
    // The data is definitely not in the filter (0), otherwise it possibly is (1).
    uint32_t hash = bf->hashfunc(data, len, HASH_CONSTANT);
    uint32_t hash2 = bf->hashfunc(data, len, hash);
    for (int i = 0;  i < bf->numhfuncs; i++){
        if (cdsc_bitarray_is0(bf->bitarray, (hash + hash2*i) % bf->size)){
            return 0;
        }
    }    
    return 1;
}


// Add a hash function to the bloomfilter
void cdsc_bloomfilter_sethashfun(struct cdsc_bloomfilter* bf, unsigned int (*hashfun)(void*)){
    bf->hashfunc = hashfun;
}


// Get the optimal bitarray size according to the desired false positive probability and the number of elements
// formula: -n*ln(fpr)/ln(2)²
// See https://en.wikipedia.org/wiki/Bloom_filter#Probability_of_false_positives
int32_t cdsc_bloomfilter_getoptsize(int elements, double fpr){    
    return ceil(((-elements*log(fpr))/(log(2)*log(2))));
}


// Determine the optimal number of hash functions according to the size of the array in bits and elements.
// formula: (m/n)*ln(2)²
// See https://en.wikipedia.org/wiki/Bloom_filter#Probability_of_false_positives
int32_t cdsc_bloomfilter_getnumhfuncs(int size, int elements){
    return ceil((size/elements)*log(2));
}