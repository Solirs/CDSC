#include<stdio.h>
#include <string.h>
#include "doublylinkedlist.h"


int main(){
    // Test driver code
    struct DoubleLinkedList Nodelist = *make_dll();
    char* c = malloc(6 * sizeof(char));
    strcpy(c, "Hello");
    c = realloc(c, sizeof(c) + 1);
    int* i = (int*)malloc(sizeof(int));
    *i = 11892;
    inserttail(&Nodelist, "ABC");
    inserttail(&Nodelist, i);
    inserttail(&Nodelist, c);
    inserthead(&Nodelist, "Bye world!");
    

    pophead(&Nodelist);

    printf("Data: %s\n", getindexfromhead(&Nodelist, 0));
    printf("Data: %d\n", *(int*)getindexfromhead(&Nodelist, 1));

    printf("Length: %d\n", Nodelist.size);

    /*
    Expected output:
        Data: ABC
        Data: 11892
        Length: 3

    */

    free(c);
    free(i);
    nuke(&Nodelist);

    return 0;
}