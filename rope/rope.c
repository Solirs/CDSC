#include<stdio.h>
#include<stdlib.h>
#include"rope.h"

rope *cdsc_rope_init(rope *node, rope *par, char c[], int left, int right, int leaf_chars) {
    rope *r = (rope *)malloc(sizeof(rope));
    r->left = NULL;
    r->right = NULL;
    r->par = par;
    
    if ((right-left) > leaf_chars) {
        r->string = NULL;
        r->count = (right-left)/2;
        node = r;
        int m = (left + right)/2;
        cdsc_rope_init(node->left, node, c, left, m, leaf_chars);
        cdsc_rope_init(node->right, node, c, m+1, right, leaf_chars);
    }
    else {
        node = r;
        r->count = (right-left);
        int j = 0;
        r->string = (char*)malloc(sizeof(leaf_chars));
        for (int i = left; i <= right; i++)
            r->string[j++] = c[i];
    }

    return r;
}

void cdsc_rope_nuke(rope *r) {
    free(r->left);
    free(r->right);
    free(r->par);
    free(r->string);
    free(r->count);

    free(r);
}
