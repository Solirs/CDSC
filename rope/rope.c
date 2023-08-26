#include<stdio.h>
#include<stdlib.h>
#include"rope.h"

// initialize a rope from given string of chars
rope* cdsc_rope_init(rope *node, char c[], int left, int right, int leaf_chars) {
    rope *r = (rope*) malloc(sizeof(rope));
    r->left = NULL;
    r->right = NULL;
    r->par = node;

    if ((right-left) > leaf_chars) {
        r->string = NULL;
        r->count = (right - left) / 2;
        int m = (left + right) / 2;
        r->left = cdsc_rope_init(r, c, left, m, leaf_chars);
        r->right = cdsc_rope_init(r, c, m+1, right, leaf_chars);
    }
	else {
        r->count = (right - left);
        int j = 0;
        r->string = (char*) malloc(sizeof(char)*leaf_chars);
        for (int i = left; i <= right; i++)
            r->string[j++] = c[i];
    }
    return r;
}

// free all members of the rope and the rope itself
void cdsc_rope_nuke(rope *r) {
    if (r == NULL) {
        return;
    }

    cdsc_rope_nuke(r->left);
    cdsc_rope_nuke(r->right);
    free(r->string);
    free(r);
}

// helper function to appends string from each leaf to the string buffer
void append(rope *r, char *buff, int *ind) {
    if (r == NULL) {
        return;
    }
    if (r->left == NULL && r->right == NULL) {
        for (int i = 0; i < r->count; i++) {
            buff[(*ind)++] = r->string[i];
        }
    }
    append(r->left, buff, ind);
    append(r->right, buff, ind);
}

// concatenate two strings stored in ropes
char *cdsc_rope_concat(rope *first, rope *second, int n) {
    rope *r = (rope*) malloc(sizeof(rope));
    r->par = NULL;
    r->left = first;
    r->right = second;
    first->par = r;
    second->par = r;
    r->count = n;
    r->string = NULL;

    int buff_size = first->count + second->count + 1;
    char *buff = (char *) malloc(sizeof(char) * buff_size);
    int ind = 0;
    append(r, buff, &ind);
    buff[buff_size - 1] = '\0'; // end the buffered string

    return buff;
}
