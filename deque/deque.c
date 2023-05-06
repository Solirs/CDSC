#include "deque.h"


// Create and initialize a deque
struct cdsc_deque *cdsc_deque_make_deque() {
    struct cdsc_deque *ret = malloc(sizeof(struct cdsc_deque));
    ret->capacity = 0;		// Capacity to 0 = infinite
    ret->size = 0;
    ret->list = cdsc_doublylinkedlist_make_dll();
    return ret;
}

// Push to the rear of a deque
int cdsc_deque_push_back(struct cdsc_deque *queue, void *data) {
    if (queue->size == queue->capacity && queue->capacity != 0) {
	return -1;
    } else {
	cdsc_doublylinkedlist_inserttail(queue->list, data);
	queue->size++;
	return 1;
    }
}

// Push to the front of a deque
int cdsc_deque_push_front(struct cdsc_deque *queue, void *data) {
    if (queue->size == queue->capacity && queue->capacity != 0) {

	return -1;
    } else {
	cdsc_doublylinkedlist_inserthead(queue->list, data);
	queue->size++;
	return 1;
    }
}

// Pop the front of a deque, returns popped data
void *cdsc_deque_pop_front(struct cdsc_deque *queue) {
    if (QUEUE_EMPTY) {
	return NULL;
    } else {
	return cdsc_doublylinkedlist_pophead(queue->list);;
    }

}

// Pop the head of a deque, returns popped data
void *cdsc_deque_pop_back(struct cdsc_deque *queue) {
    if (QUEUE_EMPTY) {
	return NULL;
    } else {
	return cdsc_doublylinkedlist_poptail(queue->list);;
    }

}

// Free a deque's contents and zero it
int cdsc_deque_nuke(struct cdsc_deque *queue) {
    if (QUEUE_EMPTY) {
	return 0;
    }
    cdsc_doublylinkedlist_nuke(queue->list);
    free(queue->list);
    queue->list = NULL;
    queue->size = 0;
    return 1;
}

// Look at the front of a deque without changing anything
void *cdsc_deque_peek_front(struct cdsc_deque *queue) {
    if (QUEUE_EMPTY) {
	return NULL;
    }
    void *data = cdsc_doublylinkedlist_getindexfromhead(queue->list, 0);
    return data;
}

// Look at the read of a deque without changing anything
void *cdsc_deque_peek_rear(struct cdsc_deque *queue) {
    if (QUEUE_EMPTY) {
	return NULL;
    }
    void *data = cdsc_doublylinkedlist_getindexfromtail(queue->list, 0);
    return data;
}

// For those who like functions or other miscanellous purposes
int cdsc_deque_is_empty(struct cdsc_deque *queue) {
    return (QUEUE_EMPTY);
}
