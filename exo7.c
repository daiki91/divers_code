#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud {
    int valeur;
    struct Noeud *gauche;
    struct Noeud *droite;
} Noeud;

typedef struct {
    Noeud *racine;
} ARB_BIN;

void FEUILLE(ARB_BIN A) {
    if (A.racine == NULL) return;
    
    if (A.racine->gauche == NULL && A.racine->droite == NULL) {
        printf("l'etiquette de la feuille est : %d ", A.racine->valeur);
        return;
    }
    
    ARB_BIN gauche, droite;
    gauche.racine = A.racine->gauche;
    droite.racine = A.racine->droite;
    
    FEUILLE(gauche);
    FEUILLE(droite);
}

void DEGRE(ARB_BIN A) {
    if (A.racine == NULL) 
    return;
    
    int i = 0;
    if (A.racine->gauche != NULL) 
    i++;
    if (A.racine->droite != NULL)
     i++;
    
    printf("le noeud %d a pour  degre = %d\n", A.racine->valeur, i);
    
    ARB_BIN gauche, droite;
    gauche.racine = A.racine->gauche;
    droite.racine = A.racine->droite;
    
    DEGRE(gauche);
    DEGRE(droite);
}

void PROFONDEUR(ARB_BIN A, int x) {
    static int temp = 0;
    static int trouve = 0;
    
    if (A.racine == NULL) {
        if (temp == 0) {
            printf("L'arbre est vide\n");
        }
        return;
    }
    
    if (A.racine->valeur == x) {
        printf("La profondeur du noeud %d est : %d\n", x, temp);
        trouve = 1;
        return;
    }
    
    if (A.racine->gauche != NULL) {
        temp++;
        ARB_BIN gauche;
        gauche.racine = A.racine->gauche;
        PROFONDEUR(gauche, x);
        temp--;
    }
    
    if (!trouve && A.racine->droite != NULL) {
        temp++;
        ARB_BIN droite;
        droite.racine = A.racine->droite;
        PROFONDEUR(droite, x);
        temp--;
    }
    
    if (temp == 0 && !trouve) {
        printf("Le noeud %d n'a pas ete trouve dans l'arbre\n", x);
    }
}

int HAUTEUR(ARB_BIN A) {
    static int compteur = 0;
    static int hauteurMax = 0;
    
    if (A.racine == NULL) {
        return 0;
    }
    
    compteur++;
    
    if (compteur > hauteurMax) {
        hauteurMax = compteur;
    }
    
    ARB_BIN gauche, droite;
    gauche.racine = A.racine->gauche;
    droite.racine = A.racine->droite;
    
    HAUTEUR(gauche);
    HAUTEUR(droite);
    
    compteur--;
    
    if (compteur == 0) {
        int resultat = hauteurMax;
        hauteurMax = 0;
        return resultat;
    }
    
    return 0;
}

int SOM_NOEUDS(ARB_BIN A) {
    if (A.racine == NULL) {
        return 0;
    }
    
    int somme = A.racine->valeur;
    
    ARB_BIN gauche, droite;
    gauche.racine = A.racine->gauche;
    droite.racine = A.racine->droite;
    
    somme += SOM_NOEUDS(gauche);
    somme += SOM_NOEUDS(droite);
    
    return somme;
}

Noeud* creerNoeud(int valeur) {
    Noeud* newnode = (Noeud*)malloc(sizeof(Noeud));
    newnode->valeur = valeur;
    newnode->gauche = NULL;
    newnode->droite = NULL;
    return newnode;
}

int main() {
    ARB_BIN A;
    
    A.racine = creerNoeud(10);
    
    A.racine->gauche = creerNoeud(5);
    A.racine->droite = creerNoeud(15);
    
    A.racine->gauche->gauche = creerNoeud(3);
    A.racine->gauche->droite = creerNoeud(7);
    A.racine->droite->gauche = creerNoeud(12);
    A.racine->droite->droite = creerNoeud(18);
    
    printf("les etiquettes des feuilles sont : \n");
    FEUILLE(A);
    printf("\n\n");
    
    printf("les degres des noeuds sont : \n");
    DEGRE(A);
    printf("\n");
    
    printf("les profondeurs des noeuds sont : \n");
    PROFONDEUR(A, 10);
    PROFONDEUR(A, 3);
    PROFONDEUR(A, 99);
    printf("\n");
    
    printf("Test de la hauteur de l'arbre:\n");
    int h = HAUTEUR(A);
    printf("La hauteur de l'arbre est : %d\n", h);
    
    printf("\nTest de la somme des noeuds:\n");
    int somme = SOM_NOEUDS(A);
    printf("La somme des noeuds de l'arbre est : %d\n", somme);
    
    return 0;
}
