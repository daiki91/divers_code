#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t status;
    status = fork();
    
    switch (status) {
        case -1:
            perror("Erreur de creation de processus");
            return 1;
        
        case 0: // Child process
            switch (fork()) {
                case -1:
                    perror("Erreur de creation de processus intermediaire");
                    return 1;
                
                case 0: // Grandchild process
                    printf("Processus [%d], Mon Pere : [%d]\n", getpid(), getppid());
                    sleep(5);
                    printf("Processus [%d], Mon Pere : [%d]\n", getpid(), getppid());
                    break;
                
                default:
                    return 0;
            }
            break;
        
        default: // Parent process
            wait(&status); // Wait for the child to finish
   
