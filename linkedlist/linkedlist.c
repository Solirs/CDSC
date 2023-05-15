#include "linkedlist.h"

// Add new cdsc_linkedlist_node at the head containing the data in the "data" parameter, replacing it.
int cdsc_linkedlist_inserthead(struct cdsc_linkedlist *list, void *data) {
    struct cdsc_linkedlist_node *ins =
	malloc(sizeof(struct cdsc_linkedlist_node));
    if (ins == NULL) {
	return -1;
    }
    ins->data = data;
    if (list->size == 0) {
	ins->next = NULL;

	list->tail = ins;
    } else {
	ins->next = list->head;
    }
    list->head = ins;
    list->size++;
    return 1;
}

// Add new cdsc_linkedlist_node at the tail containing the data in the "data" parameter, replacing it.
int cdsc_linkedlist_inserttail(struct cdsc_linkedlist *list, void *data) {
    struct cdsc_linkedlist_node *ins =
	malloc(sizeof(struct cdsc_linkedlist_node));
    if (ins == NULL) {
	return -1;
    }
    ins->data = data;
    ins->next = NULL;
    if (list->size == 0) {
	list->head = ins;

    } else {
	list->tail->next = ins;
    }
    list->tail = ins;
    list->size++;
    return 1;


}

// Remove the list's tail replacing it by the cdsc_linkedlist_node before it
void *cdsc_linkedlist_poptail(struct cdsc_linkedlist *list) {
    struct cdsc_linkedlist_node *newtail;
    int i;
    for (i = 0; i < list->size; i++) {
	newtail = newtail->next;
    }
    void *ret = list->tail->data;
    //We need to free the cdsc_linkedlist_node struct that was allocated in inserttail or inserthead
    free(list->tail);
    list->tail = NULL;
    if (list->size > 1) {
	newtail->next = NULL;
	list->tail = newtail;
    }
    list->size--;
    return ret;

}

// Remove the list's head replacing it with the next cdsc_linkedlist_node
void *cdsc_linkedlist_pophead(struct cdsc_linkedlist *list) {
    struct cdsc_linkedlist_node *newhead = list->head->next;
    void *ret = list->head->data;
    //We need to free the cdsc_linkedlist_node struct that was allocated in inserttail or inserthead
    free(list->head);
    list->head = NULL;

    if (list->size > 1) {
	list->head = newhead;
    }
    list->size--;
    return ret;

}

// Get data by index starting at the head
void *cdsc_linkedlist_getindexfromhead(struct cdsc_linkedlist *list,
				       int index) {
    if (list->head == NULL) {
	return NULL;
    }
    int i;
    struct cdsc_linkedlist_node *cur = list->head;


    for (i = 0; i < index; i++) {
	cur = cur->next;

	if (cur == NULL) {
	    return NULL;
	}

    }

    return cur->data;
}

// Get data by index starting at the tail
void *cdsc_linkedlist_getindexfromtail(struct cdsc_linkedlist *list,
				       int index) {
    int i;
    struct cdsc_linkedlist_node *cur = list->head;
    if (index == 0) {
	return list->tail->data;
    } else {
	index = (list->size - index - 1);
	for (i = 0; i < index; i++) {
	    cur = cur->next;
	    if (cur == NULL) {
		return NULL;
	    }
	}

	return cur->data;

    }


}

// Create and init linked list
struct cdsc_linkedlist *cdsc_linkedlist_make_ll() {
    struct cdsc_linkedlist *ret = malloc(sizeof(struct cdsc_linkedlist));
    ret->size = 0;
    ret->head = NULL;
    ret->tail = NULL;
    return ret;
}

// Completely wipe a linked list
int cdsc_linkedlist_nuke(struct cdsc_linkedlist *list) {
    struct cdsc_linkedlist_node *cur;
    if (list->size == 0) {
	return 1;		// Nothing to do!
    }
    if (list->head == list->tail) {
	free(list->head);
	list->head = NULL;
    } else {
	cur = list->head;
	while (1) {
	    struct cdsc_linkedlist_node *nxt = cur->next;
	    if (cur == list->tail) {
		free(cur);
		cur = NULL;
		break;
	    } else {
		free(cur);
		cur = nxt;
	    }

	}
    }
    list->size = 0;
    return 1;

}

// Sets the data of a LinkedList's certain index, starting from the head.
int cdsc_linkedlist_setdata(struct cdsc_linkedlist *list, void *data,
			    int index) {
    int i;
    struct cdsc_linkedlist_node *cur = list->head;
    for (i = 0; i < index; i++) {
	cur = cur->next;
	if (cur == NULL) {
	    return -1;
	}
    }
    cur->data = data;
    return 1;

}


// Searches for a specific piece of data in a linked list, returns the node if its found, otherwise NULL.
struct cdsc_linkedlist_node *cdsc_linkedlist_find(struct cdsc_linkedlist
						  *list, void *key) {
    struct cdsc_linkedlist_node *current = list->head;
    if (list->head == NULL) {
	return NULL;
    }
    while (current->data != key) {
	if (current->next == NULL) {
	    return NULL;
	} else {
	    current = current->next;
	}
    }
    return current;
}

// Searches for a specific piece of data in a linked list, returns the index if its found, otherwise NULL.
int cdsc_linkedlist_findindex(struct cdsc_linkedlist *list, void *key) {
    struct cdsc_linkedlist_node *current = list->head;
    int i = 0;
    if (list->head == NULL) {
	return -1;
    }
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

int is_empty(struct cdsc_linkedlist *list) {
    return list->head == NULL;
}

// Reverse a linked list
int cdsc_linkedlist_reverse(struct cdsc_linkedlist *list) {
    struct cdsc_linkedlist_node *prev = NULL;
    struct cdsc_linkedlist_node *formerhead = list->head;
    list->tail = formerhead;
    struct cdsc_linkedlist_node *current = list->head;
    struct cdsc_linkedlist_node *next;

    while (current != NULL) {
	next = current->next;
	current->next = prev;
	prev = current;
	current = next;
    }
    list->head = prev;
    return 1;
}

// Remove a node if it contains a specific piece of data
// Removes every node with that piece of data
int cdsc_linkedlist_remove_node_if_contains(struct cdsc_linkedlist *list,
					    void *key) {
    int i;
    struct cdsc_linkedlist_node *cur = list->head;
    struct cdsc_linkedlist_node *prev = NULL;
    for (i = 0; i < list->size; i++) {
	if (cur->data == key) {
	    if (cur == list->head) {
		cdsc_linkedlist_pophead(list);
	    } else {
		prev->next = cur->next;
		free(cur);
	    }
	} else {;
	    prev = cur;
	    cur = cur->next;
	}

    }
    cur = NULL;
    return 1;
}

// Appends a premade node struct to a linked list.
int cdsc_linkedlist_appendnode(struct cdsc_linkedlist *list, struct cdsc_linkedlist_node
			       *cdsc_linkedlist_node) {
    if (list->size == 0) {
	list->head = cdsc_linkedlist_node;
	list->tail = cdsc_linkedlist_node;
    } else {
	list->tail->next = cdsc_linkedlist_node;
	list->tail = cdsc_linkedlist_node;
    }
    return 1;

}

// Merge two linked lists at the first linked list's tail by changing the destination list's tail pointer  and zeroing the input list
int cdsc_linkedlist_fastconcat(struct cdsc_linkedlist *list1,
			       struct cdsc_linkedlist *list2) {
    list1->tail->next = list2->head;
    list1->size += list2->size;
    list2->tail = list2->tail;
    list2->head = NULL;
    list2->tail = NULL;
    list2->size = 0;
    return 1;
}

// Concat two lists by copying and appending the data of list2 to list1.
int cdsc_linkedlist_concat(struct cdsc_linkedlist *list1,
			   struct cdsc_linkedlist *list2) {
    struct cdsc_linkedlist_node *cur = list2->head;
    while (cur != NULL) {
	cdsc_linkedlist_append(list1, cur->data);
	cur = cur->next;
    }
    return 1;
}

// Merge two lists by copying and appending the data of list2 and list1 to a new one.
struct cdsc_linkedlist *cdsc_linkedlist_merge(struct cdsc_linkedlist
					      *list1, struct cdsc_linkedlist
					      *list2) {
    struct cdsc_linkedlist *dest = cdsc_linkedlist_make_ll();
    struct cdsc_linkedlist_node *cur = list1->head;
    while (cur != NULL) {
	cdsc_linkedlist_append(dest, cur->data);
	cur = cur->next;

    }
    cur = list2->head;
    while (cur != NULL) {
	cdsc_linkedlist_append(dest, cur->data);
	cur = cur->next;

    }

    return dest;

}


// Check if a linked list contains a piece of data, returns true if so, otherwise false.
int cdsc_linkedlist_contains(struct cdsc_linkedlist *list, void *data) {
    int i;
    struct cdsc_linkedlist_node *cur = list->head;
    for (i = 0; i < list->size; i++) {
	if (cur->data == data) {
	    return 1;
	} else {;
	    cur = cur->next;
	}

    }
    return 0;
}

// Run a function for each member of a linkedlist.
int cdsc_linkedlist_foreach(struct cdsc_linkedlist *list,
			    void (*action)(), void *param) {
    struct cdsc_linkedlist_node *cur = list->head;
    while (cur != NULL) {
	action(cur, param);
	cur = cur->next;
    }
    return 1;
}
