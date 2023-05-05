#include "queue.h"



struct cdsc_queue *cdsc_queue_make_queue() {
    struct cdsc_queue *ret = malloc(sizeof(struct cdsc_queue));
    ret->capacity = 0;		// Capacity to 0 = infinite
    ret->size = 0;
    ret->list = cdsc_doublylinkedlist_make_dll();
    return ret;
}

void cdsc_queue_enqueue(struct cdsc_queue *queue, void *data) {
    if (queue->size == queue->capacity && queue->capacity != 0) {
	return NULL;
    } else {
	cdsc_doublylinkedlist_inserttail(queue->list, data);
	queue->size++;
    }
}

void *cdsc_queue_dequeue(struct cdsc_queue *queue) {
    if (QUEUE_EMPTY) {
	return NULL;
    } else {
	void *data = cdsc_doublylinkedlist_getindexfromhead(queue->list, 0);
	cdsc_doublylinkedlist_pophead(queue->list);
	return data;
    }

}

void cdsc_queue_nuke(struct cdsc_queue *queue) {
    if (QUEUE_EMPTY) {
	return NULL;
    }
    cdsc_doublylinkedlist_nuke(queue->list);
    free(queue->list);
    queue->list = NULL;
    queue->size = 0;
}

void *cdsc_queue_getfront(struct cdsc_queue *queue) {
    if (QUEUE_EMPTY) {
	return NULL;
    }
    void *data = cdsc_doublylinkedlist_getindexfromhead(queue->list, 0);
    return data;
}

void *cdsc_queue_getrear(struct cdsc_queue *queue) {
    if (QUEUE_EMPTY) {
	return NULL;
    }
    void *data = cdsc_doublylinkedlist_getindexfromtail(queue->list, 0);
    return data;
}

int cdsc_queue_is_empty(struct cdsc_queue *queue) {
    return (queue->size == 0);
}
