#include<stdio.h>
#include <string.h>
#include "unionfind.h"

int main() {
	union_find *set = cdsc_union_find_init(42);

	nuke(set);
	return 0;
}
