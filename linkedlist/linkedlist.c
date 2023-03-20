#include "linkedlist.h"

// Add new node at the head, replacing it.
void inserthead(struct LinkedList *list, void* data){
    struct node* ins = malloc(sizeof(struct node));
    ins->data = data;
    if (list->size == 0){
        ins->next = NULL;

        list->tail = ins;
    }else{
        ins->next = list->head;
    }
    list->head = ins;
    list->size++;
}

// Add new node at the tail, replacing it.
void inserttail(struct LinkedList *list, void* data){
    struct node* ins = malloc(sizeof(struct node));
    ins->data = data;
    ins->next = NULL;
    if (list->size == 0){
        list->head = ins;

    }else{
        list->tail->next = ins;
    }
    list->tail = ins;
    list->size++;


}

// Remove the list's tail replacing it by the node before it
void* poptail(struct LinkedList *list){
    struct node *newtail;
    int i;
    for (i = 0;i<list->size; i++){
        newtail = newtail->next;
    }
    void* ret = list->tail->data;
    //We need to free the node struct that was allocated in inserttail or inserthead
    free(list->tail);
    list->tail = NULL;
    if (list->size > 1){
        newtail->next = NULL;
        list->tail = newtail;
    }
    list->size--;
    return ret;

}
// Remove the list's head replacing it with the next node
void* pophead(struct LinkedList *list){
    struct node *newhead = list->head->next;
    void* ret = list->head->data;
    //We need to free the node struct that was allocated in inserttail or inserthead
    free(list->head);
    list->head = NULL;

    if (list->size > 1){
        list->head = newhead;
    }
    list->size--;
    return ret;

}

// Get data by index starting at the heazd
void* getindexfromhead(struct LinkedList *list, int index){

    int i;
    struct node* cur = list->head;

    for (i = 0; i<index; i++){
        cur = cur->next;
        if (cur == NULL){
            return NULL;
        }
    }

    return cur->data;
}

// Get data by index starting at the tail
void* getindexfromtail(struct LinkedList *list, int index){
    int i;
    struct node* cur = list->head;
    if (index == 0){
        return list->tail->data;
    }
    else{
        index = (list->size - index - 1);
        for (i = 0; i<index; i++){
            cur = cur->next;
            if (cur == NULL){
                return NULL;
            }
        }

        return cur->data;

    }


}

// Create and init double linked list
struct LinkedList *make_ll(){
    struct LinkedList *ret = malloc(sizeof(struct LinkedList));
    ret->size = 0;
    ret->head = NULL;
    ret->tail = NULL;
    return ret;
}

// Completely wipe a doubly linked list
void nuke(struct LinkedList *list){
    struct node *cur;
    if (list->size == 0){
        return NULL;
    }
    if (list->head == list->tail){
        free(list->head);
        list->head = NULL;
    }else{
        cur = list->head;
        while(1){
            struct node *nxt = cur->next;
            if (cur == list->tail){
                free(cur);
                cur = NULL;
                break;
            } else{
                free(cur);
                cur = nxt;
            }

        }
    }  
    list->size = 0;

}

// Sets the data of a DoublyLinkedList's certain index, starting from the head.
void setdata(struct LinkedList *list, void* data, int index){
    int i;
    struct node* cur = list->head;
    for (i = 0; i<index; i++){
        cur = cur->next;
        if (cur == NULL){
            return NULL;
        }
    }
        cur->data = data;

}

struct node* find(struct LinkedList *list, void* key) {
	struct node* current = list->head;
	if (list->head == NULL) {
		return NULL;
	}
	while (current->data != key){
		if (current->next == NULL) {
			return NULL;
		}
		else {
			current = current->next;
		}
	}
	return current;
}

int findindex(struct LinkedList *list, void* key) {
	struct node* current = list->head;
    int i = 0;
	if (list->head == NULL) {
		return NULL;
	}
	while (current->data != key){
		if (current->next == NULL) {
			return NULL;
		}
		else {
			current = current->next;
            i++;
		}
	}
	return i;
}

bool is_empty(struct LinkedList *list) {
	return list->head == NULL;
}
void reverse(struct LinkedList *list) { 
	struct node* prev = NULL;
    struct node* formerhead = list->head;
    list->tail = formerhead;
	struct node* current = list->head;
	struct node* next;
 
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	list->head = prev;
}

void remove_node_if_contains(struct LinkedList *list, void* key){
    int i;
    struct node* cur = list->head;
    struct node* prev = NULL;
    for (i = 0; i<list->size; i++){
        if (cur->data == key){
            if (cur == list->head){
                pophead(list);
            }else{
                prev->next = cur->next;
                free(cur);
            }
        }else{;
            prev = cur;
            cur = cur->next;
        }

    }
    cur = NULL;
}

void appendnode(struct LinkedList *list, struct node* node){
    if (list->size == 0){
        list->head = node;
        list->tail = node;
    }else{
        list->tail->next = node;
        list->tail = node;
    }

}

void cdsc_linkedlist_merge(struct LinkedList *list1, struct LinkedList *list2){
    list1->tail->next = list2->head;
    list1->size += list2->size;
}

bool contains(struct LinkedList* list, void* data){
    int i;
    struct node* cur = list->head;
    for (i = 0; i<list->size; i++){
        if (cur->data == data){
			return true;
        }else{;
            cur = cur->next;
        }

    }
    return false;
}
