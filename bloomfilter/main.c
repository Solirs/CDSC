#include <stdio.h>
#include "bloomfilter.h"

#define PRIME 1099511628211UL

uint32_t x17(const void * key, int len, uint32_t h)
{
    // Source: https://github.com/aappleby/smhasher/blob/master/src/Hashes.cpp
    const uint8_t * data = (const uint8_t*)key;
    for (int i = 0; i < len; ++i)
    {
        h = 17 * h + (data[i] - ' ');
    }
    return h ^ (h >> 16);
}

uint32_t crc32b(const uint8_t *str) {
    // Source: https://stackoverflow.com/a/21001712
    unsigned int byte, crc, mask;
    int i = 0, j;
    crc = 0xFFFFFFFF;
    while (str[i] != 0) {
        byte = str[i];
        crc = crc ^ byte;
        for (j = 7; j >= 0; j--) {
            mask = -(crc & 1);
            crc = (crc >> 1) ^ (0xEDB88320 & mask);
        }
        i = i + 1;
    }
    return ~crc;
}
uint32_t MurmurOAAT_32(const char* str)
{
    long int h = PRIME;
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
    cdsc_bloomfilter_addhashfun(filter, crc32b);
    cdsc_bloomfilter_addhashfun(filter, MurmurOAAT_32);
    cdsc_bloomfilter_addhashfun(filter, KR_v2_hash);
    cdsc_bloomfilter_addhashfun(filter, x17);

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