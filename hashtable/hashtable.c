#include "hashtable.h"
#include <stdio.h>
#include <math.h>
#include <stdint.h>

#define CAPACITY 1000
#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL


// FNV-1A hashing algorithm, inspired by {https://create.stephan-brumme.com/fnv-hash/}
int hash(const void *key) {
    uint64_t hash = FNV_OFFSET;
    for (const char *p = key; *p; p++) {
        hash ^= (uint64_t)(unsigned char)(*p);
        hash *= FNV_PRIME;
    }
    return hash;
}
// See {https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function} for more detail

// Initialize new hash-table structure
struct hash_table *create(void) {
    struct hash_table *ht = malloc(sizeof(struct hash_table));
    if (ht == NULL)
       return NULL; 

    ht->len = 0;
    ht->cap = CAPACITY;
    //sets allocated memory to 0
    ht->entries = calloc(ht->cap, sizeof(struct item));

    if (ht->entries == NULL) {
        free(ht);
        return NULL;
    }
    return ht;
}

// Delete all fields of table and finally the table itself
void nuke(struct hash_table *table) {
    for(int i = 0; i < table->cap; i++) {
        free((void*)table->entries[i].key);
    }
    free(table->entries);
    free(table);
}