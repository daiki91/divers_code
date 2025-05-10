#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    pid_t pid;
    int status;

    pid = fork();

    switch (pid) {
        case -1:
            perror("Error dans l'appel fork");
            exit(1);
        
        case 0: /* Le fils */
            printf("Processus fils [%d] : mon père est [%d]\n", getpid(), getppid());
            exit(247);
        
        default: /* Le père */
            printf("Père [%d] : a créé processus [%d]\n", getpid(), pid);
            wait(&status);
            
            if (WIFEXITED(status)) {
                printf("Le fils termine normalement : status = %d\n", WEXITSTATUS(status));
            } else {
                printf("Fils termine anormalement\n");
            }
    }

    return 0;
}
