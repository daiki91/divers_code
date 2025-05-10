#include <stdlib.h>
#include <stdio.h>

void bilan(void) {
    printf("Vous avez fait 1h\n");
}

void paiement(void) {
    printf("Vous devez payer 10 frs\n");
}

void goodbye(void) {
    printf("Goodbye\n");
}

int main(void) {
    if (atexit(goodbye) != 0) {
        perror("Error in atexit");
    }
    if (atexit(paiement) != 0) {
        perror("Error in atexit");
    }
    if (atexit(bilan) != 0) {
        perror("Error in atexit");
    }
    
    exit(0);
}
