#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <pid> <code>\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);
    int code = atoi(argv[2]);
    int saisie;

    printf("Veuillez entrer le code de vérification : ");
    scanf("%d", &saisie);

    if (saisie == code) {
        kill(pid, SIGKILL);
        printf("Processus %d tué.\n", pid);
    } else {
        printf("Code incorrect. Processus non tué.\n");
    }

    return 0;
}
