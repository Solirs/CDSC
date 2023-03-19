#include "queue.h"



struct queue *make_queue(){
    struct queue* ret = malloc(sizeof(struct queue));
    ret->capacity = 0; // Capacity to 0 = infinite
    ret->size = 0;
    ret->list = make_dll();
    return ret;
}  

void enqueue(struct queue *queue, void* data){
    if (queue->size == queue->capacity && queue->capacity != 0){
        return NULL;
    }else{
        inserttail(queue->list, data);
        queue->size++;
    }
}

void* dequeue(struct queue *queue){
    if (QUEUE_EMPTY){
        return NULL;
    }else{
        void* data = getindexfromhead(queue->list, 0);
        pophead(queue->list);
        return data;
    }

}

void queue_nuke(struct queue* queue){
    if (QUEUE_EMPTY){
        return NULL;
    }
    nuke(queue->list);
    free(queue->list);
    queue->list = NULL;
    queue->size = 0;
}

void* getfront(struct queue *queue){
    if (QUEUE_EMPTY){
        return NULL;
    }
    void* data = getindexfromhead(queue->list, 0);
    return data;
}

void* getrear(struct queue *queue){
    if (QUEUE_EMPTY){
        return NULL;
    }
    void* data = getindexfromtail(queue->list, 0);
    return data;
}

int is_empty(struct queue *queue){
    return (queue->size == 0);
}
