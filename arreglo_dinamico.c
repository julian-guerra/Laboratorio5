#include <stdio.h>
#include <stdlib.h>
#include "arreglo_dinamico.h"

// Crea un arreglo dinámico con capacidad inicial dada
DynamicArray *createArray(int initial_capacity) {
    DynamicArray *arr = malloc(sizeof(DynamicArray));
    if (!arr) {
        fprintf(stderr, "Error: no se pudo reservar memoria para el arreglo\n");
        return NULL;
    }
    arr->data = malloc(initial_capacity * sizeof(int));
    if (!arr->data) {
        fprintf(stderr, "Error: no se pudo reservar memoria para los datos\n");
        free(arr);
        return NULL;
    }
    arr->size = 0;
    arr->capacity = initial_capacity;
    return arr;
}

// Agrega un elemento al final, duplica la capacidad si ya no hay espacio
void addElement(DynamicArray *arr, int value) {
    if (arr->size == arr->capacity) {
        // Se dobla la capacidad usando realloc
        arr->capacity *= 2;
        arr->data = realloc(arr->data, arr->capacity * sizeof(int));
        if (!arr->data) {
            fprintf(stderr, "Error: fallo el realloc\n");
            return;
        }
    }
    arr->data[arr->size] = value;
    arr->size++;
}

// Se elimina el elemento en la posición index y corre los demás hacia la izquierda
void removeElement(DynamicArray *arr, int index) {
    if (index < 0 || index >= arr->size) {
        fprintf(stderr, "Error: índice %d fuera de rango\n", index);
        return;
    }
    // Se desplaza todo un puesto hacia la izquierda desde el índice eliminado
    for (int i = index; i < arr->size - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->size--;
}

// Retorna el elemento en la posición index
int getElement(DynamicArray *arr, int index) {
    if (index < 0 || index >= arr->size) {
        fprintf(stderr, "Error: índice %d fuera de rango\n", index);
        return -1;
    }
    return arr->data[index];
}

// Imprime todos los elementos del arreglo
void printArray(DynamicArray *arr) {
    printf("Arreglo [size=%d, capacity=%d]: [ ", arr->size, arr->capacity);
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("]\n");
}

// Libera la memoria del arreglo
void freeArray(DynamicArray *arr) {
    free(arr->data);
    free(arr);
}