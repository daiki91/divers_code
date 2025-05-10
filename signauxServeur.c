#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

volatile sig_atomic_t sigusr1_received = 0;
volatile sig_atomic_t sigusr2_received = 0;

void handler(int signum) {
    if (signum == SIGUSR1) {
        sigusr1_received = 1;
        printf("Serveur : Reçu SIGUSR1\n");
    } else if (signum == SIGUSR2) {
        sigusr2_received = 1;
        printf("Serveur : Reçu SIGUSR2\n");
    }
}

int main() {
    printf("Serveur lancé avec PID : %d\n", getpid());

    signal(SIGUSR1, handler);
    signal(SIGUSR2, handler);

    while (!(sigusr1_received && sigusr2_received)) {
        pause(); // Attend un signal
    }

    printf("Serveur : Reçus les deux signaux. Fin du programme.\n");
    return 0;
}
