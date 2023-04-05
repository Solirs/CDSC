#include<stdio.h>
#include "queue.h"

int main(){

    struct cdsc_queue *queue = cdsc_queue_make_queue();
    cdsc_queue_enqueue(queue, "Hello World");

    printf("%s\n", cdsc_queue_getrear(queue));
    printf("%s\n", cdsc_queue_getfront(queue));
    
    cdsc_queue_nuke(queue);
    free(queue);

}
