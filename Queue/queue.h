#ifndef QUEUE_
#define QUEUE_

#include<stdlib.h>
#include"../doublylinkedlist/doublylinkedlist.h"



struct queue{
    struct DoubleLinkedList list;
    int capacity;
    int size;
};

struct queue make_queue();
void enqueue(struct queue *queue, void* data);
void* dequeue(struct queue *queue);

#endif