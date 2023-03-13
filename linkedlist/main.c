#include<stdio.h>
#include <string.h>
#include "linkedlist.h"


int main(){
    // Test driver code
    struct LinkedList *Nodelist = make_ll();
    //struct LinkedList Nodelist2 = *make_ll();
    char* c = malloc(6 * sizeof(char));
    strcpy(c, "Hello");
    c = realloc(c, sizeof(c) + 1);
    int* i = (int*)malloc(sizeof(int));
    *i = 11892;
    inserttail( Nodelist, i);
    inserttail( Nodelist, c);
    inserttail( Nodelist, "ABC");

    inserthead( Nodelist, "Bye world!");
    //mergeattail( Nodelist,  Nodelist2);
    reverse( Nodelist);
    //remove_node_if_contains( Nodelist, "ABC");
    printf("Data: %s\n", getindexfromhead( Nodelist, 0));



    free(c);
    free(i);
    nuke( Nodelist);
    free(Nodelist);
    //nuke( Nodelist2);

    return 0;
}