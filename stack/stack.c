#include"stack.h"


// Create and init stack
struct cdsc_stack* cdsc_stack_make_stack(){
    struct cdsc_stack* st = malloc(sizeof(struct cdsc_stack));
    st->size = 0;
    st->content = cdsc_linkedlist_make_ll();
    return st;
}

// Push to the head of stack
void cdsc_stack_push(struct cdsc_stack* stack, void* data){
    cdsc_linkedlist_inserthead(stack->content, data);
    stack->size++;

}


// Pop the head of the stack and return the popped value
void* cdsc_stack_pop(struct cdsc_stack* stack){
    void* ret = cdsc_linkedlist_pophead(stack->content);
    stack->size--;
    return ret;
}

// Return value at the head of the stack
void* cdsc_stack_peek(struct cdsc_stack* stack){
    void* ret = cdsc_linkedlist_getindexfromhead(stack->content, 0);
    return ret;
}

// Merge two stacks
struct cdsc_stack* cdsc_stack_merge(struct cdsc_stack* stack1, struct cdsc_stack* stack2){
    struct cdsc_stack* st = malloc(sizeof(struct cdsc_stack));
	st->content = cdsc_linkedlist_merge(stack1->content, stack2->content);
	st->size = st->content->size;
	return st;
}


// Zero stack
void cdsc_stack_nuke(struct cdsc_stack* stack){
	cdsc_linkedlist_nuke(stack->content);
	free(stack->content);
	
	stack->size = 0;
}
