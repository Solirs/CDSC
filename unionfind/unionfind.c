#include<stdio.h>
#include<stdlib.h>
#include"unionfind.h"

int cdsc_union_find_find(union_find *set, int a);
void cdsc_union_find_uni(union_find *set, int a, int b);
bool cdsc_union_find_same(union_find *set, int a, int b);

union_find *cdsc_union_find_init(int a);
void nuke(union_find *set);
