#include "deque.h"



struct cdsc_deque *cdsc_deque_make_deque(){
    struct cdsc_deque* ret = malloc(sizeof(struct cdsc_deque));
    ret->capacity = 0; // Capacity to 0 = infinite
    ret->size = 0;
    ret->list = make_ll();
    return ret;
}  

void cdsc_deque_push_back(struct cdsc_deque *queue, void* data){
    if (queue->size == queue->capacity && queue->capacity != 0){
        return NULL;
    }else{
        cdsc_doublylinkedlist_inserttail(queue->list, data);
        queue->size++;
    }
}

void cdsc_deque_push_front(struct cdsc_deque *queue, void* data){
    if (queue->size == queue->capacity && queue->capacity != 0){

        return NULL;
    }else{
        cdsc_doublylinkedlist_inserthead(queue->list, data);
        queue->size++;
    }
}

void* cdsc_deque_pop_front(struct cdsc_deque *queue){
    if (QUEUE_EMPTY){
        return NULL;
    }else{
        return cdsc_doublylinkedlist_pophead(queue->list);;
    }

}

void* cdsc_deque_pop_back(struct cdsc_deque *queue){
    if (QUEUE_EMPTY){
        return NULL;
    }else{
        return cdsc_doublylinkedlist_poptail(queue->list);;
    }

}

void cdsc_deque_nuke(struct cdsc_deque* queue){
    if (QUEUE_EMPTY){
        return NULL;
    }
    cdsc_doublylinkedlist_nuke(queue->list);
    free(queue->list);
    queue->list = NULL;
    queue->size = 0;
}

void* cdsc_deque_peek_front(struct cdsc_deque *queue){
    if (QUEUE_EMPTY){
        return NULL;
    }
    void* data = cdsc_doublylinkedlist_getindexfromhead(queue->list, 0);
    return data;
}

void* cdsc_deque_peek_rear(struct cdsc_deque *queue){
    if (QUEUE_EMPTY){
        return NULL;
    }
    void* data = cdsc_doublylinkedlist_getindexfromtail(queue->list, 0);
    return data;
}

int cdsc_deque_is_empty(struct cdsc_deque *queue){
    return (queue->size == 0);
}
