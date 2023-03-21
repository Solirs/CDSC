#include "hashtable.h"
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct item {
    char *key;
    void *val;
    struct item *next;
    size_t key_len;
}item;

typedef struct _hash_table {
    hash_fn *hash;
    item **entries;
    size_t len;
} hash_table;

// Initialize new hash-table structure
hash_table *cdsc_ht_init(size_t len, hash_fn *hf) {
    hash_table *table = malloc(sizeof(*table));
    table->len = len;
    table->hash = hf;
    table->entries = calloc(sizeof(item*), table->len);

    return table;
}

size_t cdsc_ht_index(hash_table *table, const char* key) {
    return(table->hash(key) % table->len);
}

bool cdsc_ht_insert(hash_table *table, const char* key, void *val) {
    if (key == NULL || val == NULL)
        return false;

    size_t i = cdsc_ht_index(table, key);
    if (cdsc_ht_lookup(table, key) != NULL)
        return false;
    
    item* entry = malloc(sizeof(*entry));
    entry->val = val;
    entry->key = malloc(strlen(key)+1); 
    strcpy(entry->key, key);

    entry->next = table->entries[i];
    table->entries[i] = entry;
    return true;
}

void *cdsc_ht_lookup(hash_table *table, const char *key) {
    if (key == NULL || table == NULL)
        return false;

    size_t i = cdsc_ht_index(table, key);
    item *tmp = table->entries[i];
    while (tmp != NULL && strcmp(tmp->key, key) != 0)
        tmp = tmp->next;

    if(tmp == NULL)
        return tmp;
    return tmp->val;
}

void *cdsc_ht_delete(hash_table *table, const char *key) {
    if(key == NULL || table == NULL)
        return false;
    
    size_t i = cdsc_ht_index(table, key);
    item *tmp = table->entries[i];
    item *parent = NULL;

    while(tmp != NULL && strcmp(tmp->key, key) != 0) {
        parent = tmp;
        tmp = tmp->next;
    }

    if(tmp == NULL)
        return tmp;
    if(parent == NULL)
        table->entries[i] = tmp->next;
    else
        parent->next = tmp->next;
    
    void *res = tmp->val;
    free(tmp);
    return res;
}

// Hash table destruction
void cdsc_ht_nuke(hash_table *table) {
    free(table->entries);
    free(table);
}