#ifndef ROPE
#define ROPE

#include<stdlib.h>
#include<stdbool.h>

typedef struct rope {
	rope *left;
	rope *right;
	rope *par;
	char *string;
	int count;
} rope;

rope *cdsc_rope_init(rope *node, rope *par, char c[], int left, int right, int leaf_chars);
void cdsc_rope_nuke(rope *r);

#endif
