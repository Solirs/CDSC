#include <stdio.h>
#include "bloomfilter.h"
// Constants for the hash_fn
#define CAPACITY 1000
#define OFFSET 14695981039346656037UL
#define PRIME 1099511628211UL

// An example hashing function (FNV)
unsigned long cdsc_bf_hash(const char *key) {
    unsigned long hash = OFFSET;
    for (const char *p = key; *p; p++) {
	hash ^= (unsigned long) (*p);
	hash *= PRIME;
    }
    return hash;
}
unsigned long hash(const char *str)
{

    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
uint32_t MurmurOAAT_32(const char* str)
{
    int h = PRIME;
    // One-byte-at-a-time hash based on Murmur's mix
    // Source: https://github.com/aappleby/smhasher/blob/master/src/Hashes.cpp
    for (; *str; ++str) {
        h ^= *str;
        h *= 0x5bd1e995;
        h ^= h >> 15;
    }
    return h;
}
uint32_t KR_v2_hash(const char *s)
{
    // Source: https://stackoverflow.com/a/45641002/5407270
    // a.k.a. Java String hashCode()
    uint32_t hashval = 0;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31*hashval;
    return hashval;
}

int main(){
    struct cdsc_bloomfilter *filter = cdsc_bloomfilter_create(8900);
    cdsc_bloomfilter_addhashfun(filter, hash);
    cdsc_bloomfilter_addhashfun(filter, MurmurOAAT_32);
    cdsc_bloomfilter_addhashfun(filter, KR_v2_hash);
    cdsc_bloomfilter_addhashfun(filter, cdsc_bf_hash);

    char *str = "Hello";
    cdsc_bloomfilter_add(filter, str);
    cdsc_bloomfilter_add(filter, "Lorem ipsum dolor sit amet, consectetur adipiscing");
    cdsc_bloomfilter_add(filter, "heyy :33");

    printf("%d\n", cdsc_bloomfilter_check(filter, str));
    printf("%d\n", cdsc_bloomfilter_check(filter, "Lorem ipsum dolor sit amet, consectetur adipiscing"));
    printf("%d\n", cdsc_bloomfilter_check(filter, "I am not in the bloom filter"));

    /*while (1){  
        printf("Input a string: ");
        fgets(str, sizeof(str), stdin); 
        cdsc_bloomfilter_add(filter, trim(str));
        printf("\n");
        printf("Lookup bloom filter: ");
        fgets(str, sizeof(str), stdin); 
        if (cdsc_bloomfilter_check(filter, trim(str))){
            printf("The string is possibly in the set\n");
        }else{
            printf("The string is definitely not in the set\n");
        }
        printf("Exit?: ");
        fgets(str, sizeof(str), stdin); 
        printf("%s", str);
        if (trim(str) != "n"){
            break;
        }
    }*/
    cdsc_bloomfilter_nuke(filter);
    return 0;
}