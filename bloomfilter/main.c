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
    return hash % 320;
}

int main(){
    struct cdsc_bloomfilter *filter = cdsc_bloomfilter_create(320);
    filter->hashfuncs[0] = cdsc_bf_hash;
    cdsc_bloomfilter_add(filter, "HelloWorld");
    printf("%d\n", cdsc_bloomfilter_check(filter, "HelloWorld"));

    cdsc_bloomfilter_nuke(filter);
    return 0;
}