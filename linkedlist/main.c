#include<stdio.h>
#include <string.h>
#include "linkedlist.h"


int main(){
    // Test driver code
    struct LinkedList Nodelist = *make_ll();
    char* c = malloc(6 * sizeof(char));
    strcpy(c, "Hello");
    c = realloc(c, sizeof(c) + 1);
    int* i = (int*)malloc(sizeof(int));
    *i = 11892;
    inserttail(&Nodelist, i);
    inserttail(&Nodelist, c);
    inserttail(&Nodelist, "ABC");

    inserthead(&Nodelist, "Bye world!");
    reverse(&Nodelist);

    printf("Data: %s\n", getindexfromhead(&Nodelist, 0));


    /*pophead(&Nodelist);

    printf("Data: %s\n", find(&Nodelist, "ABC")->data);   
    printf("Data: %d\n", *(int*)getindexfromhead(&Nodelist, 1));

    printf("Length: %d\n", Nodelist.size);*/

    /*
    Expected output:
        Data: ABC
        Data: 11892
        Length: 3

    */

    //free(c);
    //free(i);
    nuke(&Nodelist);

    return 0;
}