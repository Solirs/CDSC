#include<stdbool.h>
#include<stdlib.h>
#include <stdio.h>
#include<stdarg.h>
#include "rope.h"

// for example purposes only
#define LEAF_CHARS 3

int main() {
	char a[] = "bob";
	char b[] = "lore";

	int size_a = sizeof(a)/sizeof(a[0]) - 1;
	int size_b = sizeof(b)/sizeof(b[0]) - 1;

	rope *first = cdsc_rope_init(NULL, a, 0, size_a, LEAF_CHARS);
	rope *second = cdsc_rope_init(NULL, b, 0, size_b, LEAF_CHARS);

	char *res = cdsc_rope_concat(first, second, size_a);
	printf("%s\n", res);


	// possibly solve this with variadic arguments in the future
	cdsc_rope_nuke(first);
	cdsc_rope_nuke(second);
    return 0;
}
