#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#define MAX_SIZE 1000

struct heap *init() {
    struct heap *h = malloc(sizeof(struct heap));
    h->max_len =  MAX_SIZE;
    h->len = 0;
    h->list = (void*) malloc(sizeof(void*) *(h->max_len+1));

    return h;
}