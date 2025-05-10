#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage : %s <PID_du_serveur>\n", argv[0]);
        return 1;
    }

    int server_pid = atoi(argv[1]);

    printf("Client : Envoi de SIGUSR1 au PID %d\n", server_pid);
    kill(server_pid, SIGUSR1);
    sleep(1); // Petit délai pour voir le traitement

    printf("Client : Envoi de SIGUSR2 au PID %d\n", server_pid);
    kill(server_pid, SIGUSR2);

    printf("Client : Signaux envoyés.\n");
    return 0;
}
