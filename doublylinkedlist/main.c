#include<stdio.h>
#include <string.h>
#include "doublylinkedlist.h"


int main(){
    // Test driver code
    struct cdsc_doublylinkedlist *Nodelist = cdsc_doublylinkedlist_make_dll();
    char* c = malloc(6 * sizeof(char));
    strcpy(c, "Hello");
    c = realloc(c, sizeof(c) + 1);
    int* i = (int*)malloc(sizeof(int));
    *i = 11892;
    cdsc_doublylinkedlist_inserttail(  Nodelist, "ABC");
    cdsc_doublylinkedlist_inserttail(  Nodelist, i);
    cdsc_doublylinkedlist_inserttail(  Nodelist, c);
    cdsc_doublylinkedlist_inserthead(  Nodelist, "Bye world!");
    

    cdsc_doublylinkedlist_pophead(  Nodelist);

    printf("Data: %s\n", cdsc_doublylinkedlist_getindexfromhead(  Nodelist, 0));
    printf("Data: %d\n", *(int*)cdsc_doublylinkedlist_getindexfromhead(  Nodelist, 1));

    printf("Length: %d\n", Nodelist->size);

    /*
    Expected output:
        Data: ABC
        Data: 11892
        Length: 3

    */

    free(c);
    free(i);
    cdsc_doublylinkedlist_nuke(  Nodelist);
    free(Nodelist);
    

    return 0;
}
