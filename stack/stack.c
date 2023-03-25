#include"stack.h"


struct cdsc_stack* cdsc_stack_make_stack(){
    struct cdsc_stack* st = malloc(sizeof(struct cdsc_stack));
    st->size = 0;
    st->content = make_ll();
    return st;
}

void cdsc_stack_push(struct cdsc_stack* stack, void* data){
    inserthead(stack->content, data);
    stack->size++;

}

void* cdsc_stack_pop(struct cdsc_stack* stack){
    void* ret = pophead(stack->content);
    stack->size--;
    return ret;
}
void* cdsc_stack_peek(struct cdsc_stack* stack){
    void* ret = getindexfromhead(stack->content, 0);
    return ret;
}

void cdsc_stack_nuke(struct cdsc_stack* stack){
	nuke(stack->content);
	free(stack->content);
	stack->size = 0;
}
