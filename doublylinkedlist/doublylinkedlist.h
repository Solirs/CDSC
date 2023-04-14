#ifndef DOUBLE_LL_
#define DOUBLE_LL_

#include <stdlib.h>
#include <stdbool.h>

#define cdsc_doublylinkedlist_prepend(list, data) inserthead(list, data)
#define cdsc_doublylinkedlist_append(list, data) inserttail(list, data)

struct cdsc_doublylinkedlist_node{
    struct cdsc_doublylinkedlist_node* previous;
    void* data;
    struct cdsc_doublylinkedlist_node* next;
};

struct cdsc_doublylinkedlist{
    int size;
    struct cdsc_doublylinkedlist_node* head;
    struct cdsc_doublylinkedlist_node* tail;


};

void cdsc_doublylinkedlist_inserthead(struct cdsc_doublylinkedlist *list, void* data);
void cdsc_doublylinkedlist_inserttail(struct cdsc_doublylinkedlist *list, void* data);

void* cdsc_doublylinkedlist_poptail(struct cdsc_doublylinkedlist *list);
void* cdsc_doublylinkedlist_pophead(struct cdsc_doublylinkedlist *list);

void* cdsc_doublylinkedlist_getindexfromhead(struct cdsc_doublylinkedlist *list, int index);
void* cdsc_doublylinkedlist_getindexfromtail(struct cdsc_doublylinkedlist *list, int index);

struct cdsc_doublylinkedlist *cdsc_doublylinkedlist_make_dll();
void cdsc_doublylinkedlist_nuke(struct cdsc_doublylinkedlist *list);
void cdsc_doublylinkedlist_setdata(struct cdsc_doublylinkedlist *list, void* data, int index);

void doublelinkedlist_zero(struct cdsc_doublylinkedlist *ll);
void cdsc_doublylinkedlist_reverse(struct cdsc_doublylinkedlist *list);
void cdsc_doublylinkedlist_merge(struct cdsc_doublylinkedlist *list1, struct cdsc_doublylinkedlist *list2);
void cdsc_doublylinkedlist_appendnode(struct cdsc_doublylinkedlist *list, struct cdsc_doublylinkedlist_node* node);
bool cdsc_doublylinkedlist_contains(struct cdsc_doublylinkedlist* list, void* data);
struct cdsc_doublylinkedlist_node* cdsc_doublylinkedlist_find(struct cdsc_doublylinkedlist *list, void* key);
int cdsc_doublylinkedlist_findindex(struct cdsc_doublylinkedlist *list, void* key);
void cdsc_doublylinkedlist_foreach(struct cdsc_doublylinkedlist *list, void (*action)(), void* param);

#endif
