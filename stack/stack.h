#ifndef STACK_
#define STACK_

#include<stdlib.h>
#include"../linkedlist/linkedlist.h"


struct cdsc_stack{
    int size;
    struct LinkedList *content;
};

struct cdsc_stack* cdsc_stack_make_stack();
void cdsc_stack_push(struct cdsc_stack* cdsc_stack, void* data);
void* cdsc_stack_pop(struct cdsc_stack* cdsc_stack);
void* cdsc_stack_peek(struct cdsc_stack* cdsc_stack);

#endif
