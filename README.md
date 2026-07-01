

## Cómo compilar

```bash
make
```

Esto genera el ejecutable `main` en la raíz del proyecto.

Para limpiar los archivos generados:

```bash
make clean
```

## Cómo ejecutar

```bash
./main
```

El programa demuestra todas las operaciones de cada estructura de datos con output en consola.

Para verificar que no hay memory leaks:

```bash
valgrind --leak-check=full ./main
```