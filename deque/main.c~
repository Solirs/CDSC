#include<stdio.h>
#include "deque.h"

int main() {

    struct cdsc_deque *deque = cdsc_deque_make_deque();
    cdsc_deque_push_back(deque, "Hello world");
    cdsc_deque_push_front(deque, "Goodbye world");

    printf("%s\n", cdsc_deque_pop_front(deque));
    printf("%s\n", cdsc_deque_pop_front(deque));
    cdsc_deque_nuke(deque);
    free(deque);

}
