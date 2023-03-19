#ifndef HASH_TABLE
#define HASH_TABLE
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>

struct cdsc_ht_item {
    const char *key;
    void *value;
};

struct cdsc_ht_hash_table {
    struct cdsc_ht_item *entries;
    size_t cap;
    size_t len;
};

unsigned long cdsc_ht_hash(const char *key);
struct cdsc_ht_hash_table *cdsc_ht_init(void);
void cdsc_ht_nuke(struct cdsc_ht_hash_table *table);

void *cdsc_ht_get(struct cdsc_ht_hash_table *table, const char *key);

const char *cdsc_ht_set_table_entry(struct cdsc_ht_item *entries, size_t cap, const char* key, void* value);
bool cdsc_ht_expand_table(struct cdsc_ht_hash_table *table);
const char *cdsc_ht_set(struct cdsc_ht_hash_table *table, const char *key, void *value);
#endif