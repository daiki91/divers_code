#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    printf("Processus [%d]\n", getpid());
    
    switch (fork()) {
        case -1:
            perror("Creation de processus");
            return 1;
        
        case 0: // Child process
            printf("Processus [%d] - Mon pere est [%d]\n", getpid(), getppid());
            sleep(5);
            printf("Processus [%d] - Mon pere est [%d]\n", getpid(), getppid());
            exit(0);
        
        default: // Parent process
            sleep(1);
            printf("Processus pere [%d]: je termine\n", getpid());
            exit(0);
    }
}
