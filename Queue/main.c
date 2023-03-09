#include<stdio.h>
#include "queue.h"

int main(){

    struct queue queue;
    enqueue(&queue, "Hello World");
    enqueue(&queue, "Bye World");

    printf("%s\n", dequeue(&queue));
    printf("%s\n", dequeue(&queue));

}