#include <stdio.h>
#include <string.h>
#include "operaciones.h"
#include "lectura.h"

char inventario_nombres[MAX_PRODUCTOS][MAX_NOMBRE_PRODUCTO];
int inventario_cantidades[MAX_PRODUCTOS];
float inventario_precios[MAX_PRODUCTOS];
int numProductos = 0;

char clientes_cedulas[MAX_CLIENTES][MAX_CEDULA];
char clientes_nombres[MAX_CLIENTES][MAX_NOMBRE_CLIENTE];
int numClientes = 0;

char facturas_fechas[MAX_FACTURAS][MAX_FECHA];
char facturas_cedulas[MAX_FACTURAS][MAX_CEDULA];
char facturas_nombres[MAX_FACTURAS][MAX_NOMBRE_CLIENTE];
float facturas_valores[MAX_FACTURAS];
int facturas_cantidades[MAX_FACTURAS];
int numFacturas = 0;

void copiarCadena(char* destino, const char* origen) {
    while (*origen) {
        *destino = *origen;
        destino++;
        origen++;
    }
    *destino = '\0';
}

int longitudCadena(const char* cadena) {
    int longitud = 0;
    while (*cadena) {
        longitud++;
        cadena++;
    }
    return longitud;
}

int compararCadenas(const char* cadena1, const char* cadena2) {
    while (*cadena1 && *cadena2 && *cadena1 == *cadena2) {
        cadena1++;
        cadena2++;
    }
    return (*cadena1 == '\0' && *cadena2 == '\0');
}

int revisaCedula(const char* cedula) {
    return validarCedulaEcuatoriana((char*)cedula);
}

void ingresarProducto() {
    if (numProductos < MAX_PRODUCTOS) {
        printf("Ingresar nombre del producto: ");
        scanf(" %[^\n]", inventario_nombres[numProductos]);

        for (int i = 0; i < numProductos; i++) {
            if (compararCadenas(inventario_nombres[i], inventario_nombres[numProductos])) {
                printf("Ya existe un producto con este nombre.\n");
                return;
            }
        }

        inventario_cantidades[numProductos] = leerEnteroPositivo("Ingresar cantidad: ");
        inventario_precios[numProductos] = leerFlotantePositivo("Ingresar precio: ");

        numProductos++;
    } else {
        printf("Inventario lleno.\n");
    }
}

void editarProducto() {
    char nombreEditar[MAX_NOMBRE_PRODUCTO];
    printf("Ingresar nombre del producto a editar: ");
    scanf(" %[^\n]", nombreEditar);

    int encontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        if (compararCadenas(inventario_nombres[i], nombreEditar)) {
            encontrado = 1;
            printf("Editar nombre del producto (anterior: %s): ", inventario_nombres[i]);
            scanf(" %[^\n]", inventario_nombres[i]);

            inventario_cantidades[i] = leerEnteroPositivo("Ingresar nueva cantidad: ");
            inventario_precios[i] = leerFlotantePositivo("Ingresar nuevo precio: ");
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}

void eliminarProducto() {
    char nombreEliminar[MAX_NOMBRE_PRODUCTO];
    printf("Ingresar nombre del producto a eliminar: ");
    scanf(" %[^\n]", nombreEliminar);

    int encontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        if (compararCadenas(inventario_nombres[i], nombreEliminar)) {
            encontrado = 1;
            for (int j = i; j < numProductos - 1; j++) {
                copiarCadena(inventario_nombres[j], inventario_nombres[j + 1]);
                inventario_cantidades[j] = inventario_cantidades[j + 1];
                inventario_precios[j] = inventario_precios[j + 1];
            }
            numProductos--;
            printf("Producto eliminado.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}

void listarProductos() {
    printf("\n===== Lista de Productos =====\n");
    for (int i = 0; i < numProductos; i++) {
        printf("Nombre: %s, Cantidad: %d, Precio: %.2f\n", inventario_nombres[i], inventario_cantidades[i], inventario_precios[i]);
    }
}

void ingresarCliente() {
    if (numClientes < MAX_CLIENTES) {
        char cedula[MAX_CEDULA];
        printf("Ingresar cedula del cliente: ");
        scanf("%s", cedula);

        if (revisaCedula(cedula)) {
            for (int i = 0; i < numClientes; i++) {
                if (compararCadenas(clientes_cedulas[i], cedula)) {
                    printf("Ya existe un cliente con esta cédula.\n");
                    return;
                }
            }

            copiarCadena(clientes_cedulas[numClientes], cedula);
            printf("Ingresar nombre del cliente: ");
            scanf(" %[^\n]", clientes_nombres[numClientes]);

            numClientes++;
        } else {
            printf("Cédula inválida.\n");
        }
    } else {
        printf("Lista de clientes llena.\n");
    }
}

void editarCliente() {
    char cedulaEditar[MAX_CEDULA];
    printf("Ingresar cedula del cliente a editar: ");
    scanf("%s", cedulaEditar);

    int encontrado = 0;
    for (int i = 0; i < numClientes; i++) {
        if (compararCadenas(clientes_cedulas[i], cedulaEditar)) {
            encontrado = 1;
            printf("Ingresar nuevo nombre del cliente (anterior: %s): ", clientes_nombres[i]);
            scanf(" %[^\n]", clientes_nombres[i]);
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente no encontrado.\n");
    }
}

void consultarCliente() {
    char cedulaConsultar[MAX_CEDULA];
    printf("Ingresar cedula del cliente a consultar: ");
    scanf("%s", cedulaConsultar);

    int encontrado = 0;
    for (int i = 0; i < numClientes; i++) {
        if (compararCadenas(clientes_cedulas[i], cedulaConsultar)) {
            encontrado = 1;
            printf("Nombre: %s\n", clientes_nombres[i]);
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente no encontrado.\n");
    }
}

void verListadoClientes() {
    printf("\n===== Lista de Clientes =====\n");
    for (int i = 0; i < numClientes; i++) {
        printf("Cedula: %s, Nombre: %s\n", clientes_cedulas[i], clientes_nombres[i]);
    }
}

void adicionarCompraProducto() {
    printf("Funcionalidad de adicionar compra de producto no implementada aún.\n");
}

void facturar() {
    printf("Funcionalidad de facturación no implementada aún.\n");
}

void buscarFactura() {
    printf("Funcionalidad de búsqueda de factura no implementada aún.\n");
}

void verListadoFacturas() {
    printf("\n===== Lista de Facturas =====\n");
    for (int i = 0; i < numFacturas; i++) {
        printf("Fecha: %s, Cedula: %s, Nombre: %s, Valor: %.2f, Cantidad: %d\n", 
               facturas_fechas[i], facturas_cedulas[i], facturas_nombres[i], 
               facturas_valores[i], facturas_cantidades[i]);
    }
}

void cargarDatos() {
    printf("Funcionalidad de carga de datos no implementada aún.\n");
}

void guardarDatos() {
    printf("Funcionalidad de guardado de datos no implementada aún.\n");
}
