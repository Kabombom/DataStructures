#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack *create() {
    Stack *newStack = (Stack *) malloc(sizeof(Stack));
    newStack -> top = NULL;
    return newStack;
}

int isEmpty(Stack *stack) {
    if (stack -> top != NULL)
        return 1;
    return 0;
}

void push(int data, Stack *stack) {
    if (stack == NULL)
        return;
    Snode *newNode = (Snode *) malloc(sizeof(Snode));
    newNode -> data = data;
    newNode -> next = stack -> top;
    stack -> top = newNode;
}

void pop(Stack *stack) {
    if (stack == NULL || stack -> top == NULL)
        return;
    Snode *node = stack -> top;
    stack -> top = node -> next;
    free(node);
}

void print(Stack *stack) {
    Snode *aux = stack -> top;
    while (aux != NULL) {
        printf("%d\n", aux -> data);
        aux = aux -> next;
    }
}
