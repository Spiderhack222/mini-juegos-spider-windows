#include <stdio.h>
#include <stdlib.h>

//Juego de Gato en lenguaje C

char tablero[3][3]; // El tablero del juego

// Función para inicializar el tablero
void inicializar_tablero() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = ' ';
        }
    }
}

// Función para imprimir el tablero
void imprimir_tablero() {
    printf("\n");
    printf(" %c | %c | %c\n", tablero[0][0], tablero[0][1], tablero[0][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", tablero[1][0], tablero[1][1], tablero[1][2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n", tablero[2][0], tablero[2][1], tablero[2][2]);
    printf("\n");
}

// Función para verificar si alguien ha ganado
char ganador() {
    // Comprobar filas
    for (int i = 0; i < 3; i++) {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != ' ') {
            return tablero[i][0];
        }
    }
    // Comprobar columnas
    for (int j = 0; j < 3; j++) {
        if (tablero[0][j] == tablero[1][j] && tablero[1][j] == tablero[2][j] && tablero[0][j] != ' ') {
            return tablero[0][j];
        }
    }
    // Comprobar diagonales
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] != ' ') {
        return tablero[0][0];
    }
    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] != ' ') {
        return tablero[0][2];
    }
    // Si no hay ganador
    return ' ';
}

int main() {
    int fila, columna;
    char jugador = 'X';
    int jugadas = 0;

    inicializar_tablero();
    printf("¡Bienvenido al juego de gato!\n");
    printf("Jugador 1: X\n");
    printf("Jugador 2: O\n");
    
    while (1) {
        printf("Turno del Jugador %c\n", jugador);
        imprimir_tablero();
        
        // Obtener la jugada del jugador
        printf("Ingrese fila y columna (ejemplo: 1 1): ");
        scanf("%d %d", &fila, &columna);
        
        // Verificar si la casilla está ocupada
        if (tablero[fila - 1][columna - 1] != ' ') {
            printf("La casilla está ocupada. Inténtalo de nuevo.\n");
            continue;
        }
        
        // Actualizar el tablero
        tablero[fila - 1][columna - 1] = jugador;
        jugadas++;
        
        // Verificar si hay un ganador
        if (ganador() == jugador) {
            imprimir_tablero();
            printf("¡El Jugador %c ha ganado!\n", jugador);
            break;
        } else if (jugadas == 9) {
            imprimir_tablero();
            printf("¡Empate!\n");
            break;
        }
        
        // Cambiar de jugador
        jugador = (jugador == 'X') ? 'O' : 'X';
    }

    return 0;
}
