#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	pid_t status;
	status = fork();
	switch (status)
    {
    case -1:
        perror("Creation de processus");
        return -1;
        break;
    case 0: /*code du fils*/
        printf("[%d] je vient de naitre \n", getpid());
        printf("[%d] mon pere %d\n", getpid(), getppid());
        break;
    
    default:
        printf("[%d] j\'ai engendre'\n", getpid());
        printf("[%d] mon fils %d\n", getpid(), status);
        
        break;
    };
    printf("[%d] je termine\n", getpid());
    exit(EXIT_SUCCESS);

	return 0;
}
