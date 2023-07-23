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

int main(){
    struct cdsc_bloomfilter *filter = cdsc_bloomfilter_create(320);
    cdsc_bloomfilter_addhashfun(filter, cdsc_bf_hash);
    cdsc_bloomfilter_addhashfun(filter, hash);

    char str[255];
    while (1){
        printf("Input a string: ");
        scanf("%s", &str);
        cdsc_bloomfilter_add(filter, str);

        printf("\n");
        printf("Lookup bloom filter: ");
        scanf("%s", &str);
        if (cdsc_bloomfilter_check(filter, str)){
            printf("The string is possibly in the set\n");
        }else{
            printf("The string is definitely not in the set\n");
        }
    }
    cdsc_bloomfilter_nuke(filter);
    return 0;
}