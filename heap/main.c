#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main() {
    int values[] = { 476, 1968, 1066, 20023, 1618, 1789, 1993, 1871 };
    struct heap *h = cdsc_heap_init();

    for (int i = 0; i < sizeof(values) / sizeof(int); i++)
	cdsc_heap_insert(h, values[i]);

    while (!cdsc_heap_is_empty(h)) {
	printf("%i\n", cdsc_heap_find_min(h));
	cdsc_heap_delete_min(h);
    }

    cdsc_heap_nuke(h);
    return 0;
}
