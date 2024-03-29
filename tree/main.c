#include "tree.h"
#include <stdio.h>


void printone(struct cdsc_tree_node *nod) {
    printf("1\n");
}
void printnode(struct cdsc_tree_node *nod) {
    if (nod->data != NULL) {
	printf("%s\n", (char*)nod->data);
    }
}
int main() {
    int i;
    struct cdsc_tree *tree = cdsc_tree_make_tree();
    struct cdsc_tree_node *child =
	cdsc_tree_add_child(tree->root, "Hello1");
    struct cdsc_tree_node *child2 =
	cdsc_tree_add_child(tree->root, "Hello2");
    struct cdsc_tree_node *child3 =
	cdsc_tree_add_child(tree->root, "Hello3");
    struct cdsc_tree_node *child4 =
	cdsc_tree_add_child(tree->root, "Hello4");

    struct cdsc_tree_node *ch4 = cdsc_tree_add_child(child, "Hello11");
    struct cdsc_tree_node *ch5 = cdsc_tree_add_child(child, "Hello12");
    struct cdsc_tree_node *ch6 = cdsc_tree_add_child(child3, "Hello31");
    //cdsc_tree_add_child(ch4, "ByeBB2");
    //cdsc_tree_add_child(child2, "Hello21");
    //cdsc_tree_add_child(child3, "Hello31");
    cdsc_tree_remove_node(child4);


    //struct cdsc_tree_node *rootnode = cdsc_tree_get_root_node(child);
    //struct cdsc_tree_node *child3 = cdsc_tree_add_child(child, "bye");
    //remove_node(child);
    //prune_node(child);
    //graft(child, child2);
    ///printf("%d\n", get_depth(child));

    //prune_node(child2);

    //cdsc_tree_foreach_post_order(rootnode, printnode, NULL);

    cdsc_tree_nuke(tree);
    //nuke(rootnode->children);
    //free(rootnode->children);

    //free(rootnode);

    free(tree);

}
