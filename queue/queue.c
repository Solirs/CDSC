#include "queue.h"



struct cdsc_queue *cdsc_queue_make_queue(){
    struct cdsc_queue* ret = malloc(sizeof(struct cdsc_queue));
    ret->capacity = 0; // Capacity to 0 = infinite
    ret->size = 0;
    ret->list = make_ll();
    return ret;
}  

void cdsc_queue_enqueue(struct cdsc_queue *queue, void* data){
    if (queue->size == queue->capacity && queue->capacity != 0){
        return NULL;
    }else{
        inserttail(queue->list, data);
        queue->size++;
    }
}

void* cdsc_queue_dequeue(struct cdsc_queue *queue){
    if (QUEUE_EMPTY){
        return NULL;
    }else{
        void* data = getindexfromhead(queue->list, 0);
        pophead(queue->list);
        return data;
    }

}

void cdsc_queue_nuke(struct cdsc_queue* queue){
    if (QUEUE_EMPTY){
        return NULL;
    }
    nuke(queue->list);
    free(queue->list);
    queue->list = NULL;
    queue->size = 0;
}

void* cdsc_queue_getfront(struct cdsc_queue *queue){
    if (QUEUE_EMPTY){
        return NULL;
    }
    void* data = getindexfromhead(queue->list, 0);
    return data;
}

void* cdsc_queue_getrear(struct cdsc_queue *queue){
    if (QUEUE_EMPTY){
        return NULL;
    }
    void* data = getindexfromtail(queue->list, 0);
    return data;
}

int cdsc_queue_is_empty(struct cdsc_queue *queue){
    return (queue->size == 0);
}
