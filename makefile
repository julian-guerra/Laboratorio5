
CC = gcc
CFLAGS = -Wall -Wextra -g
SRC = src/main_lab5.c src/stack.c src/listas_enlazadas.c src/listas_d_enlazadas.c src/arreglo_dinamico.c
OBJ = $(SRC:.c=.o)
TARGET = main_lab5

# compila todo y genera el ejecutable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# compilar cada .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Elimina todos los archivos generados
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: clean