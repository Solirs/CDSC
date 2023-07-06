#include<stdbool.h>
#include<stdlib.h>
#include <stdio.h>
#include "unionfind.h"

int main() {
    union_find *set = cdsc_union_find_init(5);

    cdsc_union_find_uni(set, 1, 2);
    cdsc_union_find_uni(set, 3, 4);
    cdsc_union_find_uni(set, 2, 4);

    bool cmp1 = cdsc_union_find_same(set, 1, 4);  // false
    bool cmp2 = cdsc_union_find_same(set, 2, 3);  // true

    printf("1 and 4 in the same set: %s\n", cmp1 ? "Yes" : "No");
    printf("2 and 3 in the same set: %s\n", cmp2 ? "Yes" : "No");

    nuke(set);

    return 0;
}

