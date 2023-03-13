#include <stdio.h>
#include<stdlib.h>
#include "heap.h"
#include <time.h>

/*
int main() {
    struct heap *h = init();
    printf("%i", is_empty(h));
    
    int values[] = {14, 88, 420, 69, 3, 12, 4};
    for (int i = 0; i < sizeof(values); i++) {
        insert(h, values[i]);
        printf("%i", h->list[i]);
    }
    printf("%i", len(h));
    while(!is_empty(h)) {
        printf("%i\n", find_min(h));
        delete_min(h);
    }

    nuke(h);
    return 0;
}
*/

int main() {
    int i;
    srand(time(NULL));
    struct heap *h = init();
    for(i = 0; i < 10; i++)
        insert(h, rand() % 1000);
    while(!is_empty(h)) {
        printf("%i\n", find_min(h));
        delete_min(h);
    }
    nuke(h);
    return 0;
}