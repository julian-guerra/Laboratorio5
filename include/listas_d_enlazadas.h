#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

// tiene puntero al anterior y al siguiente
typedef struct DNode {
    int data;
    struct DNode *prev;
    struct DNode *next;
} DNode;

// Lista con puntero al inicio y al final para insertar en ambos extremos
typedef struct {
    DNode *head;
    DNode *tail;
    int size;
} DoublyLinkedList;

// Prototipos
DoublyLinkedList *createDList(void);
void dInsertAtHead(DoublyLinkedList *list, int value);
void dInsertAtTail(DoublyLinkedList *list, int value);
void dInsertAtPosition(DoublyLinkedList *list, int value, int position);
void dDeleteByValue(DoublyLinkedList *list, int value);
DNode *dSearchValue(DoublyLinkedList *list, int value);
void printDListForward(DoublyLinkedList *list);
void printDListBackward(DoublyLinkedList *list);
void freeDList(DoublyLinkedList *list);

#endif