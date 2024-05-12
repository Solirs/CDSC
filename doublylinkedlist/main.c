#include<stdio.h>
#include <string.h>
#include "doublylinkedlist.h"


typedef struct canditate {
    int age;
    float average;
    char *name;
} candidate;

void printlist(struct cdsc_doublylinkedlist_node *nd) {
    printf("L: %d\n", (int) nd->data);
}

int compaverage(candidate *cd1, candidate *cd2) {
    // Negative if second element is bigger
    // Positive if first is bigger
    // Otherwise 0
    if (cd1->average > cd2->average) {
	return 1;
    } else if (cd1->average < cd2->average) {
	return -1;
    }
    return 0;

}



int main() {

    candidate one;
    one.age = 24;
    one.average = 17.56;
    one.name = "Maria";

    candidate two;
    two.age = 30;
    two.average = 13.43;
    two.name = "Bob";

    candidate three;
    three.age = 1;
    three.average = 19.75;
    three.name = "Chuck";

    // Test driver code
    struct cdsc_doublylinkedlist *list = cdsc_doublylinkedlist_make_dll();
    int i = 0;
    for (i = 0; i < 10; i++) {
	cdsc_doublylinkedlist_append(list, 16);

    }

    
    cdsc_doublylinkedlist_insert(list, 10, 10);
    cdsc_doublylinkedlist_insert(list, 10, 10);
    cdsc_doublylinkedlist_insert(list, 10, 10);

    printf("%d\n", list->size);

	cdsc_doublylinkedlist_remove(list, 10);


    //cdsc_doublylinkedlist_qsort(list, NULL);

    cdsc_doublylinkedlist_foreach(list, printlist, NULL);
    cdsc_doublylinkedlist_nuke(list);
    free(list);

    return 0;
}
