#ifndef STACK_
#define STACK_

#include<stdlib.h>
#include"../doublylinkedlist/doublylinkedlist.h"


struct stack{
    int size;
    struct DoubleLinkedList *content;
};

struct stack* make_stack();
void push(struct stack* stack, void* data);
void* pop(struct stack* stack);
void* peek(struct stack* stack);

#endif