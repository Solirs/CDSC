#include "tree.h"

int main(){
    struct tree* tree = make_tree();
    struct tree_node* child = add_child(tree->root, "Hello");
    struct tree_node* child2 = add_child(tree->root, "Bye");
    struct tree_node* rootnode = get_root_node(child);
    add_child(child, "bye");
    remove_node(child);
    struct tree_node* tn = (struct tree_node*)getindexfromhead(rootnode->children, 0);
    printf("%s\n", tn->data);

}