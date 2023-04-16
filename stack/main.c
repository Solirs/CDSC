#include<stdio.h>
#include "stack.h"

int main() {
    struct cdsc_stack *stack1 = cdsc_stack_make_stack();
    struct cdsc_stack *stack2 = cdsc_stack_make_stack();

    cdsc_stack_push(stack2, "Hello Worldie!");
    cdsc_stack_push(stack2, "Bye Worldie!");
    cdsc_stack_push(stack1, "Hello Worldie!");
    cdsc_stack_push(stack1, "Hello Worldie!");

    struct cdsc_stack *stack = cdsc_stack_merge(stack1, stack2);

    printf("%s\n", cdsc_stack_pop(stack));
    printf("%s\n", cdsc_stack_pop(stack));
    printf("%s\n", cdsc_stack_pop(stack));
    printf("%s\n", cdsc_stack_pop(stack));

    printf("%d\n", stack->size);

    cdsc_stack_nuke(stack);
    cdsc_stack_nuke(stack1);
    cdsc_stack_nuke(stack2);
    free(stack1);
    free(stack2);
    free(stack);
    return 0;

}
