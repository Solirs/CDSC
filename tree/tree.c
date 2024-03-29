#include "tree.h"
#include <stdio.h>

// Append child to a tree node.
struct cdsc_tree_node *cdsc_tree_add_child(struct cdsc_tree_node *node,
					   void *data) {
    struct cdsc_tree_node *newnode = malloc(sizeof(struct cdsc_tree_node));
    if (newnode == NULL) {
	return NULL;
    }
    newnode->parent = node;
    newnode->data = data;
    newnode->children = cdsc_doublylinkedlist_make_dll();

    cdsc_doublylinkedlist_inserttail(node->children, newnode);

    return newnode;
}

// Get the root node of a tree using any node inside it.
struct cdsc_tree_node *cdsc_tree_get_root_node(struct cdsc_tree_node *node) {
    while (true) {
	if (node->parent == NULL) {
	    return node;
	} else {
	    node = node->parent;
	}
    }
}


void _setparent(struct cdsc_tree_node* node, struct cdsc_tree_node* parent){
    node->parent = parent;
}
// Remove a node from the tree
// Its children are adopted by the parent node
int cdsc_tree_remove_node(struct cdsc_tree_node *node) {
    if (node->parent == NULL) {
	return -1;
    }
    int i;

    // Remove the node from its parent's children
    cdsc_doublylinkedlist_remove_node_if_contains(node->parent->children, node);
    // Set the parent of all of the node's children to the node's parent
    cdsc_doublylinkedlist_foreach(node->children, _setparent, node->parent); 

    // Merge the node's children with its parent's children.
    cdsc_doublylinkedlist_concat(node->parent->children, node->children);


    // Purge the node
    cdsc_tree_purge_node(node);
    return 1;
}

// Graft a node and all its children to another
// This will make this node a child of the parent node.
int cdsc_tree_graft(struct cdsc_tree_node *nod,
		    struct cdsc_tree_node *parent) {
    cdsc_doublylinkedlist_remove_node_if_contains(nod->parent->children, nod);
    cdsc_doublylinkedlist_inserttail(parent->children, nod);
    nod->parent = parent;
    return 1;

}

// Get how deep a node is in the tree
int cdsc_tree_get_depth(struct cdsc_tree_node *nod) {
    int i = 0;
    struct cdsc_tree_node *cur = nod;
    while (cur->parent != NULL) {
	i++;
	cur = cur->parent;
    }
    return i;

}

// A decent O(n) algorithm to get the last common ancestor between two nodes.
struct cdsc_tree_node *cdsc_tree_naive_lca(struct cdsc_tree_node *nod1,
					   struct cdsc_tree_node *nod2) {
    int dpt1 = cdsc_tree_get_depth(nod1);
    int dpt2 = cdsc_tree_get_depth(nod2);

    struct cdsc_tree_node *lower;
    struct cdsc_tree_node *higher;

    int diff = 0;
    int i = 0;

    if (dpt1 != dpt2) {
	if (dpt1 > dpt2) {
	    diff = (dpt1 - dpt2);
	    lower = nod1;
	    higher = nod2;
	} else {
	    diff = (dpt2 - dpt1);
	    lower = nod2;
	    higher = nod1;
	}
	for (i = 0; i < diff; i++) {
	    lower = lower->parent;
	}

    } else {
	lower = nod1;
	higher = nod2;
    }

    // From this point higher and lower are at the same depth.
    while (1) {
	if (higher->parent == lower->parent) {	// Last common ancestor found
	    return higher->parent;

	} else if (higher->parent == NULL || lower->parent == NULL) {	// One of the cursors reached the root, it is the LCA.
	    return higher;
	} else {		// Keep going
	    higher = higher->parent;
	    lower = lower->parent;
	}
    }
}

// Create and initialize a tree
struct cdsc_tree *cdsc_tree_make_tree() {
    struct cdsc_tree *newtree = malloc(sizeof(struct cdsc_tree));
    struct cdsc_tree_node *newnode = malloc(sizeof(struct cdsc_tree_node));
    if (newtree == NULL || newnode == NULL) {
	return NULL;
    }
    newnode->parent = NULL;
    newnode->children = cdsc_doublylinkedlist_make_dll();
    newnode->data = NULL;

    newtree->root = newnode;
    return newtree;
}

// Internal function used by the iterative post order traversal
void _stackpushnode(struct cdsc_doublylinkedlist_node *nod,
		    struct cdsc_stack *stack) {

    if (nod->data != NULL) {
	cdsc_stack_push(stack, (struct cdsc_tree_node *) nod->data);
    }
}

// Iterative pre order traversal using a stack
// Implements https://en.wikipedia.org/wiki/Tree_traversal#Pre-order_implementation
int cdsc_tree_foreach_pre_order(struct cdsc_tree_node *nod,
				void (*action)(), void *param) {
    struct cdsc_stack *stack = cdsc_stack_make_stack();
    cdsc_stack_push(stack, nod);

    while (stack->size != 0) {
	struct cdsc_tree_node *nn =
	    (struct cdsc_tree_node *) cdsc_stack_pop(stack);
	action(nn, param);
	if (nn->children->size != 0) {
	    cdsc_doublylinkedlist_foreach_reverse(nn->children, _stackpushnode, stack);

	}
    }
    cdsc_stack_nuke(stack);
    free(stack);
    return 1;

}

/*void cdsc_tree_foreach_in_order(struct cdsc_tree_node *nod,
				void (*action)(), void *param) {
    // TODO
}*/

// Implementation of post order tree traversal for n-ary trees.
int cdsc_tree_foreach_post_order(struct cdsc_tree_node *nod,
				 void (*action)(), void *param) {
    // Our main stack
    struct cdsc_stack *stack = cdsc_stack_make_stack();
    struct cdsc_tree_node *lastnode = NULL;

    // Current node to process
    struct cdsc_tree_node *nodde = NULL;

    // Push our root node to the stack
    cdsc_stack_push(stack, nod);
    while (stack->size != 0) {
	nodde = (struct cdsc_tree_node *) cdsc_stack_peek(stack);	// Get the root node of our traversal
	if (nodde->children->size == 0 || (lastnode != NULL
					   &&
					   (cdsc_doublylinkedlist_find
					    (nodde->children,
					     lastnode) != NULL))) {
	    // If node is a leaf or  last node is a child of the node
	    action(nodde, param);	// Run the passed function on that node.
	    cdsc_stack_pop(stack);	// Remove it from the stack as we go up
	    lastnode = nodde;	// Now this node is the last node visited
	} else {		// If the node is'nt a leaf and the last node visited isn't a child of the node
	    // Add its children to the stack in reverse order to be processed.
	    cdsc_doublylinkedlist_foreach_reverse(nodde->children, _stackpushnode,
				    stack);
	}

    }

    // Free all those data structures we allocated.
    cdsc_stack_nuke(stack);
    free(stack);

    return 1;

}


//TODO: Wrap those functions so the root node can also be affected
void cdsc_tree_foreach_post_order_recursive(struct cdsc_tree_node *nod,
					    void (*action)(),
					    void *param) {
    int i;
    for (i = 0; i < nod->children->size; i++) {
	cdsc_tree_foreach_post_order_recursive
	    (cdsc_doublylinkedlist_getindexfromhead(nod->children, i), action,
	     param);
	action(cdsc_doublylinkedlist_getindexfromhead(nod->children, i), param);

    }
}
void cdsc_tree_foreach_pre_order_recursive(struct cdsc_tree_node *nod,
					   void (*action)(), void *param) {
    int i;
    for (i = 0; i < nod->children->size; i++) {
	action(cdsc_doublylinkedlist_getindexfromhead(nod->children, i), param);
	cdsc_tree_foreach_pre_order_recursive
	    (cdsc_doublylinkedlist_getindexfromhead(nod->children, i), action,
	     param);
    }
}

//WARNING: Only used internally by the implementation, do NOT call unless you know what you're doing!
void cdsc_tree_purge_node(struct cdsc_tree_node *nod) {
    cdsc_doublylinkedlist_nuke(nod->children);
    free(nod->children);
    free(nod);
}

int cdsc_tree_prune_node(struct cdsc_tree_node *nod) {


    // Remove the node from its parent's children
    if (nod->parent){
        cdsc_doublylinkedlist_remove_node_if_contains(nod->parent->children, nod);
    }
    cdsc_tree_foreach_post_order(nod, cdsc_tree_purge_node, NULL);

    return 1;
}

// Zero a cdsc_tree, for this we post-order traverse it to free every node.
int cdsc_tree_nuke(struct cdsc_tree *tree) {
    cdsc_tree_prune_node(tree->root);
    tree->root = NULL;
    return 1;
}

// Increment passed integer, used in cdsc_tree_count
void _intplusplus(struct cdsc_tree_node *nod, int *in) {
    *in = *in + 1;

}

// Return the amount of nodes in a tree, for this we pre order traverse the tree and implement an int
// Which we then return
int cdsc_tree_count(struct cdsc_tree *tree) {
    int num = 1;		// Start at 1 because of root node
    cdsc_tree_foreach_pre_order(tree->root, _intplusplus, &num);	// Increment for each node in the cdsc_tree
    return num;
}
