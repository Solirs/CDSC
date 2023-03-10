#ifndef HASH_TABLE
#define HASH_TABLE
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct item {
    int key;
    void *value;
};

struct hash_table {
    struct item *entries;
    size_t cap;
    size_t len;
};

struct hash_table_iter {
    void *value;
    int key;
    struct hash_table *table;
    size_t index;
};

int hash(const void *key);
struct hash_table *init(void);
void insert(struct hash_table, void *key, void *value);
void search(struct hash_table, void *key);
void delete_key(struct hash_table, void *key);

void nuke(struct hash_table *table);
void *get(struct hash_table *table, const void *key);
void *set(struct hash_table *table, int key, void *value);

size_t len(struct hash_table);
bool next(struct hash_table_iter *iter);
struct hash_table_iter iterator(struct hash_table);
#endif