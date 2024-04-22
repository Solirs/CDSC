#include "skiplist.h"


int cdsc_sl_at(cdsc_sl* skiplist, int layer, int at){
		struct cdsc_doublylinkedlist* layer_list = (struct cdsc_doublylinkedlist*)(cdsc_doublylinkedlist_at(skiplist->layers, layer));
		
		struct cdsc_sl_data* dt = (struct cdsc_sl_data*)(cdsc_doublylinkedlist_at(layer_list, at));
		
		return (((int)(dt->data)));
}

// Get the actual data in a node inside a skiplist.
int cdsc_sl_data_from_node(struct cdsc_doublylinkedlist_node* nd){
		struct cdsc_sl_data *dt = (struct cdsc_sl_data*)(nd->data);
		
		return (int)((dt->data));
}

struct cdsc_sl* cdsc_sl_init(int layers, double layer_up_chance){
		struct cdsc_sl* ret = malloc(sizeof(struct cdsc_sl));
		struct cdsc_doublylinkedlist_node *last_null_element = NULL;
		ret->layer_up_chance = layer_up_chance;
		
		ret->layers = cdsc_doublylinkedlist_make_dll();
		
		int i;
		for (i = 0; i < layers; i++){
			struct cdsc_doublylinkedlist* app = cdsc_doublylinkedlist_make_dll();
			cdsc_doublylinkedlist_append(ret->layers, app);
			
			// We are inserting a null element at the top of each layer that will be smaller than all elements.
			// It's not supposed to be accessible and is mainly here as a starting point for operations.
			struct cdsc_sl_data* null_element = malloc(sizeof(struct cdsc_sl_data));
			null_element->data = NULL;
			null_element->above = NULL;
			null_element->below = NULL;
			cdsc_doublylinkedlist_append(app, null_element);
			
			
			if (last_null_element != NULL){			
				null_element->below = last_null_element;

				((struct cdsc_sl_data*)(last_null_element->data))->above = app->head;
			}
			
			last_null_element = app->head;
		}
		
		return ret;
}


void _cdsc_sl_nuke_node(struct cdsc_doublylinkedlist_node* nd){
		struct cdsc_sl_data* data = ((struct cdsc_sl_data*)nd->data);
		
		free(data);
		free(nd);
}
void _cdsc_sl_nuke_list(struct cdsc_doublylinkedlist_node* list_node){
		struct cdsc_doublylinkedlist* list = ((struct cdsc_doublylinkedlist*)list_node->data);
		cdsc_doublylinkedlist_foreach(list, _cdsc_sl_nuke_node, NULL);
		free(list);
		
}
int cdsc_sl_nuke(cdsc_sl* skiplist){
		struct cdsc_doublylinkedlist_node* head = skiplist->layers->head;
		while(head != NULL){
			_cdsc_sl_nuke_list(head);
			head = head->next;
		}
		cdsc_doublylinkedlist_nuke(skiplist->layers);
		free(skiplist->layers);
		free(skiplist);
		return 1;
}

int cdsc_sl_insert(struct cdsc_sl* skiplist, int data){


	struct cdsc_doublylinkedlist_node* curr_node = ((struct cdsc_doublylinkedlist*)(skiplist->layers->tail->data))->head;
	
	struct cdsc_doublylinkedlist* level_1 = (struct cdsc_doublylinkedlist*)(skiplist->layers->head->data);
	struct cdsc_sl_data* new_data = malloc(sizeof(struct cdsc_sl_data));
	struct cdsc_doublylinkedlist_node* new_node = NULL;
	int previous_head = (int)(level_1->head->data);

	new_data->data = data;
	new_data->below = NULL;
	new_data->above = NULL;


	
	
	while (curr_node != NULL){
			int val = cdsc_sl_data_from_node(curr_node);
			int invis = 0;
			if (curr_node->previous == NULL){
				invis = 1;
			}			
			// We move until the value to be inserted is superior to the current pointer.
			while ((invis == 1 || data > val) && curr_node->next != NULL){

				
				curr_node = curr_node->next;
				val = cdsc_sl_data_from_node(curr_node);	
				invis = 0;			
				
			}
			
			
			if (((struct cdsc_sl_data*)(curr_node->data))->below == NULL){
				// If we are at layer 1 and there is no node after we append.
				if ((curr_node->next == NULL && data > val) || invis == 1){
					cdsc_doublylinkedlist_append(level_1, new_data);	
					new_node = level_1->tail;					
				}else{
					// Otherwise we insert before the pointer.
					new_node = cdsc_doublylinkedlist_insert_before(level_1, curr_node, new_data);					
				}
				break;
			}else{
				if (invis == 0){
					curr_node = ((struct cdsc_sl_data*)curr_node->previous->data)->below;
				}else{
					curr_node = ((struct cdsc_sl_data*)curr_node->data)->below;					
				}
			}
				

	}

	
	
	
	// Might be its own function?
	// This is the part where we copy an element up a layer with a random chance.
	
	// Start at layer 1.
	struct cdsc_doublylinkedlist_node* curr_list = skiplist->layers->head;	
	curr_node = new_node;
	while (1){
			// We make a seed using the current time in nanoseconds.
			// FUTURE: Allow user to supply a function to generate a seed.
			struct timespec curTime;
			clock_gettime(CLOCK_REALTIME, &curTime);
			srand(curTime.tv_nsec);
			double rd = (double)(rand());
			
			if (rd / (double)RAND_MAX < skiplist->layer_up_chance &&  curr_list->next != NULL){ // If a random number between 0 and 1 is lower than the layer up chance.
				curr_list = curr_list->next;
				struct cdsc_doublylinkedlist* list = (struct cdsc_doublylinkedlist*)(curr_list->data);

			
				// If curr_node doesn't have any node above it, we look for the closest node to have one.
				while (((struct cdsc_sl_data*)(curr_node->data))->above == NULL){
					curr_node = curr_node->previous;
				}
				// We then move up
				curr_node = ((struct cdsc_sl_data*)(curr_node->data))->above;

				// Data to be added to the new node
				struct cdsc_sl_data* nd = malloc(sizeof(struct cdsc_sl_data));
				nd->below = new_node;
				nd->above = NULL;
				nd->data = data;
				nd->invis = false;

				// We insert the new node after curr_node
				struct cdsc_doublylinkedlist_node* nn = cdsc_doublylinkedlist_insert_after(list, curr_node, nd);
				((struct cdsc_sl_data*)(new_node->data))->above = nn;
				new_node = nn;
				
			}else{
				// If we don't roll the layer up chance or a new node has been added to each layer we quit.
				return 1;
			}
	
	}
			
}
