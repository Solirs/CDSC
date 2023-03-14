#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main() {
    int values[] = {476, 1968, 1066, 20023, 1618, 1789, 1993, 1871};
    struct heap *h = init();

    for(int i = 0; i < sizeof(values)/sizeof(int); i++)
        insert(h, values[i]);

    while(!is_empty(h)) {
        printf("%i\n", find_min(h));
        delete_min(h);
    }

    nuke(h);
    return 0;
}