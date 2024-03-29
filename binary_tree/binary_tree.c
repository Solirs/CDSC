#include "binary_tree.h"
#include <stdio.h>

struct cdsc_btree_node *cdsc_btree_makenode(struct cdsc_btree_node *parent) {
    struct cdsc_btree_node *newnode =
	malloc(sizeof(struct cdsc_btree_node));
    if (newnode == NULL) {
	return NULL;
    }
    newnode->parent = parent;
    newnode->data = NULL;
    newnode->rchild = NULL;
    newnode->lchild = NULL;
    return newnode;
}

// Implements https://en.wikipedia.org/wiki/Binary_tree#Internal_nodes
struct cdsc_btree_node *cdsc_btree_insert_lchild(struct cdsc_btree_node
						 *node, void *data) {
    struct cdsc_btree_node *newnode = cdsc_btree_makenode(node);
    newnode->lchild = node->lchild;
    newnode->data = data;

    if (node->lchild) {
	node->lchild->parent = newnode;
    }
    node->lchild = newnode;

    return newnode;
}

// Implements https://en.wikipedia.org/wiki/Binary_tree#Internal_nodes
struct cdsc_btree_node *cdsc_btree_insert_rchild(struct cdsc_btree_node
						 *node, void *data) {
    struct cdsc_btree_node *newnode = cdsc_btree_makenode(node);
    newnode->rchild = node->rchild;
    newnode->data = data;


    if (node->rchild) {
	node->rchild->parent = newnode;
    }
    node->rchild = newnode;

    return newnode;
}

//TODO: Actually implement
/*struct cdsc_btree_node* cdsc_btree_insert_leaf(struct cdsc_btree* tree, void* data){
	struct cdsc_btree_node* nod = tree->root;
	struct cdsc_btree_node *newnode = cdsc_btree_makenode(nod);
	newnode->rchild = nod->rchild;

	nod->rchild = malloc(sizeof(struct cdsc_btree_node));
    nod->rchild->parent = newnode;
    nod->rchild = newnode;

    return newnode;
}*/

struct cdsc_btree_node *cdsc_btree_get_root_node(struct cdsc_btree_node
						 *node) {
    while (true) {
	if (node->parent == NULL) {
	    return node;
	} else {
	    node = node->parent;
	}
    }
}

// Get the number of children a node has
int cdsc_btree_getchildnum(struct cdsc_btree_node *node) {
    if (node->lchild != NULL && node->rchild != NULL) {
	return 2;
    } else if (node->lchild == NULL && node->rchild == NULL) {
	return 0;
    } else {
	return 1;
    }
}

// Is the single child of a tree node its left child or right child??, O(1)
struct cdsc_btree_node *cdsc_btree_get_child_direction(struct
						       cdsc_btree_node
						       *node) {
    int childnum = cdsc_btree_getchildnum(node);
    if (childnum == 2 || childnum == 0) {
	return NULL;
    } else {
	if (node->lchild != NULL) {
	    return node->lchild;
	} else {
	    return node->rchild;
	}
    }

}

//WARNING: Only used internally by the implementation, do NOT call unless you know what you're doing!
void cdsc_btree_purge_node(struct cdsc_btree_node *node) {
    free(node);
}

// Gracefully remove a node
// Implements https://en.wikipedia.org/wiki/Binary_tree#Deletion
int cdsc_btree_remove_node(struct cdsc_btree_node *node) {
    int childnum = cdsc_btree_getchildnum(node);
    struct cdsc_btree_node *childdir =
	cdsc_btree_get_child_direction(node);

    if (node->parent->rchild == node) {
	node->parent->rchild = childdir;
    } else if (node->parent->lchild == node) {
	node->parent->lchild = childdir;
    }
    if (childnum == 2) {
	cdsc_btree_prune_node(node);
    } else {
	if (childdir != NULL) {
	    childdir->parent = node->parent;
	}
	cdsc_btree_purge_node(node);
    }
    return 1;
}

// Purges/frees a node and all of its children.
int cdsc_btree_prune_node(struct cdsc_btree_node *nod) {
    return cdsc_btree_foreach_post_order(nod, cdsc_btree_purge_node, NULL);
}

// Iterative post order binary tree traversal algorithm, implements https://en.wikipedia.org/wiki/Tree_traversal#Post-order_implementation
int cdsc_btree_foreach_post_order(struct cdsc_btree_node *nod,
				  void (*action)(), void *param) {
    struct cdsc_stack *stack = cdsc_stack_make_stack();
    struct cdsc_btree_node *node = nod;
    struct cdsc_btree_node *lastnodevisited = NULL;

    while (stack->size != 0 || node != NULL) {
	if (node != NULL) {
	    cdsc_stack_push(stack, node);
	    node = node->lchild;
	} else {
	    struct cdsc_btree_node *pnode = cdsc_stack_peek(stack);
	    if (pnode->rchild != NULL && lastnodevisited != pnode->rchild) {
		node = pnode->rchild;
	    } else {
		action(pnode, param);
		lastnodevisited = cdsc_stack_pop(stack);
	    }

	}
    }
    cdsc_stack_nuke(stack);
    free(stack);
    return 1;

}

int cdsc_btree_foreach_post_order_recursive(struct cdsc_btree_node *nod,
					    void (*action)(),
					    void *param) {
    _cdsc_btree_foreach_post_order_recursive(nod, action, param);
    action(nod, param);
    return 1;

}
void _cdsc_btree_foreach_post_order_recursive(struct cdsc_btree_node *nod,
					      void (*action)(),
					      void *param) {
    if (nod->rchild != NULL) {
	_cdsc_btree_foreach_post_order_recursive(nod->rchild, action,
						 param);
	action(nod->rchild, param);
    }
    if (nod->lchild != NULL) {
	_cdsc_btree_foreach_post_order_recursive(nod->lchild, action,
						 param);
	action(nod->lchild, param);
    }

}

// Convinces a node's parent to ruthlessly sell its own child to be eaten by faroese leprechauns.
// Really though it just separates a node from its parent
int cdsc_btree_orphan(struct cdsc_btree_node *nod) {
    if (nod->parent == NULL) {
	return -1;
    }
    if (nod->parent->rchild == nod) {
	nod->parent->rchild = NULL;
    } else if (nod->parent->lchild == nod) {
	nod->parent->lchild = NULL;
    }
    nod->parent = NULL;
    return 1;


}

// Implements https://en.wikipedia.org/wiki/Binary_tree#Internal_nodes
int cdsc_btree_graft_lchild(struct cdsc_btree_node *nod,
			    struct cdsc_btree_node *parent) {
    cdsc_btree_orphan(nod);
    if (parent->lchild) {
	cdsc_btree_prune_node(parent->lchild);
    }
    parent->lchild = nod;
    nod->parent = parent;
    return 1;

}

// Implements https://en.wikipedia.org/wiki/Binary_tree#Internal_nodes
int cdsc_btree_graft_rchild(struct cdsc_btree_node *nod,
			    struct cdsc_btree_node *parent) {
    cdsc_btree_orphan(nod);
    if (parent->rchild) {
	cdsc_btree_prune_node(parent->rchild);
    }
    parent->rchild = nod;
    nod->parent = parent;
    return 1;

}
int cdsc_btree_get_depth(struct cdsc_btree_node *nod) {
    int i = 0;
    struct cdsc_btree_node *cur = nod;
    while (cur->parent != NULL) {
	cur = cur->parent;
	i++;

    }
    return i;

}

// A decent O(n) algorithm to get the last common ancestor between two nodes.
struct cdsc_btree_node *cdsc_btree_naive_lca(struct cdsc_btree_node *nod1,
					     struct cdsc_btree_node *nod2) 
{
    int dpt1 = cdsc_btree_get_depth(nod1);
    int dpt2 = cdsc_btree_get_depth(nod2);

    struct cdsc_btree_node *lower;
    struct cdsc_btree_node *higher;

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

struct cdsc_btree *cdsc_btree_make_btree() {
    struct cdsc_btree *newtree = malloc(sizeof(struct cdsc_btree));
    struct cdsc_btree_node *newnode = cdsc_btree_makenode(NULL);
    newtree->root = newnode;
    newtree->root->parent = NULL;
    return newtree;
}


// Implements https://en.wikipedia.org/wiki/Tree_traversal#Pre-order_implementation
int cdsc_btree_foreach_pre_order(struct cdsc_btree_node *nod,
				 void (*action)(), void *param) {
    struct cdsc_stack *stack = cdsc_stack_make_stack();
    cdsc_stack_push(stack, nod);
    while (stack->size != 0) {
	struct cdsc_btree_node *node = cdsc_stack_pop(stack);
	action(node, param);
	if (node->rchild != NULL) {
	    cdsc_stack_push(stack, node->rchild);
	}
	if (node->lchild != NULL) {
	    cdsc_stack_push(stack, node->lchild);
	}
    }
    cdsc_stack_nuke(stack);
    free(stack);
    return 1;
}
int cdsc_btree_foreach_pre_order_recursive(struct cdsc_btree_node *nod,
					   void (*action)(), void *param) {
    action(nod, param);
    _cdsc_btree_foreach_pre_order_recursive(nod, action, param);
    return 1;



}
void _cdsc_btree_foreach_pre_order_recursive(struct cdsc_btree_node *nod,
					     void (*action)(),
					     void *param) {
    if (nod->rchild != NULL) {
	action(nod->rchild, param);
	_cdsc_btree_foreach_pre_order_recursive(nod->rchild, action,
						param);
    }

    if (nod->lchild != NULL) {
	action(nod->lchild, param);
	_cdsc_btree_foreach_pre_order_recursive(nod->lchild, action,
						param);
    }



}

// Zero a tree
int cdsc_btree_nuke(struct cdsc_btree_node *nod) {
    return cdsc_btree_prune_node(cdsc_btree_get_root_node(nod));
}

// Increment passed integer, used in cdsc_tree_count
void _bintplusplus(struct cdsc_btree_node *nod, int *in) {
    *in = *in + 1;

}
int cdsc_btree_count(struct cdsc_btree *tree) {
    int num = 0;
    cdsc_btree_foreach_pre_order(tree->root, _bintplusplus, &num);	// Increment for each node in the tree
    return num;
}
