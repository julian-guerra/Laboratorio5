#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Crea un stack vacío
Stack *creaStack(void) {
    Stack *stack = malloc(sizeof(Stack));
    if (!stack) {
        fprintf(stderr, "Error: no se pudo crear el stack\n");
        return NULL;
    }
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

// el push agrega un elemento al tope del stack
void push(Stack *stack, int value) {
    StackNode *node = malloc(sizeof(StackNode));
    if (!node) {
        fprintf(stderr, "Error: no se pudo reservar memoria para el nodo\n");
        return;
    }
    node->data = value;
    // El nuevo nodo apunta al antiguo tope, y pasa a ser el nuevo tope
    node->next = stack->top;
    stack->top = node;
    stack->size++;
    printf("Push(%d) -> stack size: %d\n", value, stack->size);
}

// Pop: elimina y retorna el elemento del tope
// Retorna -1 si el stack está vacío
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Error: pop en stack vacío\n");
        return -1;
    }
    StackNode *temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    stack->size--;
    return value;
}

// Peek/Top: retorna el valor del tope sin eliminarlo
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        fprintf(stderr, "Error: peek en stack vacío\n");
        return -1;
    }
    return stack->top->data;
}

// Verifica si el stack está vacío
int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

// Libera todos los nodos del stack
void freeStack(Stack *stack) {
    StackNode *current = stack->top;
    while (current != NULL) {
        StackNode *next = current->next;
        free(current);
        current = next;
    }
    free(stack);
}
