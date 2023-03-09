#include "hashtable.h"
#include <stdio.h>

int hash(struct hash_table ht, void *value) { // returns key for value
    return ((int)value % ht.len);
}