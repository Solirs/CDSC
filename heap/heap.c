#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#define MAX_SIZE 1000

// Initialize new structure of type heap and allocate memory for it
struct heap *init() {
    struct heap *h = malloc(sizeof(struct heap));
    h->max_len =  MAX_SIZE;
    h->len = 0;
    h->list = (int*)malloc(sizeof(int*) *(h->max_len+1));

    return h;
}

// Helper function for swapping two neighboring elements on the heap
void swap(struct heap *h, int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// Double the size of the initial array if current lenght hits the max
void double_cap(struct heap *h) {
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
void bubble_up(struct heap *h) {
    int size = h->len;
    while(size > 1 && h->list[size] && size <= h->len)
        swap(h, size/2, size);
}

void bubble_down(struct heap *h, int x) {
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
    h->list[h->len++] = value;
    bubble_up(h);
}

// Return the root element
int find_min(struct heap *h) {
    return h->list[0];
}

// Delete the smallest element (root)
void delete_min(struct heap *h) {
    if (is_empty(h))
        abort();
    
    swap(h, 1, h->len);
    h->len--;
    bubble_down(h, 1);
}

bool is_empty(struct heap *h) {
    if (h->len == 0) 
        return true;
    return false;
}

int len(struct heap *h) {
    return h->len;
}

// Destroy the passed structure
void nuke(struct heap *h) {
    free(h);
}