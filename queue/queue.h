#ifndef QUEUE_
#define QUEUE_

#include<stdlib.h>
#include"../doublylinkedlist/doublylinkedlist.h"

#define QUEUE_EMPTY queue->size == 0

struct queue{
    struct DoubleLinkedList *list;
    int capacity;
    int size;
};

struct queue *make_queue();
void enqueue(struct queue *queue, void* data);
void* dequeue(struct queue *queue);

void queue_nuke(struct queue* queue);
void* getfront(struct queue *queue);
void* getrear(struct queue *queue);
int cdsc_queue_is_empty(struct queue *queue);
#endif
