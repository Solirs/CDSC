#include "queue.h"

struct queue make_queue(){
    struct queue ret;
    ret.capacity = 0; // Capacity to 0 = infinite
    ret.size = 0;
    ret.list = make_dll();

    return ret;
}  

void enqueue(struct queue *queue, void* data){
    inserttail(&queue->list, data);
}

void* dequeue(struct queue *queue){
    void* data = getindexfromhead(&queue->list, 0);
    pophead(&queue->list);
    return data;
}