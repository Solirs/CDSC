#ifndef HASH_TABLE
#define HASH_TABLE

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<stdint.h>

typedef unsigned long hash_fn (const char*);
typedef struct _hash_table hash_table;

hash_table *cdsc_ht_init(size_t len, hash_fn *hf);
int cdsc_ht_nuke(hash_table *table);

int cdsc_ht_insert(hash_table *ht, const char *key, void *val);
void *cdsc_ht_lookup(hash_table *ht, const char *key);
void *cdsc_ht_delete(hash_table *ht, const char *key);
#endif
