#include"stack.h"


struct cdsc_stack* cdsc_stack_make_stack(){
    struct cdsc_stack* st = malloc(sizeof(struct cdsc_stack));
    st->size = 0;
    st->content = cdsc_linkedlist_make_ll();
    return st;
}

void cdsc_stack_push(struct cdsc_stack* stack, void* data){
    cdsc_linkedlist_inserthead(stack->content, data);
    stack->size++;

}

void* cdsc_stack_pop(struct cdsc_stack* stack){
    void* ret = cdsc_linkedlist_pophead(stack->content);
    stack->size--;
    return ret;
}
void* cdsc_stack_peek(struct cdsc_stack* stack){
    void* ret = cdsc_linkedlist_getindexfromhead(stack->content, 0);
    return ret;
}

void cdsc_stack_nuke(struct cdsc_stack* stack){
	cdsc_linkedlist_nuke(stack->content);
	free(stack->content);
	stack->size = 0;
}
