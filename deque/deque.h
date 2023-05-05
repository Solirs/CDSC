#ifndef DEQUEUE_
#define DEQUEUE_

#include<stdlib.h>
#include"../doublylinkedlist/doublylinkedlist.h"

#define QUEUE_EMPTY queue->size == 0


struct cdsc_deque{
    struct cdsc_doublylinkedlist *list;
    int capacity;
    int size;
};

struct cdsc_deque *cdsc_deque_make_deque();
int cdsc_deque_push_back(struct cdsc_deque *queue, void* data);
void* cdsc_deque_pop_front(struct cdsc_deque *queue);

int cdsc_deque_nuke(struct cdsc_deque* queue);
void* cdsc_deque_peek_front(struct cdsc_deque *queue);
void* cdsc_deque_peek_rear(struct cdsc_deque *queue);
int cdsc_deque_push_front(struct cdsc_deque *queue, void* data);
int cdsc_deque_push_back(struct cdsc_deque *queue, void* data);
#endif
