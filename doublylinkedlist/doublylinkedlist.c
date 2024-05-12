#include "doublylinkedlist.h"

#define LIST_EMPTY list->size == 0

// Create and init double linked list
struct cdsc_doublylinkedlist *cdsc_doublylinkedlist_make_dll() {
    struct cdsc_doublylinkedlist *ret =
	malloc(sizeof(struct cdsc_doublylinkedlist));
    ret->size = 0;
    ret->head = NULL;
    ret->tail = NULL;
    return ret;
}


// Function to get the data at a certain index.
// This function determines whether the index is closer to the head or the tail and uses the fastest option.
// Recommended for library usage.
void *cdsc_doublylinkedlist_at(struct cdsc_doublylinkedlist *list,
			       int index) {
    if (index < list->size / 2) {
	return cdsc_doublylinkedlist_getindexfromhead(list, index);
    } else {
	return cdsc_doublylinkedlist_getindexfromtail(list,
						      list->size - 1 -
						      index);
    }
}



// Zeroes a cdsc_doublylinkedlist, mainly used internally.
int cdsc_doublylinkedlist_zero(struct cdsc_doublylinkedlist *ll) {
    ll->head = NULL;
    ll->tail = NULL;
    ll->size = 0;
    return 1;

}

// Add new node at the head, replacing it.
int cdsc_doublylinkedlist_inserthead(struct cdsc_doublylinkedlist *list,
				     void *data) {
    struct cdsc_doublylinkedlist_node *ins =
	malloc(sizeof(struct cdsc_doublylinkedlist_node));
    if (ins == NULL) {
	return -1;		// malloc went wrong.
    }
    ins->data = data;
    ins->previous = NULL;
    if (list->size == 0) {
	ins->next = NULL;

	list->tail = ins;
    } else {
	ins->next = list->head;
	list->head->previous = ins;
    }
    list->head = ins;
    list->size++;
    return 1;
}

// Add new node at the tail, replacing it.
int cdsc_doublylinkedlist_inserttail(struct cdsc_doublylinkedlist *list,
				     void *data) {
    struct cdsc_doublylinkedlist_node *ins =
	malloc(sizeof(struct cdsc_doublylinkedlist_node));
    if (ins == NULL) {
	return -1;		// malloc went wrong.
    }
    ins->data = data;
    ins->next = NULL;
    if (list->size == 0) {
	ins->previous = NULL;
	list->head = ins;

    } else {
	ins->previous = list->tail;
	list->tail->next = ins;
    }
    list->tail = ins;
    list->size++;
    return 1;


}

// Remove the list's tail replacing it by the node before it
void *cdsc_doublylinkedlist_poptail(struct cdsc_doublylinkedlist *list) {
    if (LIST_EMPTY) {
	return NULL;
    }
    struct cdsc_doublylinkedlist_node *newtail = list->tail->previous;
    void *ret = list->tail->data;
    //We need to free the node struct that was allocated in inserttail or inserthead
    free(list->tail);
    if (list->size > 1) {
	newtail->next = NULL;
	list->tail = newtail;
	list->size--;
    } else {
	cdsc_doublylinkedlist_zero(list);
    }
    return ret;

}

// Remove the list's head replacing it with the next node
void *cdsc_doublylinkedlist_pophead(struct cdsc_doublylinkedlist *list) {
    if (LIST_EMPTY) {
	return NULL;
    }
    struct cdsc_doublylinkedlist_node *newhead = list->head->next;
    void *ret = list->head->data;
    //We need to free the node struct that was allocated in inserttail or inserthead
    free(list->head);

    if (list->size > 1) {
	newhead->previous = NULL;
	list->head = newhead;
	list->size--;

    } else {
	cdsc_doublylinkedlist_zero(list);
    }
    return ret;

}

// Get data by index starting at the head
void *cdsc_doublylinkedlist_getindexfromhead(struct cdsc_doublylinkedlist
					     *list, int index) {
    if (LIST_EMPTY) {
	return NULL;
    }

    int i;
    struct cdsc_doublylinkedlist_node *cur = list->head;

    for (i = 0; i < index; i++) {
	cur = cur->next;
	if (cur == NULL) {
	    return NULL;
	}
    }

    return cur->data;
}

// Get data by index starting at the tail
void *cdsc_doublylinkedlist_getindexfromtail(struct cdsc_doublylinkedlist
					     *list, int index) {
    if (LIST_EMPTY) {
	return NULL;
    }
    int i;
    struct cdsc_doublylinkedlist_node *cur = list->tail;

    for (i = 0; i < index; i++) {
	cur = cur->previous;
	if (cur == NULL) {
	    return NULL;
	}
    }

    return cur->data;
}


// Completely wipe a doubly linked list
int cdsc_doublylinkedlist_nuke(struct cdsc_doublylinkedlist *list) {
    struct cdsc_doublylinkedlist_node *cur;
    cur = list->head;
    if (LIST_EMPTY) {
	return -1;
    }
    if (list->head == list->tail) {
	free(list->head);

    } else {
	while (1) {
	    struct cdsc_doublylinkedlist_node *nxt = cur->next;
	    if (cur == list->tail) {
		free(cur);
		break;
	    } else {
		free(cur);
		cur = nxt;
	    }

	}

    }
    cdsc_doublylinkedlist_zero(list);
    return 1;
}

// Sets the data of a DoublyLinkedList's certain index.
// Starting from head if the index is closer to it otherwise from tail
int cdsc_doublylinkedlist_setdata(struct cdsc_doublylinkedlist *list,
				  void *data, int index) {
    int i;
    struct cdsc_doublylinkedlist_node *cur;

    if (index < list->size / 2) {
	cur = list->head;
	for (i = 0; i < index; i++) {
	    cur = cur->next;
	    if (cur == NULL) {
		return -1;
	    }
	}
    } else {
	cur = list->tail;
	for (i = 0; i < list->size - 1 - index; i++) {
	    cur = cur->previous;
	    if (cur == NULL) {
		return -1;
	    }
	}
    }

    cur->data = data;
    return 1;
}

int cdsc_doublylinkedlist_reverse(struct cdsc_doublylinkedlist *list) {
    if (list->size < 2) {
	return -1;
    }
    struct cdsc_doublylinkedlist_node *prev = NULL;
    struct cdsc_doublylinkedlist_node *formerhead = list->head;
    list->tail = formerhead;
    struct cdsc_doublylinkedlist_node *current = list->head;
    struct cdsc_doublylinkedlist_node *next;

    while (current != NULL) {
	next = current->next;
	current->next = prev;
	prev = current;
	current = next;
    }
    list->head = prev;
    return 1;
}

int cdsc_doublylinkedlist_appendnode(struct cdsc_doublylinkedlist *list, struct cdsc_doublylinkedlist_node
				     *node) {
    if (LIST_EMPTY) {
	list->head = node;
	list->tail = node;
    } else {
	list->tail->next = node;
	list->tail = node;
    }
    list->size++;
    return 1;

}
/*
void cdsc_doublylinkedlist_merge(struct cdsc_doublylinkedlist *list1,
				 struct cdsc_doublylinkedlist *list2) {
    list1->tail->next = list2->head;
    list2->head->previous = list1->tail;
    list1->size += list2->size;
}				// TODO: Apply fixes from linkedlist
*/
int cdsc_doublylinkedlist_contains(struct cdsc_doublylinkedlist *list,
				   void *data) {
    if (LIST_EMPTY) {
	return -1;
    }
    int i;
    struct cdsc_doublylinkedlist_node *cur = list->head;
    for (i = 0; i < list->size; i++) {
	if (cur->data == data) {
	    return 1;
	} else {;
	    cur = cur->next;
	}

    }
    return 0;
}

struct cdsc_doublylinkedlist_node *cdsc_doublylinkedlist_find(struct
							      cdsc_doublylinkedlist
							      *list,
							      void *key) {
    if (LIST_EMPTY) {
	return NULL;
    }
    struct cdsc_doublylinkedlist_node *current = list->head;
    while (current->data != key) {
	if (current->next == NULL) {
	    return NULL;
	} else {
	    current = current->next;
	}
    }
    return current;
}

int cdsc_doublylinkedlist_findindex(struct cdsc_doublylinkedlist *list,
				    void *key) {
    if (LIST_EMPTY) {
	return -1;
    }
    struct cdsc_doublylinkedlist_node *current = list->head;
    int i = 0;
    while (current->data != key) {
	if (current->next == NULL) {
	    return -1;
	} else {
	    current = current->next;
	    i++;
	}
    }
    return i;
}

// Run a function for each member of a doublylinkedlist.
int cdsc_doublylinkedlist_foreach(struct cdsc_doublylinkedlist *list,
				  void (*action)(), void *param) {
    if (LIST_EMPTY) {
	return -1;
    }
    struct cdsc_doublylinkedlist_node *cur = list->head;
    while (cur != NULL) {
	action(cur, param);
	cur = cur->next;
    }
    return 1;
}
// Run a function for each member of a doublylinkedlist.
int cdsc_doublylinkedlist_foreach_reverse(struct cdsc_doublylinkedlist *list,
				  void (*action)(), void *param) {
    if (LIST_EMPTY) {
	return -1;
    }
    struct cdsc_doublylinkedlist_node *cur = list->tail;
    while (cur != NULL) {
	action(cur, param);
	cur = cur->previous;
    }
    return 1;
}

struct cdsc_doublylinkedlist_node *cdsc_doublylinkedlist_node_at(struct
								 cdsc_doublylinkedlist
								 *list,
								 int
								 index) {
    if (list->head == NULL) {
	return NULL;
    }
    int i;
    struct cdsc_doublylinkedlist_node *cur = list->head;


    for (i = 0; i < index; i++) {
	cur = cur->next;

	if (cur == NULL) {
	    return NULL;
	}

    }

    return cur;
}

int echo(int num, int num2) {
    return num - num2;
}

// This implements Tony Hoare's partition scheme for quicksort
struct qs_ret _qsort_partition(struct cdsc_doublylinkedlist *list, int low,
			       int high,
			       struct cdsc_doublylinkedlist_node *hptr,
			       struct cdsc_doublylinkedlist_node *lptr,
			       int (*comparator)()) {

    // If no comparator is set we fallback to a default one that 
    // Compares the two numbers normally
    if(comparator == NULL) {
	comparator = echo;
    }
    struct qs_ret qsr;
    int count = 0;
    struct cdsc_doublylinkedlist_node *pointer1 = lptr;
    struct cdsc_doublylinkedlist_node *pointer2 = hptr;
    //int pivot = (int)cdsc_doublylinkedlist_getindexfromhead(list,floor((low+high)/2)); // Choose middle element of list or sublist as pivot
    void *pivot = lptr->data;	// This is not great, but this is the best way to choose a pivot i can come up with right now to minimize linked list operations


    while (1) {

	if (count > 0) {
	    pointer1 = pointer1->next;
	    low++;
	}
	// Comparators return a negative value if the second passed value is superior
	// A positive one if the second passed value is inferior
	// And Zero if both are equal
	while (comparator(pointer1->data, pivot) < 0) {
	    pointer1 = pointer1->next;
	    low++;
	}
	if (count > 0) {
	    pointer2 = pointer2->previous;
	    high--;

	}

	while (comparator(pointer2->data, pivot) > 0) {
	    pointer2 = pointer2->previous;
	    high--;

	}


	void *value1 = pointer1->data;
	void *value2 = pointer2->data;
	if (low >= high || high <= low) {
	    // We return both the second pointer as well as a pointer to the node it 
	    // is at.
	    qsr.ptr = high;
	    qsr.nod = pointer2;
	    return qsr;
	} else if (comparator(value1, pivot) > 0
		   || comparator(value2, pivot) < 0) {
	    // We swap if the value at the first pointer is higher than the pivot
	    // Or if the value at the second pointer is lower
	    pointer1->data = value2;
	    pointer2->data = value1;
	}
	count = 1;

    }

}


int cdsc_doublylinkedlist_qsort(struct cdsc_doublylinkedlist *list,
				int (*comparator)()) {
    if(list->size < 2) {
	return 0;
    }
    _cdsc_doublylinkedlist_qsort(list, 0, list->size - 1,
				 cdsc_doublylinkedlist_node_at(list,
							       list->size -
							       1),
				 cdsc_doublylinkedlist_node_at(list, 0),
				 comparator);
    return 1;
}
void _cdsc_doublylinkedlist_qsort(struct cdsc_doublylinkedlist *list,
				  int low, int high,
				  struct cdsc_doublylinkedlist_node *hptr,
				  struct cdsc_doublylinkedlist_node *lptr,
				  int (*comparator)()) {
    if(low >= 0 && high >= 0 && low < high) {
	struct qs_ret p =
	    _qsort_partition(list, low, high, hptr, lptr, comparator);

	_cdsc_doublylinkedlist_qsort(list, low, p.ptr, p.nod, lptr,
				     comparator);
	_cdsc_doublylinkedlist_qsort(list, p.ptr + 1, high, hptr,
				     p.nod->next, comparator);
    }


}
// Merge two lists by copying and appending the data of list2 and list1 to a new one.
struct cdsc_doublylinkedlist *cdsc_doublylinkedlist_merge(struct cdsc_doublylinkedlist
					      *list1, struct cdsc_doublylinkedlist
					      *list2) {
    struct cdsc_doublylinkedlist *dest = cdsc_doublylinkedlist_make_dll();
    struct cdsc_doublylinkedlist_node *cur = list1->head;
    while (cur != NULL) {
		cdsc_doublylinkedlist_append(dest, cur->data);
		cur = cur->next;
    }
    cur = list2->head;
    while (cur != NULL) {
	cdsc_doublylinkedlist_append(dest, cur->data);
	cur = cur->next;

    }

    return dest;

}

// Concatenate two lists into the first.
void cdsc_doublylinkedlist_concat(struct cdsc_doublylinkedlist
					      *list1, struct cdsc_doublylinkedlist
					      *list2) {
    struct cdsc_doublylinkedlist_node *cur = cur = list2->head;
    while (cur != NULL) {
	cdsc_doublylinkedlist_append(list1, cur->data);
	cur = cur->next;

    }

}
int cdsc_doublylinkedlist_remove_node_if_contains(struct cdsc_doublylinkedlist *list,
					    void *key) {
    int i;
    struct cdsc_doublylinkedlist_node *cur = list->head;
    struct cdsc_doublylinkedlist_node *prev = NULL;
	if (cur->data == key){
		cdsc_doublylinkedlist_pophead(list);
		return 1;
	}else{
		prev = cur;
		cur = cur->next;
	}

    while (cur != NULL) {
	if (cur->data == key) {
	    if (cur == list->tail) {
			cdsc_doublylinkedlist_poptail(list);

	    } else {
		prev->next = cur->next;
		cur->next->previous = prev;
		free(cur);
	    }
	} else {
	    prev = cur;
	    cur = cur->next;
	}

    }
    return 1;
}


// Insert data at a specific index, inserting at an index i will insert the new element right before the element that was present there.
// For example, inserting at 0 is the same as cdsc_doublylinkedlist_inserthead.
// Inserting at index 1 will insert the element between node 0 and 1
// TODO: Handle edge cases
struct cdsc_doublylinkedlist_node* cdsc_doublylinkedlist_insert(struct cdsc_doublylinkedlist *list, void* data, int at){
		struct cdsc_doublylinkedlist_node *ins =
		malloc(sizeof(struct cdsc_doublylinkedlist_node));
		ins->data = data;
		struct cdsc_doublylinkedlist_node* nod = cdsc_doublylinkedlist_node_at(list, at);
		if (at > list->size){
			return NULL;
		} else if (at == list->size){
			cdsc_doublylinkedlist_appendnode(list, ins);
			list->size++;
			return ins;
		}
		
		struct cdsc_doublylinkedlist_node* node_before = nod->previous;
		
		if (node_before != NULL){
			node_before->next = ins;
			ins->previous = node_before;
		}else{
			list->head = ins;
		}
		
		nod->previous = ins;
		ins->next = nod;
		
		list->size++;
		
		return ins;
		
}

// Same as cdsc_doublylinkedlist_insert but to directly insert a node
// TODO: Handle edge cases
int cdsc_doublylinkedlist_insertnode(struct cdsc_doublylinkedlist *list, struct cdsc_doublylinkedlist_node* ins, int at){

		struct cdsc_doublylinkedlist_node* nod = cdsc_doublylinkedlist_node_at(list, at);
		if (at > list->size){
			return -1;
		} else if (at == list->size){
			cdsc_doublylinkedlist_appendnode(list, ins);
			list->size++;
			return 1;
		}
		
		struct cdsc_doublylinkedlist_node* node_before = nod->previous;
		
		if (node_before != NULL){
			node_before->next = ins;
			ins->previous = node_before;
		}else{
			list->head = ins;
		}
		
		nod->previous = ins;
		ins->next = nod;
		
		list->size++;
		
		return 1;
		
}


// Insert a new node containing data right after a given node.
// TODO: Handle edge cases
struct cdsc_doublylinkedlist_node* cdsc_doublylinkedlist_insert_after(struct cdsc_doublylinkedlist *list, struct cdsc_doublylinkedlist_node* at, void* data){
		struct cdsc_doublylinkedlist_node *ins =
		malloc(sizeof(struct cdsc_doublylinkedlist_node));
		ins->data = data;

		struct cdsc_doublylinkedlist_node* node_after = at->next;
		at->next = ins;
		ins->previous = at;
		if (node_after != NULL){
				node_after->previous = ins;
				ins->next = node_after;
				
		}else{	
			list->tail = ins;
		}
		
		
		list->size++;
		
		return ins;
		
}

// Insert a new node containing data right before a given node.
// TODO: Handle edge cases
struct cdsc_doublylinkedlist_node* cdsc_doublylinkedlist_insert_before(struct cdsc_doublylinkedlist *list, struct cdsc_doublylinkedlist_node* at, void* data){
		struct cdsc_doublylinkedlist_node *ins =
		malloc(sizeof(struct cdsc_doublylinkedlist_node));
		ins->data = data;

		struct cdsc_doublylinkedlist_node* node_before = at->previous;
		at->previous = ins;
		ins->next = at;
		if (node_before != NULL){
				node_before->next = ins;
				ins->previous = node_before;
		}else{	
			list->head = ins;
		}
		
		
		list->size++;
		
		return ins;
		
}

