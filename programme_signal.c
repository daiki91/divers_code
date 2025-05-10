#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>

#define DELAI 1

void traitement(int numero_signal) {
    printf("\n Reception du Signal %d => ",numero_signal);
    switch(numero_signal) {
        case SIGTSTP:
            printf("Je m’endors....\n");
            kill(getpid(), SIGSTOP);
            printf("Je me réveille !\n");
            signal(SIGTSTP, traitement);
            break;
        case SIGINT:
        case SIGTERM:
            printf("Fin du programme.\n");
            exit(EXIT_SUCCESS);
            break;
    }
}

int main(void) {
    printf("Mon PID est %d => ", getpid());

    signal(SIGTSTP, traitement);
    signal(SIGINT , traitement );
    signal(SIGTERM, traitement);

    printf("Attente de reception d'un signal \n");

    while (1) {
        sleep(DELAI);
        printf(".");
        fflush(stdout);
    }

    printf("fin\n");
    exit(EXIT_SUCCESS);
}
