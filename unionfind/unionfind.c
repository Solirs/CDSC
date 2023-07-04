#include<stdio.h>
#include<stdlib.h>
#include"unionfind.h"

// find operation on a disjoint set
int cdsc_union_find_find(union_find *set, int a) {
	return a == set->par[a] ? a : cdsc_union_find_find(set, a);
}

void cdsc_union_find_uni(union_find *set, int a, int b) {
	a = cdsc_union_find_find(set, a);
	b = cdsc_union_find_find(set, b);

	if (set->rank[b] > set->rank[a]) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	set->par[b] = a;
	set->rank[a] += set->rank[b];
}

// check whether two elements belong to the same set
bool cdsc_union_find_same(union_find *set, int a, int b) {
	return cdsc_union_find_find(set, a) == cdsc_union_find_find(set, b);
}

// initialize new set with parent list and element ranking for merging sets
union_find *cdsc_union_find_init(int a) {
	union_find *set = (union_find*)malloc(sizeof(union_find));

	set->par = (int*)malloc((a+1) * sizeof(int));
	set->rank = (int*)malloc((a+1) * sizeof(int));

	for(int i = 0; i<= a; i++) {
		set->par[i] = i;
		set->rank[i] = 0;
	}

	return set;
}

// destroy the entire set after freeing both lists
void nuke(union_find *set) {
	if(set != NULL) {
		free(set->par);
		free(set->rank);
		free(set);
	}
}
