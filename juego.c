#include <stdio.h>
#include <stdlib.h>

// Función para limpiar el buffer de entrada
void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int opcion;
    do {
        // Mostrar el menú de juegos
        printf("Bienvenido al Menu de Juegos\n");
        printf("1. Buscaminas\n");
        printf("2. Gato\n");
        printf("3. Piedra\n");
        printf("4. Juego de Laberintos\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        limpiarBuffer(); // Limpiar el buffer de entrada

        // Ejecutar el juego correspondiente según la opción
        switch (opcion) {
            case 1:
                system("buscaminas.exe"); // Ejecutar buscaminas
                break;
            case 2:
                system("gato.exe"); // Ejecutar gato
                break;
            case 3:
                system("piedra.exe"); // Ejecutar piedra
                break;
            case 4:
                system("laberinto\\JuegoLaberintos.exe");
                // Ejecutar Juego de Laberintos desde la ruta especificada
                break;
            case 5:
                printf("Saliendo del Menu de Juegos. Hasta luego!\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}
