#ifndef ROPE
#define ROPE

#include<stdlib.h>
#include<stdbool.h>

typedef struct rope {
	struct rope *left;
	struct rope *right;
	struct rope *par;
	char *string;
	int count;
} rope;

rope *cdsc_rope_init(rope *node, char c[], int left, int right, int leaf_chars);
void cdsc_rope_nuke(rope *r);

char *cdsc_rope_concat(rope *first, rope *second, int n);
#endif
