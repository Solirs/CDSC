#ifndef SIMPLE_LL_
#define SIMPLE_LL_

#include <stdlib.h>
#include <stdbool.h>
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
bool is_empty(struct LinkedList *list);
void reverse(struct LinkedList *list);
#endif