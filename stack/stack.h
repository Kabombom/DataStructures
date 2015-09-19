#include <stdio.h>
#include <stdlib.h>

int stackSize = 10;

typedef struct snode {
    int data;
    struct snode *next;
}Snode;

typedef struct stack {
    Snode *top;
}Stack;

Stack *create();
void pop(Stack *stack);
void print(Stack *stack);
Snode *top(Stack *stack);
int isEmpty(Stack *stack);
