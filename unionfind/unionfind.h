#ifndef UNION_FIND
#define UNION_FIND

#include <stdlib.h>
#include<stdbool.h>

typedef struct union_find {
    int* par;
    int* rank;
} union_find;

int cdsc_union_find_find(union_find *set, int a);
void cdsc_union_find_uni(union_find *set, int a, int b);
bool cdsc_union_find_same(union_find *set, int a, int b);

union_find *cdsc_union_find_init(int a);
void nuke(union_find *set);

#endif
