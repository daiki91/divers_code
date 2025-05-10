#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void handler(int sig) {
    char password[100];
    printf("\nMot de passe : ");
    scanf("%s", password);
    if (strcmp(password, "1234") == 0) {
        printf("Mot de passe correct. Fin du programme.\n");
        exit(0);
    } else {
        printf("Mot de passe incorrect. Ignoré.\n");
    }
}

int main() {
    signal(SIGINT, handler);
    while (1) {
        printf("Travail en cours... (CTRL+C pour tenter d'arrêter)\n");
        sleep(2);
    }
    return 0;
}
