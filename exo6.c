#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NMAX 100

typedef double MATCARREE[NMAX][NMAX];

// 3. Calcul du nombre d'éléments nécessaires pour la représentation compacte
// Une matrice symétrique n×n nécessite n(n+1)/2 éléments

bool symetrique(MATCARREE m, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (m[i][j] != m[j][i]) {
                return false;
            }
        }
    }
    return true;
}

double *symCompacte(MATCARREE m, int n) {
    if (!symetrique(m, n)) {
        return NULL;
    }
    int size = n * (n + 1) / 2;
    double *compact = (double *)malloc(size * sizeof(double));
    if (compact == NULL) {
        return NULL;
    }
    int index = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            compact[index++] = m[i][j];
        }
    }
    return compact;
}

double access(double *c, int i, int j) {
    if (i < j) {
        int temp = i;
        i = j;
        j = temp;
    }
    return c[(i * (i + 1)) / 2 + j];
}

void traiterCoef(double x) {
    // on connait pas l'implémentation selon l'énoncé
    printf("%6.2f", x);
}

void traiterLigne(double *c, int n, int i) {
    for (int j = 0; j < n; j++) {
        traiterCoef(access(c, i, j));
    }
}

void afficher(double *c, int n) {
    for (int i = 0; i < n; i++) {
        traiterLigne(c, n, i);
        printf("\n");
    }
}

// Exemple d'utilisation :
int main() {
    MATCARREE mat = {
        {1, 2, 3},
        {2, 4, 5},
        {3, 5, 6}
    };
    int n = 3;

    if (symetrique(mat, n)) {
        printf("La matrice est symétrique.\n");
    } else {
        printf("La matrice n'est pas symétrique.\n");
    }

    double *compact = symCompacte(mat, n);
    if (compact != NULL) {
        printf("Représentation compacte :\n");
        for (int i = 0; i < n*(n+1)/2; i++) {
            printf("%.2f ", compact[i]);
        }
        printf("\n");

        printf("Accès à m[1][2] : %.2f\n", access(compact, 1, 2));

        printf("Affichage matriciel :\n");
        afficher(compact, n);

        free(compact);
    }

    return 0;
}