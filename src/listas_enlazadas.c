#include <stdio.h>
#include <stdlib.h>
#include "listas_enlazadas.h"

// Crea y retorna una lista vacía
LinkedList *createList(void) {
    LinkedList *list = malloc(sizeof(LinkedList));
    if (!list) {
        fprintf(stderr, "Error: no se pudo crear la lista\n");
        return NULL;
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

// Crea un nodo nuevo con el valor dado
static Node *createNode(int value) {
    Node *node = malloc(sizeof(Node));
    if (!node) {
        fprintf(stderr, "Error: no se pudo crear el nodo\n");
        return NULL;
    }
    node->data = value;
    node->next = NULL;
    return node;
}

// Inserta al inicio de la lista
void insertAtHead(LinkedList *list, int value) {
    Node *node = createNode(value);
    if (!node) return;
    node->next = list->head;
    list->head = node;
    list->size++;
}

// Inserta al final de la lista (O(n) porque hay que llegar al último)
void insertAtTail(LinkedList *list, int value) {
    Node *node = createNode(value);
    if (!node) return;

    if (list->head == NULL) {
        list->head = node;
    } else {
        // Recorre hasta llegar al último nodo
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
    list->size++;
}

// Inserta en una posición específica
void insertAtPosition(LinkedList *list, int value, int position) {
    if (position < 0 || position > list->size) {
        fprintf(stderr, "Error: posición %d inválida\n", position);
        return;
    }
    if (position == 0) {
        insertAtHead(list, value);
        return;
    }
    Node *node = createNode(value);
    if (!node) return;

    // Llega hasta el nodo anterior a la posición deseada
    Node *current = list->head;
    for (int i = 0; i < position - 1; i++) {
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
    list->size++;
}

// Elimina el primer nodo que tenga el valor buscado
void deleteByValue(LinkedList *list, int value) {
    if (list->head == NULL) {
        printf("Lista vacía, nada que eliminar\n");
        return;
    }
    
    // Busca el nodo anterior al que tiene el valor
    Node *current = list->head;
    while (current->next != NULL && current->next->data != value) {
        current = current->next;
    }
    if (current->next == NULL) {
        printf("Valor %d no encontrado en la lista\n", value);
        return;
    }
    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    list->size--;
}

// Busca el primer nodo con el valor dado, retorna el nodo o NULL si no está
Node *searchValue(LinkedList *list, int value) {
    Node *current = list->head;
    while (current != NULL) {
        if (current->data == value) return current;
        current = current->next;
    }
    return NULL;
}

// Imprime la lista: 1 -> 2 -> 3 -> NULL
void printList(LinkedList *list) {
    printf("Lista [size=%d]: ", list->size);
    Node *current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Libera todos los nodos y la lista
void freeList(LinkedList *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}