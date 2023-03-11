#include"stack.h"


struct stack* make_stack(){
    struct stack* st = malloc(sizeof(struct stack));
    st->size = 0;
    st->content = malloc(sizeof(struct DoubleLinkedList));
    return st;
}

void push(struct stack* stack, void* data){
    inserthead(stack->content, data);
    stack->size++;

}

void* pop(struct stack* stack){
    void* ret = pophead(stack->content);
    stack->size--;
    return ret;
}
void* peek(struct stack* stack){
    void* ret = getindexfromhead(stack->content, 0);
    return ret;
}