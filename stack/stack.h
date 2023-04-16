#ifndef STACK_
#define STACK_

#include<stdlib.h>
#include"../linkedlist/linkedlist.h"


struct cdsc_stack{
    int size;
    struct cdsc_linkedlist *content;
};

struct cdsc_stack* cdsc_stack_make_stack();
void cdsc_stack_push(struct cdsc_stack* cdsc_stack, void* data);
void* cdsc_stack_pop(struct cdsc_stack* cdsc_stack);
void* cdsc_stack_peek(struct cdsc_stack* cdsc_stack);
void cdsc_stack_nuke(struct cdsc_stack* stack);
struct cdsc_stack* cdsc_stack_merge(struct cdsc_stack* stack1, struct cdsc_stack* stack2);
#endif
