#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include <string.h>
#include <assert.h>
#define MAX_SIZE 1000

// Initialize new structure of type heap and allocate memory for it
struct heap *init() {
    struct heap *h = (struct heap*)malloc(sizeof(struct heap));
    h->max_len =  MAX_SIZE;
    h->len = 0;
    h->list = (int*)malloc(sizeof(int*) *(h->max_len+1));

    return h;
}

// Helper function for swapping two neighboring elements on the heap
static void swap(struct heap *h, int a, int b) {
    assert(h && a >= 1 && a <= h->len && b>= 1 && b <= h->len);
    int tmp = h->list[a];
    h->list[a] = h->list[b];
    h->list[b] = tmp;
}

// Double the size of the initial array if current lenght hits the max
static void double_cap(struct heap *h) {
    int updated_max_len = h->max_len * 2;
    int *updated_list = (int*) malloc(sizeof(int)*(updated_max_len+1));
    for (int i = 0; i < h->len; i++) {
        updated_list[i] = h->list[i];
    }

    // Dump the old array and replace it with new one
    free(h->list);
    h->list = updated_list;
    h->max_len = updated_max_len;
}

// Switch values of two neighbours as long as they dont fit
static void bubble_up(struct heap *h, int x) {
    while(x > 1 && h->list[x] < h->list[x/2]) {
        swap(h, x/2, x);
        x /= 2;
    }
}

static void bubble_down(struct heap *h, int x) {
    while (x * 2 <= h->len) {
        int j = x *2;
        if (j < h->len && h->list[j+1] < h->list[j]) {j++;}
        if (h->list[x] <= h->list[j]) {break;}

        swap(h, x, j);
        x = j;
    }
}

void insert(struct heap *h, int value) {
    assert(h);
    // We only insert one element at a time
    if (h->len == h-> max_len)
        double_cap(h);

    // Insert the element and bubble up if needed
    h->list[++h->len] = value;
    bubble_up(h, h->len);
}

// Return the root element
int find_min(struct heap *h) {
    if (is_empty(h))
        abort();
    return h->list[1];
}

// Delete the smallest element (root)
void delete_min(struct heap *h) {
    if (is_empty(h))
        abort();
    
    swap(h, 1, h->len);
    h->len--;
    bubble_down(h, 1);
}

int is_empty(struct heap *h) {
    if (h->len == 0) 
        return 1;
    return 0;
}

int len(struct heap *h) {
    return h->len;
}

// Destroy the passed structure
void nuke(struct heap *h) {
    free(h->list);
    free(h);
}