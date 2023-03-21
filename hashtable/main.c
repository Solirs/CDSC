#include "hashtable.h"
#include <stdio.h>

// Constants for the hash_fn
#define CAPACITY 1000
#define OFFSET 14695981039346656037UL
#define PRIME 1099511628211UL

// An example hashing function (FNV)
unsigned long cdsc_ht_hash(const char *key) {
    unsigned long hash = OFFSET;
    for (const char *p = key; *p; p++) {
        hash ^= (unsigned long)(*p);
        hash *= PRIME;
    }
    return hash;
}

// Driver code
int main() {
    hash_table *table = cdsc_ht_init(CAPACITY, cdsc_ht_hash);

    bool inserted = cdsc_ht_insert(table, "Amo", "gus");
    printf("%i\n", inserted);

    printf("%s\n", (char*) cdsc_ht_lookup(table, "Amo"));

    inserted = cdsc_ht_insert(table, "Amo", "gus");
    printf("%i\n", inserted);

    cdsc_ht_insert(table, "Sug", "oma");
    cdsc_ht_delete(table, "Sug");
    inserted = cdsc_ht_insert(table, "Sug", "oma");
    printf("%i\n", inserted);

    cdsc_ht_nuke(table);
}