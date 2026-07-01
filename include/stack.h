#ifndef STACK_H
#define STACK_H

// El stack se implementa sobre una lista enlazada simple
// El "tope" de la pila es siempre la cabeza de la lista (head)
typedef struct StackNode {
    int data;
    struct StackNode *next;
} StackNode;

typedef struct {
    StackNode *top;
    int size;
} Stack;

// Prototipos
Stack *createStack(void);
void push(Stack *stack, int value);
int pop(Stack *stack);
int peek(Stack *stack);
int isEmpty(Stack *stack);
void freeStack(Stack *stack);

#endif