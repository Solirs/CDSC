#ifndef HEAP
#define HEAP

struct heap {
    void *list;
    int len;
    int max_len;
};

// Constructors and destructors
struct heap *init();
void nuke(struct heap);

// Helper functions
struct heap heapify(void*, int);
int len(struct heap);
bool is_empty(struct heap);

// Heap operations
int find_min(struct heap);
void insert_min(struct heap, void*);
void delete_min(struct heap);

#endif