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
    mergeattail(node->parent->children, node->children);
    purge_node(node);
}

//WARNING: Only used internally by the implementation, do NOT call unless you know what you're doing!
void purge_node(struct tree_node* nod){
	nuke(nod->children);
	free(nod->children);
	free(nod);
}

void prune_node(struct tree_node* nod){
	int i;
	for (i = 0; i<nod->children->size; i++){
			prune_node(getindexfromhead(nod->children, i));
	}
	remove_node_if_contains(nod->parent->children, nod);
	purge_node(nod);
}

void graft(struct tree_node* nod, struct tree_node* parent){
	remove_node_if_contains(nod->parent->children, nod);
	inserttail(parent->children, nod);
	nod->parent = parent;
	
}
int get_depth(struct tree_node *nod){
	int i = 0;
	struct tree_node *cur = nod;
	while(cur->parent != NULL){
		i++;
		cur = cur->parent;
	}
	return i;
	
}
struct tree_node* naive_lca(struct tree_node* nod1, struct tree_node* nod2){
	
}
struct tree *make_tree(){
    struct tree* newtree = malloc(sizeof(struct tree));
    struct tree_node* newnode = malloc(sizeof(struct tree_node));
    newnode->parent = NULL;
    newnode->children = make_ll();
    newnode->data = NULL;

    newtree->root = newnode;
    newtree->number_of_nodes = 1;
	return newtree;
}  
