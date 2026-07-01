#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

// Estructura del arreglo dinámico
// size = cuántos elementos hay, capacity = cuánto espacio hay reservado
typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

// Prototipos de las funciones
DynamicArray *createArray(int initial_capacity);
void addElement(DynamicArray *arr, int value);
void removeElement(DynamicArray *arr, int index);
int getElement(DynamicArray *arr, int index);
void printArray(DynamicArray *arr);
void freeArray(DynamicArray *arr);

#endif