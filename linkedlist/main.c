#include<stdio.h>
#include <string.h>
#include "linkedlist.h"


int main() {
    // Test driver code
    struct cdsc_linkedlist *list = cdsc_linkedlist_make_ll();
    cdsc_linkedlist_append(list, 9);
    cdsc_linkedlist_append(list, 5);
    cdsc_linkedlist_append(list, 10);
    cdsc_linkedlist_append(list, 5);
    cdsc_linkedlist_append(list, 7);
    cdsc_linkedlist_append(list, 5);
    cdsc_linkedlist_append(list, 2);
    cdsc_linkedlist_append(list, 4);
    cdsc_linkedlist_append(list, 5);
    cdsc_linkedlist_append(list, 1);
    cdsc_linkedlist_append(list, 5);





    cdsc_linkedlist_qsort(list, 0, list->size - 1);

    cdsc_linkedlist_foreach(list, printlist, NULL);


    /*struct cdsc_linkedlist *Nodelist2 = cdsc_linkedlist_make_ll();

       //struct LinkedList Nodelist2 = *make_ll();
       char *c = malloc(6 * sizeof(char));
       strcpy(c, "Hello");
       c = realloc(c, sizeof(c) + 1);
       int *i = (int *) malloc(sizeof(int));
       *i = 11892;
       cdsc_linkedlist_inserttail(Nodelist, i);
       cdsc_linkedlist_inserttail(Nodelist, c);
       cdsc_linkedlist_inserttail(Nodelist2, "ABC");

       struct cdsc_linkedlist *Nodelist3 =
       cdsc_linkedlist_merge(Nodelist, Nodelist2);

       cdsc_linkedlist_inserthead(Nodelist, "Bye world!");
       //mergeattail( Nodelist,  Nodelist2);
       cdsc_linkedlist_reverse(Nodelist);
       //remove_node_if_contains( Nodelist, "ABC");
       printf("Data: %s\n", cdsc_linkedlist_getindexfromhead(Nodelist, 0));
       printf("Contains: %d\n", cdsc_linkedlist_contains(Nodelist, c));



       free(c);
       free(i);
       cdsc_linkedlist_nuke(Nodelist);
       cdsc_linkedlist_nuke(Nodelist2);
       cdsc_linkedlist_nuke(Nodelist3);


       free(Nodelist2);
       free(Nodelist3); */
    free(list);


    return 0;
}
