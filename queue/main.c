#include<stdio.h>
#include "queue.h"

int main(){

    struct queue *queue = make_queue();
    enqueue(queue, "Hello World");

    printf("%s\n", getrear(queue));
    printf("%s\n", getfront(queue));

}