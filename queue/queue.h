#ifndef QUEUE_
#define QUEUE_

#include<stdlib.h>
#include"../doublylinkedlist/doublylinkedlist.h"

#define QUEUE_EMPTY queue->size == 0
#define QUEUE_FULL queue->size == queue->capacity && queue->capacity != 0
struct cdsc_queue{
    struct DoubleLinkedList *list;
    int capacity;
    int size;
};

struct cdsc_queue *make_queue();
void cdsc_queue_enqueue(struct cdsc_queue *queue, void* data);
void* cdsc_queue_dequeue(struct cdsc_queue *queue);

void cdsc_queue_nuke(struct cdsc_queue* queue);
void* cdsc_queue_getfront(struct cdsc_queue *queue);
void* cdsc_queue_getrear(struct cdsc_queue *queue);
int cdsc_queue_is_empty(struct cdsc_queue *queue);
#endif
