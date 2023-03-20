#ifndef DOUBLE_LL_
#define DOUBLE_LL_

#include <stdlib.h>
#include <stdbool.h>

#define cdsc_doublylinkedlist_prepend(list, data) inserthead(list, data)
#define cdsc_doublylinkedlist_append(list, data) inserttail(list, data)

struct node{
    struct node* previous;
    void* data;
    struct node* next;
};

struct DoubleLinkedList{
    int size;
    struct node* head;
    struct node* tail;


};

void inserthead(struct DoubleLinkedList *list, void* data);
void inserttail(struct DoubleLinkedList *list, void* data);

void* poptail(struct DoubleLinkedList *list);
void* pophead(struct DoubleLinkedList *list);

void* getindexfromhead(struct DoubleLinkedList *list, int index);
void* getindexfromtail(struct DoubleLinkedList *list, int index);

struct DoubleLinkedList *make_dll();
void nuke(struct DoubleLinkedList *list);
void setdata(struct DoubleLinkedList *list, void* data, int index);

void doublelinkedlist_zero(struct DoubleLinkedList *ll);
void cdsc_doublylinkedlist_reverse(struct DoubleLinkedList *list);
void cdsc_doublylinkedlist_merge(struct DoubleLinkedList *list1, struct DoubleLinkedList *list2);
void cdsc_doublylinkedlist_appendnode(struct DoubleLinkedList *list, struct node* node);
bool cdsc_doublylinkedlist_contains(struct DoubleLinkedList* list, void* data);
struct node* cdsc_doublylinkedlist_find(struct DoubleLinkedList *list, void* key);
int cdsc_doublylinkedlist_findindex(struct DoubleLinkedList *list, void* key);
void cdsc_doublylinkedlist_foreach(struct DoubleLinkedList *list, void (*action)(), void* param);

#endif
