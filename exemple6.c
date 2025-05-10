#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    printf("avant\n");
    fork();
    printf("apres\n");
    return 0;
}

