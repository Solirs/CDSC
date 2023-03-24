#include "binary_tree.h"
#include <stdio.h>

void printnode(struct cdsc_btree_node* nod){
	printf("%s\n", nod->data);
}
void printone(struct cdsc_btree_node* nod){
	printf("1\n");
}


int main(){
    struct cdsc_btree* tree = cdsc_btree_make_btree();
	cdsc_btree_insert_lchild(tree->root, "Hello");
	struct cdsc_btree_node* nd1 = cdsc_btree_insert_rchild(tree->root, "Bye");
	struct cdsc_btree_node* nd2 = cdsc_btree_insert_rchild(nd1, "JJ");
	//cdsc_btree_prune_node(nd1);	
	//cdsc_btree_foreach_pre_order(tree->root, printone, NULL);
	printf("%d\n", cdsc_btree_count(tree));
	cdsc_btree_nuke(tree->root);
	free(tree);
}
