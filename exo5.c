#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int compteur = 0;
int nb_signaux = 2;
pid_t fils_pid;

void handler_sigusr1(int sig) {
    printf("Père : reçu SIGUSR1\n");
    if (++compteur < nb_signaux) {
        kill(fils_pid, SIGUSR2);
    }
}

void handler_sigusr2(int sig) {
    printf("Fils : reçu SIGUSR2\n");
    if (++compteur < nb_signaux) {
        kill(getppid(), SIGUSR1);
    }
}

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        signal(SIGUSR2, handler_sigusr2);
        pause();
        pause();
        exit(0);
    } else {
        fils_pid = pid;
        signal(SIGUSR1, handler_sigusr1);
        kill(pid, SIGUSR2); // Premier envoi
        pause();
        pause();
        wait(NULL);
    }
    return 0;
}
