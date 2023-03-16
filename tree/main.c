#include "tree.h"
#include <stdio.h>

int main(){
    struct tree* tree = make_tree();
    struct tree_node* child = add_child(tree->root, "Hello");
    struct tree_node* child2 = add_child(tree->root, "Bye");
    struct tree_node* rootnode = get_root_node(child);
    struct tree_node *child3 = add_child(child, "bye");
    //remove_node(child);
    //prune_node(child);
    graft(child, child2);
    struct tree_node* tn = ((struct tree_node*)getindexfromhead(rootnode->children, 0));
    printf("%s\n", (((struct tree_node*)getindexfromhead(tn->children, 0))->data));
    printf("%d\n", get_depth(child2));

	prune_node(child2);


	nuke(rootnode->children);
	free(rootnode->children);

	free(rootnode);
	
	free(tree);

}
