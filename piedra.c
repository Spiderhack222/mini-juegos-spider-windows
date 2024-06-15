#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int computer_choice, user_choice;
    int score = 0;
    int i;
    char *choices[] = {"piedra", "papel", "tijera"};

    srand(time(NULL));

    for (i = 0; i < 5; i++) {
        printf("Elige una opcion (1: piedra, 2: papel, 3: tijera): ");
        scanf("%d", &user_choice);

        computer_choice = rand() % 3 + 1;

        printf("Tu opcion: %s\n", choices[user_choice - 1]);
        printf("Opcion del computador: %s\n", choices[computer_choice - 1]);

        if (user_choice == computer_choice) {
            printf("Empate!\n\n");
        } else if ((user_choice == 1 && computer_choice == 3) || (user_choice == 2 && computer_choice == 1) || (user_choice == 3 && computer_choice == 2)) {
            printf("Ganaste esta ronda!\n\n");
            score++;
        } else {
            printf("Perdiste esta ronda.\n\n");
            score--;
        }
    }

    printf("Tu puntuacion final es: %d\n", score);

    return 0;
}