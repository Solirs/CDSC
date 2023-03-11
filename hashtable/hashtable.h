#ifndef HASH_TABLE
#define HASH_TABLE
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>

struct item {
    const char *key;
    void *value;
};

struct hash_table {
    struct item *entries;
    size_t cap;
    size_t len;
};

unsigned long hash_fn(const char *key);
struct hash_table *init(void);
void nuke(struct hash_table *table);

void *get(struct hash_table *table, const char *key);

const char *set_table_entry(struct item *entries, size_t cap, const char* key, void* value);
bool expand_table(struct hash_table *table);
const char *set(struct hash_table *table, const char *key, void *value);
#endif