#include <stdio.h>
#include <stdlib.h>
#include "listas_d_enlazadas.h"

// Crea una lista doblemente enlazada vacía
DoublyLinkedList *createDList(void) {
    DoublyLinkedList *list = malloc(sizeof(DoublyLinkedList));
    if (!list) {
        fprintf(stderr, "Error: no se pudo crear la lista doble\n");
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

// Función interna para crear un nodo
static DNode *createDNode(int value) {
    DNode *node = malloc(sizeof(DNode));
    if (!node) {
        fprintf(stderr, "Error: no se pudo crear el nodo\n");
        return NULL;
    }
    node->data = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

// Inserta al inicio, actualiza head y el puntero prev del antiguo primero
void dInsertAtHead(DoublyLinkedList *list, int value) {
    DNode *node = createDNode(value);
    if (!node) return;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
    list->size++;
}

// Inserta al final usando el puntero tail (O(1) gracias a tail)
void dInsertAtTail(DoublyLinkedList *list, int value) {
    DNode *node = createDNode(value);
    if (!node) return;

    if (list->tail == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

// Inserta en una posición específica
void dInsertAtPosition(DoublyLinkedList *list, int value, int position) {
    if (position < 0 || position > list->size) {
        fprintf(stderr, "Error: posición %d inválida\n", position);
        return;
    }
    if (position == 0) {
        dInsertAtHead(list, value);
        return;
    }
    if (position == list->size) {
        dInsertAtTail(list, value);
        return;
    }
    DNode *node = createDNode(value);
    if (!node) return;

    // Llega al nodo en la posición deseada
    DNode *current = list->head;
    for (int i = 0; i < position; i++) {
        current = current->next;
    }
    // Enchufa el nuevo nodo entre current->prev y current
    node->next = current;
    node->prev = current->prev;
    current->prev->next = node;
    current->prev = node;
    list->size++;
}

// Elimina el primer nodo con el valor dado
void dDeleteByValue(DoublyLinkedList *list, int value) {
    DNode *current = list->head;
    while (current != NULL) {
        if (current->data == value) {
            // Reconecta los vecinos
            if (current->prev) current->prev->next = current->next;
            else list->head = current->next; // era el primero

            if (current->next) current->next->prev = current->prev;
            else list->tail = current->prev; // era el último

            free(current);
            list->size--;
            return;
        }
        current = current->next;
    }
    printf("Valor %d no encontrado\n", value);
}

// Busca un nodo por valor
DNode *dSearchValue(DoublyLinkedList *list, int value) {
    DNode *current = list->head;
    while (current != NULL) {
        if (current->data == value) return current;
        current = current->next;
    }
    return NULL;
}

// Imprime de inicio a fin
void printDListForward(DoublyLinkedList *list) {
    printf("DLista (adelante) [size=%d]: ", list->size);
    DNode *current = list->head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Imprime de fin a inicio aprovechando el puntero tail
void printDListBackward(DoublyLinkedList *list) {
    printf("DLista (atrás)   [size=%d]: ", list->size);
    DNode *current = list->tail;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

// Libera todos los nodos
void freeDList(DoublyLinkedList *list) {
    DNode *current = list->head;
    while (current != NULL) {
        DNode *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}