#ifndef BINARY_TREE_
#define BINARY_TREE_

#include<stdlib.h>
#include <stdbool.h>

struct cdsc_btree_node{
    struct cdsc_btree_node* parent;
    void* data;
    struct cdsc_btree_node* lchild;
    struct cdsc_btree_node* rchild;
};

struct cdsc_btree{
    struct cdsc_btree_node* root;
};

struct cdsc_btree_node* cdsc_btree_insert_lchild(struct cdsc_btree_node* node, void* data);
struct cdsc_btree_node* cdsc_btree_insert_rchild(struct cdsc_btree_node* node, void* data);

struct cdsc_btree* cdsc_btree_make_btree();

struct cdsc_btree_node* cdsc_btree_get_root_node(struct cdsc_btree_node* node);

void cdsc_btree_remove_node(struct cdsc_btree_node* node);
void cdsc_btree_prune_node(struct cdsc_btree_node* node);
void cdsc_btree_purge_node(struct cdsc_btree_node* node);
struct cdsc_btree_node* cdsc_btree_naive_lca(struct cdsc_btree_node* nod1, struct cdsc_btree_node* nod2);

int cdsc_btree_get_depth(struct cdsc_btree_node *nod);
int cdsc_btree_count(struct cdsc_btree* tree);

void cdsc_btree_foreach_pre_order(struct cdsc_btree_node* nod, void(*action)(), void* param);
void cdsc_btree_foreach_post_order(struct cdsc_btree_node* nod, void (*action)(), void* param);
void _cdsc_btree_foreach_pre_order(struct cdsc_btree_node* nod, void(*action)(), void* param);
void _cdsc_btree_foreach_post_order(struct cdsc_btree_node* nod, void (*action)(), void* param);

void cdsc_btree_graft_rchild(struct cdsc_btree_node* nod, struct cdsc_btree_node* parent);
void cdsc_btree_graft_lchild(struct cdsc_btree_node* nod, struct cdsc_btree_node* parent);

void cdsc_btree_orphan(struct cdsc_btree_node* nod);
void cdsc_btree_nuke(struct cdsc_btree_node* nod);

int cdsc_btree_getchildnum(struct cdsc_btree_node* node);
// Is the single child of a tree node its left child or right child??, O(1)
struct cdsc_btree_node* cdsc_btree_get_child_direction(struct cdsc_btree_node* node);
#endif
