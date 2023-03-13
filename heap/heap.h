#ifndef HEAP
#define HEAP
#include<stdbool.h>

struct heap {
    int *list;
    int len;
    int max_len;
};

// Constructors and destructors
struct heap *init();
void nuke(struct heap*);

// Helper functions
bool is_empty(struct heap*);
int len(struct heap*);

// Heap operations
int find_min(struct heap*);
void insert(struct heap*, int);
void delete_min(struct heap*);

#endif