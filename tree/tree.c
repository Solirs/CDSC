#include "tree.h"
#include <stdio.h>
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
    cdsc_linkedlist_merge(node->parent->children, node->children);
    purge_node(node);
}

//WARNING: Only used internally by the implementation, do NOT call unless you know what you're doing!
void purge_node(struct tree_node* nod){
	nuke(nod->children);
	free(nod->children);
	free(nod);
}

void prune_node(struct tree_node* nod){

	cdsc_tree_foreach_post_order_recursive(nod, purge_node, NULL);
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
// A decent O(n) algorithm to get the last common ancestor between two nodes.
struct tree_node* cdsc_tree_naive_lca(struct tree_node* nod1, struct tree_node* nod2){
	int dpt1 = get_depth(nod1);
	int dpt2 = get_depth(nod2);

	struct tree_node* lower;
	struct tree_node* higher;

	int diff = 0;
	int i = 0;

	if (dpt1 != dpt2){
		if (dpt1 > dpt2){
			diff = (dpt1-dpt2);
			lower = nod1;
			higher = nod2;
		}else{
			diff = (dpt2-dpt1);
			lower = nod2;
			higher = nod1;
		}
		for (i = 0;i<diff; i++){
			lower = lower->parent;
		}

	}else{
		lower = nod1;
		higher = nod2;
	}
	
	// From this point higher and lower are at the same depth.
	while (1){
		if (higher->parent == lower->parent){ // Last common ancestor found
			return higher->parent;
			
		}else if (higher->parent == NULL || lower->parent == NULL){ // One of the cursors reached the root, it is the LCA.
			return higher;
		}else{ // Keep going
			higher = higher->parent;
			lower = lower->parent;
		}
	}
}
struct tree *make_tree(){
    struct tree* newtree = malloc(sizeof(struct tree));
    struct tree_node* newnode = malloc(sizeof(struct tree_node));
    newnode->parent = NULL;
    newnode->children = make_ll();
    newnode->data = NULL;

    newtree->root = newnode;
	return newtree;
}  


void _stackpushnode(struct node *nod, struct cdsc_stack* stack){
	
	if (nod->data != NULL){
		cdsc_stack_push(stack,(struct tree_node*)nod->data);	
	}
}
// Iterative pre order traversal using a stack
// Implements https://en.wikipedia.org/wiki/Tree_traversal#Pre-order_implementation
void cdsc_tree_foreach_pre_order(struct tree_node* nod, void (*action)(), void* param){
	struct cdsc_stack* stack = cdsc_stack_make_stack();
	cdsc_stack_push(stack, nod);
	while (stack->size != 0){
		struct tree_node* nn = (struct tree_node*)cdsc_stack_pop(stack);
		action(nod, param);
		if (nn->children->size != 0){
			cdsc_linkedlist_foreach(nn->children, _stackpushnode, stack);

		}
	}
	
}

void stackadd(struct node* nd, struct cdsc_stack* stack){
	cdsc_stack_push(stack, nd->data);
	
}
void cdsc_tree_foreach_in_order(struct tree_node* nod, void (*action)(), void* param){
	// TODO
}
//TODO: Comment
void cdsc_tree_foreach_post_order(struct tree_node* nod, void (*action)(), void* param){
	struct cdsc_stack* stack = cdsc_stack_make_stack();

	struct tree_node* lastnode = NULL;
	struct tree_node* nodde = NULL;
	cdsc_stack_push(stack, nod);
	while (stack->size != 0){
		nodde = (struct tree_node*)cdsc_stack_peek(stack);
		if (nodde->children->size == 0 || lastnode != NULL && find(nodde->children, lastnode) != NULL){
			action(nodde, param);
			cdsc_stack_pop(stack);
			lastnode = nodde;
		}else{
			struct cdsc_stack* tempstack = cdsc_stack_make_stack();
			cdsc_linkedlist_foreach(nodde->children, stackadd, tempstack);
			while (tempstack->size != 0){
				cdsc_stack_push(stack, cdsc_stack_pop(tempstack));
			}
			
		}

	}
	
}


//TODO: Wrap those functions so the root node can also be affected
void cdsc_tree_foreach_post_order_recursive(struct tree_node* nod, void (*action)(), void* param){
	int i;
	for (i = 0; i<nod->children->size; i++){
			cdsc_tree_foreach_post_order_recursive(getindexfromhead(nod->children, i), action, param);
			action(getindexfromhead(nod->children, i), param);

	}
}
void cdsc_tree_foreach_pre_order_recursive(struct tree_node* nod, void (*action)(), void* param){
	int i;
	for (i = 0; i<nod->children->size; i++){
			action(getindexfromhead(nod->children, i), param);
			cdsc_tree_foreach_pre_order_recursive(getindexfromhead(nod->children, i), action, param);
	}
}
// Zero a tree
void cdsc_tree_nuke(struct tree* tree){
	prune_node(tree->root);
	purge_node(tree->root);
	tree->root = NULL;
}

// Increment passed integer, used in cdsc_tree_count
void _intplusplus(struct tree_node *nod, int* in){
	*in = *in + 1;

}

int cdsc_tree_count(struct tree* tree){
	int num = 1; // Start at 1 because of root node
	cdsc_tree_foreach_pre_order_recursive(tree->root, _intplusplus, &num); // Increment for each node in the tree
	return num;
}
