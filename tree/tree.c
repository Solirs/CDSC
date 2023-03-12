#include "tree.h"

struct tree_node* add_child(struct tree_node* node, void* data){
    struct tree_node* newnode = malloc(sizeof(struct tree_node));
    newnode->parent = node;
    newnode->data = data;
    newnode->children = make_ll();

    inserttail(node->children, newnode);

    return newnode;
}

struct tree_node* get_root_node(struct tree_node* node){
    while (true){
        if (node->parent == NULL){
            return node;
        }else{
            node = node->parent;
        }
    }
}
struct tree_node* remove_node(struct tree_node* node){
    int i;

    for (i = 0; i<node->children->size; i++){
        struct tree_node* child = (struct tree_node*)getindexfromhead(node->children, i);
        child->parent = node->parent;
    }
    node->parent->children = node->children;

    free(node);
}
void prune_node(struct tree_node* node){
    
}

struct tree *make_tree(){
    struct tree* newtree = malloc(sizeof(struct tree));
    struct tree_node* newnode = malloc(sizeof(struct tree_node));
    newnode->parent = NULL;
    newnode->children = make_ll();
    newnode->data = NULL;

    newtree->root = newnode;
    newtree->number_of_nodes = 1;
}  