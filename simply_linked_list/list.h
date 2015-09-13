#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}Node;

typedef struct list {
    Node *head;
}List;

List *create();
void push(int data, List *list);
void pop(int data, List *list);
void print(List *list);
