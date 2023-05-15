#include "hashtable.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// A single entry of the hash table structure
typedef struct item {
    char *key;
    size_t key_len;
    void *val;
    struct item *next;
} item;

// Hash table with an arbitrary hashing function
typedef struct _hash_table {
    size_t len;
    hash_fn *hash;
    item **entries;
} hash_table;

// Return an index fitting into the entries field size
size_t cdsc_ht_index(hash_table *table, const char *key) {
    return (table->hash(key) % table->len);
}

// Initialize a new hash table data structure with a custom hashing function
hash_table *cdsc_ht_init(size_t len, hash_fn *hf) {
    hash_table *table = malloc(sizeof(*table));
    table->len = len;
    table->hash = hf;
    table->entries = calloc(sizeof(item *), table->len);
    return table;
}

// Insert a new key:value pair element into the table
int cdsc_ht_insert(hash_table *table, const char *key, void *val) {
    if (key == NULL || val == NULL)
	return -1;

    size_t index = cdsc_ht_index(table, key);
    if (cdsc_ht_lookup(table, key) != NULL)
	return false;

    item *entry = malloc(sizeof(*entry));
    entry->val = val;
    entry->key = malloc(strlen(key) + 1);
    strcpy(entry->key, key);

    entry->next = table->entries[index];
    table->entries[index] = entry;
    return 1;
}

// Return value at a given key in the struct if it exists
void *cdsc_ht_lookup(hash_table *table, const char *key) {
    if (key == NULL || table == NULL)
	return false;
    size_t index = cdsc_ht_index(table, key);
    item *tmp = table->entries[index];
    while (tmp != NULL && strcmp(tmp->key, key) != 0)
	tmp = tmp->next;

    if (tmp == NULL)
	return tmp;
    return tmp->val;
}

// Delete an element from the existing entries and shift the table
void *cdsc_ht_delete(hash_table *table, const char *key) {
    if (key == NULL || table == NULL)
	return false;
    size_t index = cdsc_ht_index(table, key);

    item *tmp = table->entries[index];
    item *parent = NULL;
    while (tmp != NULL && strcmp(tmp->key, key) != 0) {
	parent = tmp;
	tmp = tmp->next;
    }

    if (tmp == NULL)
	return tmp;
    if (parent == NULL)
	table->entries[index] = tmp->next;
    else
	parent->next = tmp->next;
    void *result = tmp->val;
    free(tmp);
    return result;
}

// Free all the memory allocated for the data structure
int cdsc_ht_nuke(hash_table *table) {
    free(table->entries);
    free(table);
    return 1;
}
