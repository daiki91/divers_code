#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void alarm_handler(int sig) {
    printf("Signal SIGALRM reçu. Fin du programme.\n");
}

int main() {
    signal(SIGALRM, alarm_handler);
    alarm(5);
    pause();
    return 0;
}
