#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handler(int sig) {
    printf("Signal SIGUSR1 reçu !\n");
}

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        signal(SIGUSR1, handler);
        pause(); // Attente d’un signal
        exit(0);
    } else {
        sleep(1);
        kill(pid, SIGUSR1);
        wait(NULL);
    }
    return 0;
}
