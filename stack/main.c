#include<stdio.h>
#include "stack.h"

int main(){
    struct stack* stack = make_stack();
    push(stack, "Hello Worldie!");
    push(stack, "Bye Worldie!");
    push(stack, "Hello Worldie!");
    push(stack, "Hello Worldie!");

    printf("%s\n",pop(stack));
    printf("%s\n",pop(stack));
    printf("%s\n",peek(stack));
    printf("%d\n", stack->size);

    return 0;

}