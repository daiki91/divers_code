#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <pid>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    char reponse;

    printf("Voulez-vous tuer le processus %d ? (y/n) : ", pid);
    scanf(" %c", &reponse);

    if (reponse == 'y' || reponse == 'Y') {
        kill(pid, SIGKILL);
        printf("Processus %d tué.\n", pid);
    } else {
        printf("Annulé.\n");
    }

    return 0;
}
