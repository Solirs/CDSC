#include "bloomfilter.h"


// Allocate new bloomfilter
struct cdsc_bloomfilter* cdsc_bloomfilter_create(int size){
    struct cdsc_bloomfilter* ret = malloc(sizeof(struct cdsc_bloomfilter));
    ret->size = size;
    ret->bitarray = malloc(size/8 + 1);
    ret->numhfuncs = 0;
    return ret;
}

// Nuke and free bloom filter
void cdsc_bloomfilter_nuke(struct cdsc_bloomfilter* bf){
    free(bf->bitarray);
    free(bf);
}

// Add data to the bloom filter
void cdsc_bloomfilter_add(struct cdsc_bloomfilter* bf, void* data){
    // We hash the data with every hash function and set the bit at that index to 1
    for (int i = 0;  i < bf->numhfuncs; i++){
        cdsc_bitarray_set1(bf->bitarray, bf->hashfuncs[i](data));
    }
}

int cdsc_bloomfilter_check(struct cdsc_bloomfilter* bf, void* data){

    
    // We hash the data with every hash function, if one of the obtained indexes fall on a 0 then 
    // The data is definitely not in the filter (0), otherwise it possibly is (1).
    for (int i = 0;  i < bf->numhfuncs; i++){
        if (!cdsc_bitarray_is1(bf->bitarray, bf->hashfuncs[i](data))){
            return 0;
        }
    }    
    return 1;
}


// Add a hash function to the bloomfilter
void cdsc_bloomfilter_addhashfun(struct cdsc_bloomfilter* bf, int (*hashfun)(void*)){
    bf->hashfuncs[bf->numhfuncs] = hashfun;
    bf->numhfuncs++;
}