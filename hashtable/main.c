#include "hashtable.h"
#include <stdio.h>

int main() {
    struct cdsc_ht_hash_table *table = cdsc_ht_init();
    cdsc_ht_nuke(table);
    return 0;
}