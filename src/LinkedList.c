#include <stdlib.h>
#include "LinkedList.h"
#include "ErrorHandling.h"

LinkedList * LinkedList_push(LinkedList * list, void * data)
{
    LinkedList * node = malloc(sizeof(LinkedList));

    if (node == NULL) {
        printError("failed to malloc");
    }
    node->data = data;
    node->next = NULL;

    if (list == NULL) {
        list = node;
    }
    else {
        LinkedList_append(list, node);
    }
    return list;
}

LinkedList * LinkedList_forcePush(LinkedList * list, void * data)
{
    LinkedList * origin = list;
    list = LinkedList_push(list, data);
    if (list == NULL) {
        LinkedList_destroy(origin);
        return NULL;
    }
    return list;
}

void LinkedList_destroy(LinkedList * list)
{
    if (list == NULL)
        return;
    if (list->data)
        free(list->data);
    if (list->next) {
        LinkedList_destroy(list->next);
    }
    free(list);
}

void LinkedList_definedDestroy(LinkedList * list, void (*d)(void * data))
{
    if (list == NULL)
        return;
    if (list->data)
        d(list->data);
    if (list->next) {
        LinkedList_definedDestroy(list->next, d);
    }
    free(list);
}


void LinkedList_append(LinkedList *a, LinkedList *b)
{
    while (a->next)
        a = a->next;
    a->next = b;
}

void LinkedList_foreach(LinkedList *a, void (*fnc)(void *a, void *param), void *param)
{
    while (a) {
        fnc(a->data, param);
        a = a->next;
    }
}

int LinkedList_count(LinkedList *a)
{
    int i = 0;
    while (a != NULL) {
        a = a->next;
        i++;
    }
    return i;
}
