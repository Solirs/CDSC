#ifndef HEAP
#define HEAP

struct heap {
    int *list;
    int len;
    int max_len;
};

// Constructors and destructors
struct heap *cdsc_heap_init();
void cdsc_heap_nuke(struct heap*);

// Helper functions
int cdsc_heap_is_empty(struct heap*);
int cdsc_heap_len(struct heap*);

// Heap operations
int cdsc_heap_find_min(struct heap*);
void cdsc_heap_insert(struct heap*, int);
void cdsc_heap_delete_min(struct heap*);

#endif