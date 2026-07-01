#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Nodo de la lista enlazada simple
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// La lista en sí solo guarda un puntero al primer nodo
typedef struct {
    Node *head;
    int size;
} LinkedList;

// Prototipos
LinkedList *createList(void);
void insertAtHead(LinkedList *list, int value);
void insertAtTail(LinkedList *list, int value);
void insertAtPosition(LinkedList *list, int value, int position);
void deleteByValue(LinkedList *list, int value);
Node *searchValue(LinkedList *list, int value);
void printList(LinkedList *list);
void freeList(LinkedList *list);

#endif