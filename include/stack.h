#ifndef STACK_H
#define STACK_H

// El stack se implementa sobre una lista enlazada simple
// El tope del stack es siempre el head de la lista
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