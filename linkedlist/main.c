#include<stdio.h>
#include <string.h>
#include "linkedlist.h"


int main(){
    // Test driver code
    struct cdsc_linkedlist *Nodelist = cdsc_linkedlist_make_ll();
    //struct LinkedList Nodelist2 = *make_ll();
    char* c = malloc(6 * sizeof(char));
    strcpy(c, "Hello");
    c = realloc(c, sizeof(c) + 1);
    int* i = (int*)malloc(sizeof(int));
    *i = 11892;
    cdsc_linkedlist_inserttail( Nodelist, i);
    cdsc_linkedlist_inserttail( Nodelist, c);
    cdsc_linkedlist_inserttail( Nodelist, "ABC");

    cdsc_linkedlist_inserthead( Nodelist, "Bye world!");
    //mergeattail( Nodelist,  Nodelist2);
    cdsc_linkedlist_reverse( Nodelist);
    //remove_node_if_contains( Nodelist, "ABC");
    printf("Data: %s\n", cdsc_linkedlist_getindexfromhead( Nodelist, 0));
    printf("Contains: %d\n", cdsc_linkedlist_contains( Nodelist, c));



    free(c);
    free(i);
    cdsc_linkedlist_nuke( Nodelist);
    free(Nodelist);
    //nuke( Nodelist2);

    return 0;
}
