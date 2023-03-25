#include<stdio.h>
#include "stack.h"

int main(){
    struct cdsc_stack* stack = cdsc_stack_make_stack();
    cdsc_stack_push(stack, "Hello Worldie!");
    cdsc_stack_push(stack, "Bye Worldie!");
    cdsc_stack_push(stack, "Hello Worldie!");
    cdsc_stack_push(stack, "Hello Worldie!");

    printf("%s\n",cdsc_stack_pop(stack));
    printf("%s\n",cdsc_stack_pop(stack));
    printf("%s\n",cdsc_stack_pop(stack));
    printf("%s\n",cdsc_stack_pop(stack));

    printf("%d\n", stack->size);
	
	cdsc_stack_nuke(stack);
	free(stack);
    return 0;

}
