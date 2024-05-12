#include<stdbool.h>
#include<stdlib.h>
#include <stdio.h>
#include<stdarg.h>
#include "skiplist.h"


void printlist(struct cdsc_doublylinkedlist_node *nd) {
    printf("%d ", cdsc_sl_data_from_node(nd));
}

int main() {

	cdsc_sl* list = cdsc_sl_init(5, 0.75);
	struct cdsc_doublylinkedlist* last_lv = ((struct cdsc_doublylinkedlist*)(list->layers->tail->data));
	struct cdsc_doublylinkedlist* level_1 = (struct cdsc_doublylinkedlist*)(list->layers->head->data);
	
	cdsc_doublylinkedlist_foreach(last_lv, printlist, NULL);
	struct cdsc_doublylinkedlist_node* l1h = ((struct cdsc_sl_data*)(last_lv->head->data))->below;


	struct cdsc_doublylinkedlist* ls = ((struct cdsc_doublylinkedlist*)(list->layers->head->next->data));
	printf("SIZE %d\n", ls->size);
	


	cdsc_sl_insert(list, 1,NULL);
	cdsc_sl_insert(list, 6,NULL);
	cdsc_sl_insert(list, 6,NULL);

	
	cdsc_sl_insert(list, 4,NULL);

	
	cdsc_sl_insert(list, 0,NULL);

	cdsc_sl_insert(list, -1,NULL);
	cdsc_sl_insert(list, 12,NULL);
	cdsc_sl_insert(list, 7,NULL);
	
	struct cdsc_doublylinkedlist* sevn = cdsc_sl_search(list, 6,NULL);
 	printf("RESULT: %d\n", sevn->size);

	printf("LIST 1:\n");
	printf("SIZE %d\n", list->layers->size);
	
	cdsc_sl_delete(list, 6, NULL);
		

	printf("CONTENTS: \n");
	
	for (int i = list->layers->size-1; i >= 0; i--){
			struct cdsc_doublylinkedlist* layer = ((struct cdsc_doublylinkedlist*)(cdsc_doublylinkedlist_at(list->layers, i)));
			cdsc_doublylinkedlist_foreach(layer, printlist, NULL);
			printf("\n");
	}
	
	cdsc_sl_nuke(list);
    return 0;
}