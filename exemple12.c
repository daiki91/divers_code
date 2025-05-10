#include <stdio.h>
#include <stdlib.h>

int main() {
    execl("/bin/ls", "ls", NULL);
    printf("Je ne suis pas mort\n"); // This will not be executed if execl() succeeds
    return 0;
}
