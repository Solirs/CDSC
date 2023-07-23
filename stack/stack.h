#ifndef STACK_
#define STACK_

#include<stdlib.h>
#include"../doublylinkedlist/doublylinkedlist.h"


struct cdsc_stack{
    int size;
    struct cdsc_doublylinkedlist *content;
};

struct cdsc_stack* cdsc_stack_make_stack();
int cdsc_stack_push(struct cdsc_stack* cdsc_stack, void* data);
void* cdsc_stack_pop(struct cdsc_stack* cdsc_stack);
void* cdsc_stack_peek(struct cdsc_stack* cdsc_stack);
int cdsc_stack_nuke(struct cdsc_stack* stack);
struct cdsc_stack* cdsc_stack_merge(struct cdsc_stack* stack1, struct cdsc_stack* stack2);
#endif
