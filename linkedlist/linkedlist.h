#ifndef SIMPLE_LL_
#define SIMPLE_LL_

#include <stdlib.h>

#define cdsc_linkedlist_prepend(list, data) cdsc_linkedlist_inserthead(list, data)
#define cdsc_linkedlist_append(list, data) cdsc_linkedlist_inserttail(list, data)

struct cdsc_linkedlist_node{
    void* data;
    struct cdsc_linkedlist_node* next;
};

struct cdsc_linkedlist{
    int size;
    struct cdsc_linkedlist_node* head;
    struct cdsc_linkedlist_node* tail;
};

int cdsc_linkedlist_inserthead(struct cdsc_linkedlist *list, void* data);
int cdsc_linkedlist_inserttail(struct cdsc_linkedlist *list, void* data);

void* cdsc_linkedlist_poptail(struct cdsc_linkedlist *list);
void* cdsc_linkedlist_pophead(struct cdsc_linkedlist *list);

void* cdsc_linkedlist_getindexfromhead(struct cdsc_linkedlist *list, int index);
void* cdsc_linkedlist_getindexfromtail(struct cdsc_linkedlist *list, int index);

struct cdsc_linkedlist *cdsc_linkedlist_make_ll();
int cdsc_linkedlist_nuke(struct cdsc_linkedlist *list);
int cdsc_linkedlist_setdata(struct cdsc_linkedlist *list, void* data, int index);
struct cdsc_linkedlist_node* cdsc_linkedlist_find(struct cdsc_linkedlist *list, void* key);
int cdsc_linkedlist_findindex(struct cdsc_linkedlist *list, void* key);
int cdsc_linkedlist_is_empty(struct cdsc_linkedlist *list);
int cdsc_linkedlist_reverse(struct cdsc_linkedlist *list);
struct cdsc_linkedlist* cdsc_linkedlist_merge(struct cdsc_linkedlist *list1, struct cdsc_linkedlist *list2);
int cdsc_linkedlist_appendnode(struct cdsc_linkedlist *list, struct cdsc_linkedlist_node* cdsc_linkedlist_node);
int cdsc_linkedlist_remove_node_if_contains(struct cdsc_linkedlist *list, void* key);
int cdsc_linkedlist_contains(struct cdsc_linkedlist* list, void* data);
int cdsc_linkedlist_foreach(struct cdsc_linkedlist *list, void (*action)(), void* param);

#endif
