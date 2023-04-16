#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include <string.h>
#include <assert.h>
#define MAX_SIZE 1000

// Initialize new structure of type heap and allocate memory for it
struct heap *cdsc_heap_init() {
    struct heap *h = (struct heap *) malloc(sizeof(struct heap));
    h->max_len = MAX_SIZE;
    h->len = 0;
    h->list = (int *) malloc(sizeof(int *) * (h->max_len + 1));

    return h;
}

// Helper function for swapping two neighboring elements on the heap
void cdsc_heap_swap(struct heap *h, int a, int b) {
    assert(h && a >= 1 && a <= h->len && b >= 1 && b <= h->len);
    int tmp = h->list[a];
    h->list[a] = h->list[b];
    h->list[b] = tmp;
}

// Double the size of the initial array if current lenght hits the max
void cdsc_heap_double_cap(struct heap *h) {
    int updated_max_len = h->max_len * 2;
    int *updated_list =
	(int *) malloc(sizeof(int) * (updated_max_len + 1));
    for (int i = 0; i < h->len; i++) {
	updated_list[i] = h->list[i];
    }

    // Dump the old array and replace it with new one
    free(h->list);
    h->list = updated_list;
    h->max_len = updated_max_len;
}

// Switch values of two neighbours as long as they dont fit
void cdsc_heap_bubble_up(struct heap *h, int x) {
    while (x > 1 && h->list[x] < h->list[x / 2]) {
	cdsc_heap_swap(h, x / 2, x);
	x /= 2;
    }
}

// Switch two neighboiring elements as long as they don't fit in the opposite direction
void cdsc_heap_bubble_down(struct heap *h, int x) {
    while (x * 2 <= h->len) {
	int j = x * 2;
	if (j < h->len && h->list[j + 1] < h->list[j]) {
	    j++;
	}
	if (h->list[x] <= h->list[j]) {
	    break;
	}

	cdsc_heap_swap(h, x, j);
	x = j;
    }
}

// Insert new element and bubble it upwards if needed
void cdsc_heap_insert(struct heap *h, int value) {
    assert(h);
    // Inserting one element at a time
    if (h->len == h->max_len)
	cdsc_heap_double_cap(h);

    h->list[++h->len] = value;
    cdsc_heap_bubble_up(h, h->len);
}

// Return the root element
int cdsc_heap_find_min(struct heap *h) {
    if (cdsc_heap_is_empty(h))
	abort();
    return h->list[1];
}

// Delete the smallest element (root) and replace it with next one
void cdsc_heap_delete_min(struct heap *h) {
    if (cdsc_heap_is_empty(h))
	abort();

    cdsc_heap_swap(h, 1, h->len);
    h->len--;
    cdsc_heap_bubble_down(h, 1);
}

// See if heap contains any elements
int cdsc_heap_is_empty(struct heap *h) {
    if (h->len == 0)
	return 1;
    return 0;
}

// Number of elements in the heap array
int cdsc_heap_len(struct heap *h) {
    return h->len;
}

// Destroy the passed structure
void cdsc_heap_nuke(struct heap *h) {
    free(h->list);
    free(h);
}
