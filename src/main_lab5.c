#include <stdio.h>
#include "arreglo_dinamico.h"
#include "listas_enlazadas.h"
#include "listas_d_enlazadas.h"
#include "stack.h"

// Separador para que el output sea más legible
static void separador(const char *title) {
    printf("\n========== %s ==========\n", title);
}

int main(void) {

    // =====================
    // ARREGLO DINÁMICO
    // =====================
    separador("Arreglo Dinámico");

    DynamicArray *arr = createArray(2); // empieza con capacidad 2

    // Agrega elementos, debe hacer realloc automático cuando se llena
    addElement(arr, 10);
    addElement(arr, 20);
    addElement(arr, 30); // acá debería duplicar capacidad a 4
    addElement(arr, 40);
    addElement(arr, 50); // duplica de nuevo a 8
    printArray(arr);

    // Obtener por índice
    printf("Elemento en índice 2: %d\n", getElement(arr, 2));

    // Eliminar el elemento en índice 1 (valor 20)
    printf("Eliminando índice 1 (valor 20)...\n");
    removeElement(arr, 1);
    printArray(arr);

    freeArray(arr);

    // =====================
    // LISTA ENLAZADA SIMPLE
    // =====================
    separador("Lista Enlazada Simple");

    LinkedList *list = createList();

    insertAtTail(list, 1);
    insertAtTail(list, 2);
    insertAtTail(list, 3);
    insertAtHead(list, 0);         // 0 -> 1 -> 2 -> 3
    insertAtPosition(list, 99, 2); // 0 -> 1 -> 99 -> 2 -> 3
    printList(list);

    // Buscar un valor
    Node *found = searchValue(list, 99);
    printf("Búsqueda de 99: %s\n", found ? "encontrado" : "no encontrado");
    found = searchValue(list, 77);
    printf("Búsqueda de 77: %s\n", found ? "encontrado" : "no encontrado");

    // Eliminar por valor
    printf("Eliminando valor 99...\n");
    deleteByValue(list, 99);
    printList(list);

    freeList(list);

    // ============================
    // LISTA DOBLEMENTE ENLAZADA
    // ============================
    separador("Lista Doblemente Enlazada");

    DoublyLinkedList *dlist = createDList();

    dInsertAtTail(dlist, 10);
    dInsertAtTail(dlist, 20);
    dInsertAtTail(dlist, 30);
    dInsertAtHead(dlist, 5);          // 5 <-> 10 <-> 20 <-> 30
    dInsertAtPosition(dlist, 15, 2);  // 5 <-> 10 <-> 15 <-> 20 <-> 30

    printDListForward(dlist);
    printDListBackward(dlist);

    // Buscar
    DNode *dfound = dSearchValue(dlist, 15);
    printf("Búsqueda de 15: %s\n", dfound ? "encontrado" : "no encontrado");

    // Eliminar
    printf("Eliminando valor 10...\n");
    dDeleteByValue(dlist, 10);
    printDListForward(dlist);
    printDListBackward(dlist);

    freeDList(dlist);

    // =====================
    // STACK
    // =====================
    separador("Stack");

    Stack *stack = createStack();

    printf("¿Stack vacío? %s\n", isEmpty(stack) ? "sí" : "no");

    push(stack, 100);
    push(stack, 200);
    push(stack, 300);

    printf("Peek (tope sin eliminar): %d\n", peek(stack));
    printf("¿Stack vacío? %s\n", isEmpty(stack) ? "sí" : "no");

    printf("Pop: %d\n", pop(stack));
    printf("Pop: %d\n", pop(stack));
    printf("Peek ahora: %d\n", peek(stack));
    printf("Pop: %d\n", pop(stack));

    printf("¿Stack vacío después de 3 pops? %s\n", isEmpty(stack) ? "sí" : "no");

    freeStack(stack);
    return 0;
}