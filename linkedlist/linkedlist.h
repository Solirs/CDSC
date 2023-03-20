#ifndef SIMPLE_LL_
#define SIMPLE_LL_

#include <stdlib.h>
#include <stdbool.h>

#define cdsc_linkedlist_prepend(list, data) inserthead(list, data)
#define cdsc_linkedlist_append(list, data) inserttail(list, data)

struct node{
    void* data;
    struct node* next;
};

struct LinkedList{
    int size;
    struct node* head;
    struct node* tail;
};

void inserthead(struct LinkedList *list, void* data);
void inserttail(struct LinkedList *list, void* data);

void* poptail(struct LinkedList *list);
void* pophead(struct LinkedList *list);

void* getindexfromhead(struct LinkedList *list, int index);
void* getindexfromtail(struct LinkedList *list, int index);

struct LinkedList *make_ll();
void nuke(struct LinkedList *list);
void setdata(struct LinkedList *list, void* data, int index);
struct node* find(struct LinkedList *list, void* key);
int findindex(struct LinkedList *list, void* key);
bool is_empty(struct LinkedList *list);
void reverse(struct LinkedList *list);
void cdsc_linkedlist_merge(struct LinkedList *list1, struct LinkedList *list2);
void appendnode(struct LinkedList *list, struct node* node);
void remove_node_if_contains(struct LinkedList *list, void* key);
bool contains(struct LinkedList* list, void* data);
void cdsc_linkedlist_foreach(struct LinkedList *list, void (*action)(), void* param);

#endif
