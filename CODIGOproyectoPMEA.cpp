#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para almacenar los datos de un producto
typedef struct {
    char nombre[100];
    int cantidad;
    float precio;
} Producto;

// Función para ingresar un nuevo producto
void ingresarProducto(Producto *inventario, int *numProductos) {
    int repetir;
    do {
        Producto nuevoProducto;
        printf("Ingrese el nombre del producto: ");
        scanf("%s", nuevoProducto.nombre);
        printf("Ingrese la cantidad: ");
        scanf("%d", &nuevoProducto.cantidad);
        printf("Ingrese el precio: ");
        scanf("%f", &nuevoProducto.precio);

        // Agregar el nuevo producto al inventario
        inventario[*numProductos] = nuevoProducto;
        (*numProductos)++;
        printf("Producto agregado exitosamente.\n");

        printf("¿Desea ingresar otro producto? (1: Sí, 0: No): ");
        scanf("%d", &repetir);
    } while (repetir == 1);
}

// Función para editar un producto existente
void editarProducto(Producto *inventario, int numProductos) {
    int repetir;
    do {
        int indice;
        printf("Ingrese el índice del producto a editar (0 - %d): ", numProductos - 1);
        scanf("%d", &indice);

        if (indice >= 0 && indice < numProductos) {
            Producto *producto = &inventario[indice];
            printf("Ingrese el nuevo nombre del producto: ");
            scanf("%s", producto->nombre);
            printf("Ingrese la nueva cantidad: ");
            scanf("%d", &(producto->cantidad));
            printf("Ingrese el nuevo precio: ");
            scanf("%f", &(producto->precio));
            printf("Producto editado exitosamente.\n");
        } else {
            printf("Índice inválido.\n");
        }

        printf("¿Desea editar otro producto? (1: Sí, 0: No): ");
        scanf("%d", &repetir);
    } while (repetir == 1);
}

// Función para eliminar un producto existente
void eliminarProducto(Producto *inventario, int *numProductos) {
    int repetir;
    do {
        int indice;
        printf("Ingrese el índice del producto a eliminar (0 - %d): ", *numProductos - 1);
        scanf("%d", &indice);

        if (indice >= 0 && indice < *numProductos) {
            // Desplazar los elementos hacia atrás para eliminar el producto
            for (int i = indice; i < *numProductos - 1; i++) {
                inventario[i] = inventario[i + 1];
            }
            (*numProductos)--;
            printf("Producto eliminado exitosamente.\n");
        } else {
            printf("Índice inválido.\n");
        }

        printf("¿Desea eliminar otro producto? (1: Sí, 0: No): ");
        scanf("%d", &repetir);
    } while (repetir == 1);
}
// Función para listar todos los productos ingresados
void listarProductos(Producto *inventario, int numProductos) {
    printf("Lista de productos:\n");
    for (int i = 0; i < numProductos; i++) {
        printf("Índice: %d\n", i);
        printf("Nombre: %s\n", inventario[i].nombre);
        printf("Cantidad: %d\n", inventario[i].cantidad);
        printf("Precio: %.2f\n\n", inventario[i].precio);
    }
}

int main() {
    Producto inventario[100];  // Se asume un máximo de 100 productos
    int numProductos = 0;
    int opcion;

    do {
        printf("Sistema de Inventarios\n");
        printf("1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Listar productos\n");
        printf("5. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarProducto(inventario, &numProductos);
                break;
            case 2:
                editarProducto(inventario, numProductos);
                break;
            case 3:
                eliminarProducto(inventario, &numProductos);
                break;
            case 4:
                listarProductos(inventario, numProductos);
                break;
            case 5:
                printf("¡Hasta luego!\n");
                break;
            default:
                printf("Opción inválida.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}