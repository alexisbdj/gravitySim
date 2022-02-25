#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

typedef struct ListNode {
    void *data;
    struct ListNode *next;
} LinkedList;

LinkedList * LinkedList_push(LinkedList * list, void * data);
LinkedList * LinkedList_forcePush(LinkedList * list, void * data); // free existing data on failure

void LinkedList_destroy(LinkedList * list);

void LinkedList_append(LinkedList *a, LinkedList *b);

void LinkedList_foreach(LinkedList *a, void (*fnc)(void *a));

#endif