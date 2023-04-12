#ifndef TREE_
#define TREE_

#include<stdlib.h>
#include"../linkedlist/linkedlist.h"
#include"../stack/stack.h"


struct cdsc_tree_node{
    struct cdsc_tree_node* parent;
    void* data;
    struct LinkedList* children;
};

struct cdsc_tree{
    struct cdsc_tree_node* root;
};

struct cdsc_tree_node* cdsc_tree_add_child(struct cdsc_tree_node* node, void* data);
struct cdsc_tree_node* cdsc_tree_remove_node(struct cdsc_tree_node* node);
struct cdsc_tree* cdsc_tree_make_tree();
struct cdsc_tree_node* cdsc_tree_get_root_node(struct cdsc_tree_node* node);
void cdsc_tree_prune_node(struct cdsc_tree_node* node);
void cdsc_tree_purge_node(struct cdsc_tree_node* node);
void cdsc_tree_graft(struct cdsc_tree_node* nod, struct cdsc_tree_node* parent);
struct cdsc_tree_node* cdsc_tree_naive_lca(struct cdsc_tree_node* nod1, struct cdsc_tree_node* nod2);
int cdsc_tree_get_depth(struct cdsc_tree_node *nod);
int cdsc_tree_count(struct cdsc_tree* tree);
void cdsc_tree_foreach_pre_order(struct cdsc_tree_node* nod, void(*action)(), void* param);
void cdsc_tree_foreach_post_order(struct cdsc_tree_node* nod, void (*action)(), void* param);
void cdsc_tree_nuke(struct cdsc_tree* tree);
#endif
