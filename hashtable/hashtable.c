#include "hashtable.h"
#include <stdio.h>
#include <math.h>
#include <string.h>

#define CAPACITY 1000
#define OFFSET 14695981039346656037UL
#define PRIME 1099511628211UL


// FNV-1A hashing algorithm, inspired by {https://create.stephan-brumme.com/fnv-hash/}
unsigned long hash_fn(const char *key) {
    unsigned long hash = OFFSET;
    for (const char *p = key; *p; p++) {
        hash ^= (unsigned long)(unsigned char)(*p);
        hash *= PRIME;
    }
    return hash;
}
// See {https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function} for more detail

// Initialize new hash-table structure
struct hash_table *init(void) {
    struct hash_table *table = malloc(sizeof(struct hash_table));
    if (table == NULL)
        return NULL;

    table->len = 0;
    table->cap = CAPACITY;
    
    // Space for buckets is NULL-ed
    table->entries = calloc(table->cap, sizeof(struct item));
    // Destroy table if no entries are present
    if (table->entries == NULL) {
        free(table);
        return NULL;
    }
    return table;
}

// See if element is in boundaries, if so return the value
void *get(struct hash_table *table, const char* key) {
    unsigned long hash = hash_fn(key);
    size_t index = (size_t)(hash & (unsigned long)(table->cap - 1));

    while (table->entries[index].key != NULL) {
        if (!strcmp(table->entries[index].key, key))
            return table->entries[index].value;
        index++;

        if (index >= table->cap)
            index = 0;
    }
    return NULL;
}

// Utility for set function, if key isn't present, create it and extend lenght
const char *set_table_entry(struct item *entries, size_t cap, const char* key, void* value) {
    size_t *len = NULL;
    unsigned long hash = hash_fn(key);
    size_t index = (size_t)(hash & (unsigned long)(cap - 1));

    while (entries[index].key != NULL) {
        if (strcmp(key, entries[index].key) == 0) {
            entries[index].value = value;
            return entries[index].key;
        }
        index++;
        if (index >= cap)
            index = 0;
    }
    if (len != NULL) {
        key = strdup(key);
        if (key == NULL)
            return NULL;

        (*len)++;
    }
    entries[index].key = (char*)key;
    entries[index].value = value;
    return key;
}

// Allocate memory for new entries in the hashtable
bool expand_table(struct hash_table *table) {
    size_t updated_cap = table->cap * 2;
    if (updated_cap < table->cap)
        return false;

    struct item *updated_entries = calloc(updated_cap, sizeof(struct item));
    if (updated_entries == NULL)
        return false;
        // out of memory

    for (size_t i = 0; i < table->cap; i++) {
        struct item entry = table->entries[i];
        if (entry.key != NULL)
            set_table_entry(updated_entries, updated_cap, entry.key, entry.value);
    }

    free(table->entries);
    table->entries = updated_entries;
    table->cap = updated_cap;
    return true;
}

// Insert new element into the hash table if it fits, return the key
const char *set(struct hash_table *table, const char* key, void* value) {
    if (value == NULL)
        return NULL;
    if (table->len >= table->cap / 2)
        if (expand_table(table) == false)
            return NULL;

    return set_table_entry(table->entries, table->cap, key, value);
}

// Hash table destruction
void nuke(struct hash_table *table) {
    for (size_t i = 0; i < table->cap; i++)
        free((void*)table->entries[i].key);
    free(table->entries);
    free(table);
}