#include <stdio.h>
#include <stdlib.h>
#include "list.h"

List *create() {
    List *newList = (List *) malloc(sizeof(List));
    newList -> head = NULL;
    return newList;
}

void push(int data, List *llist) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;
    \
    if (llist -> head == NULL) {
        llist -> head = newNode;
        return;
    }
    Node *aux = llist -> head;
    while(aux -> next != NULL)
        aux = aux -> next;
    aux -> next = newNode;
}

void pop(int data, List *llist) {
    if (llist -> head == NULL)
        return;
    Node *lnodeCurr = llist -> head;
    if ((lnodeCurr != NULL && lnodeCurr -> next == NULL && lnodeCurr -> data == data)) {
        free(lnodeCurr);
        llist -> head = NULL;
        return;
    }
    if (lnodeCurr != NULL && lnodeCurr -> data == data) {
        llist -> head = lnodeCurr -> next;
        free(lnodeCurr);
        return;
    }
    Node *lnodePrev = lnodeCurr;
    while(lnodeCurr != NULL) {
        if (lnodeCurr -> data == data) {
            lnodePrev -> next = lnodeCurr -> next;
            free(lnodeCurr);
            return;
        }
        lnodePrev = lnodeCurr;
        lnodeCurr = lnodeCurr -> next;
    }
}

void print(List *llist) {
    Node *aux = llist -> head;
    while(aux != NULL) {
        printf("Number present: %d\n", aux -> data);
        aux = aux -> next;
    }
}
