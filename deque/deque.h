#ifndef DEQUEUE_
#define DEQUEUE_

#include<stdlib.h>
#include"../linkedlist/linkedlist.h"

#define QUEUE_EMPTY queue->size == 0

struct cdsc_deque{
    struct LinkedList *list;
    int capacity;
    int size;
};

struct cdsc_deque *make_deque();
void cdsc_deque_push_back(struct cdsc_deque *queue, void* data);
void* cdsc_deque_pop_front(struct cdsc_deque *queue);

void cdsc_deque_nuke(struct cdsc_deque* queue);
void* cdsc_deque_peek_front(struct cdsc_deque *queue);
void* cdsc_deque_peek_rear(struct cdsc_deque *queue);
#endif
