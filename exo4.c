#include <stdio.h>
#include <stdlib.h>

// Structure représentant un terme du polynôme
typedef struct Terme {
    int coefficient;             // Coefficient du terme (ex: 3 dans 3x^2)
    int degre;                   // Degré du terme (ex: 2 dans 3x^2)
    struct Terme* suivant;      // Pointeur vers le terme suivant (liste chaînée)
} Terme;

// Structure représentant un polynôme (liste chaînée de termes)
typedef struct {
    Terme* first_terme;         // Pointeur vers le premier terme du polynôme
} Polynome;

// Fonction pour créer un nouveau terme
Terme* creerTerme(int coefficient, int degre) {
    Terme* newnode = (Terme*)malloc(sizeof(Terme)); // Allocation mémoire
    newnode->coefficient = coefficient;             // Initialisation du coefficient
    newnode->degre = degre;                         // Initialisation du degré
    newnode->suivant = NULL;                        // Le pointeur suivant est NULL (pas encore relié)
    return newnode;
}

// Fonction pour créer un polynôme vide
Polynome* creerPolynome() {
    Polynome* p = (Polynome*)malloc(sizeof(Polynome));
    p->first_terme = NULL;                          // Polynôme vide (aucun terme)
    return p;
}

// Fonction pour ajouter un terme dans le polynôme (en respectant l’ordre décroissant des degrés)
void ajouterTerme(Polynome* p, int coefficient, int degre) {
    if (coefficient == 0) return;                   // Ne pas ajouter les termes de coefficient nul
    
    Terme* newnode = creerTerme(coefficient, degre);

    // Si le polynôme est vide, on place le terme directement
    if (p->first_terme == NULL) {
        p->first_terme = newnode;
        return;
    }

    // Si le degré du nouveau terme est plus grand que celui du premier terme
    if (newnode->degre > p->first_terme->degre) {
        newnode->suivant = p->first_terme;
        p->first_terme = newnode;
        return;
    }

    Terme* courant = p->first_terme;

    // Parcours pour trouver l'emplacement approprié (ordre décroissant des degrés)
    while (courant->suivant != NULL && courant->suivant->degre > newnode->degre) {
        courant = courant->suivant;
    }

    // Si un terme avec le même degré existe, on additionne les coefficients
    if (courant->degre == newnode->degre) {
        courant->coefficient += newnode->coefficient;
        free(newnode); // Pas besoin du nouveau terme

        // Si le coefficient devient 0, on retire le terme
        if (courant->coefficient == 0) {
            if (courant == p->first_terme) {
                p->first_terme = courant->suivant;
            } else {
                Terme* temp = p->first_terme;
                while (temp->suivant != courant) {
                    temp = temp->suivant;
                }
                temp->suivant = courant->suivant;
            }
            free(courant); // Libération de la mémoire
        }
    } else {
        // Insertion du nouveau terme dans la liste chaînée
        newnode->suivant = courant->suivant;
        courant->suivant = newnode;
    }
}

// Fonction pour afficher le polynôme de manière lisible
void afficherPolynome(Polynome* p) {
    if (p->first_terme == NULL) {
        printf("il n'y a pas encore de polynome\n");
        return;
    }

    Terme* courant = p->first_terme;
    int premier = 1; // Pour éviter d’afficher un "+" avant le premier terme

    while (courant != NULL) {
        // Affichage du signe "+"
        if (courant->coefficient > 0 && !premier) {
            printf("+");
        }

        // Affichage en fonction du degré
        if (courant->degre == 0) {
            printf("%d", courant->coefficient);
        } else if (courant->degre == 1) {
            if (courant->coefficient == 1) {
                printf("x");
            } else if (courant->coefficient == -1) {
                printf("-x");
            } else {
                printf("%dx", courant->coefficient);
            }
        } else {
            if (courant->coefficient == 1) {
                printf("x^%d", courant->degre);
            } else if (courant->coefficient == -1) {
                printf("-x^%d", courant->degre);
            } else {
                printf("%dx^%d", courant->coefficient, courant->degre);
            }
        }

        premier = 0;
        courant = courant->suivant;
    }
    printf("\n");
}

// Fonction qui calcule la dérivée première du polynôme
Polynome* DERIVEE(Polynome* p) {
    Polynome* derivee = creerPolynome();
    Terme* courant = p->first_terme;

    while (courant != NULL) {
        if (courant->degre > 0) {
            int newCoeff = courant->coefficient * courant->degre;
            int newDegre = courant->degre - 1;
            ajouterTerme(derivee, newCoeff, newDegre);
        }
        courant = courant->suivant;
    }

    return derivee;
}

// Fonction qui calcule la k-ième dérivée du polynôme
Polynome* DERIVEEKIEME(Polynome* p, int k) {
    if (k <= 0)   
        return p; // Si k <= 0, on retourne le polynôme original
    
    Polynome* resultderi = p;

    for (int i = 0; i < k; i++) {
        Polynome* temp = DERIVEE(resultderi);

        // Libérer les polynômes intermédiaires après la 1ère dérivation
        if (i > 0) {
            Terme* courant = resultderi->first_terme;
            while (courant != NULL) {
                Terme* suivant = courant->suivant;
                free(courant);
                courant = suivant;
            }
            free(resultderi);
        }

        resultderi = temp;
    }

    return resultderi;
}

// Programme principal
int main() {
    // Création du polynôme P(x) = 3x^4 + 2x^2 - 5x + 7
    Polynome* p = creerPolynome();
    ajouterTerme(p, 3, 4);
    ajouterTerme(p, 2, 2);
    ajouterTerme(p, -5, 1);
    ajouterTerme(p, 7, 0);

    printf("le premier Polynome est  P(x) = ");
    afficherPolynome(p);

    // Dérivée première
    int degreDerivation = 1;
    Polynome* derivee = DERIVEE(p);
    printf("la dérivée %d-ème P(x) = ", degreDerivation);
    afficherPolynome(derivee);

    // Dérivée troisième
    degreDerivation = 3;
    Polynome* deriveek = DERIVEEKIEME(p, degreDerivation);
    printf("la dérivée %d ème P(x) = ", degreDerivation);
    afficherPolynome(deriveek);

    return 0;
}
