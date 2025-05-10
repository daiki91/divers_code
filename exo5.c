#include <stdio.h>
#include <stdlib.h>

typedef struct maillon {
    int indice;       
    float valeur;       
    struct maillon *suivant; 
} MAILLON, *PTR;


PTR nouveau_maillon(int i, float xi, PTR s) {
    PTR newnode = (PTR)malloc(sizeof(MAILLON));
    newnode->indice = i;
    newnode->valeur = xi;
    newnode->suivant = s;
    return newnode;
}

PTR vecteur_creux(float t[], int n) {
    PTR temp = NULL;
    
    for(int i = 0; i < n; i++) {
        if(t[i] != 0) {
            if(temp == NULL) {
                temp = nouveau_maillon(i, t[i], NULL);
            } else {
                PTR p = temp;
                while(p->suivant != NULL) {
                    p = p->suivant;
                }
                p->suivant = nouveau_maillon(i, t[i], NULL);
            }
        }
    }
    return temp;
}

PTR somme(PTR a, PTR b) {
    if(a == NULL) return b;
    if(b == NULL) return a;
    
    if(a->indice < b->indice) 
        return nouveau_maillon(a->indice, a->valeur, somme(a->suivant, b));
    if(b->indice < a->indice) 
        return nouveau_maillon(b->indice, b->valeur, somme(a, b->suivant));
    
    float s = a->valeur + b->valeur;
    return s != 0 ? nouveau_maillon(a->indice, s, somme(a->suivant, b->suivant)): somme(a->suivant, b->suivant);
}

void afficher_vecteur(PTR v) {
    PTR p = v;
    while(p != NULL) {
        printf("[%d,%.2f]--> ", p->indice, p->valeur);
        p = p->suivant;
    }
    printf("NULL");
}

int main() {
    
    printf("exemple de vecteur creux de l'enonce\n");
    float t1[] = {0, 0, 9, 5, 0, 7, 0, 3, 0, 0};
    PTR vecteur_creux1 = vecteur_creux(t1, 10);
    printf("vecteur_creux1 = ");
    afficher_vecteur(vecteur_creux1);
    
    
    printf("\n");
    float t2[] = {0, 0, 1, 5, 0, 3, 0, 4, 0, 0};
    PTR vecteur_creux2 = vecteur_creux(t2, 10);
    printf("vecteur_creux2 = ");
    afficher_vecteur(vecteur_creux2);
    PTR vecteur_creux3 = somme(vecteur_creux1, vecteur_creux2);
    printf("\nvecteur_creux1 + vecteur_creux2 = ");
    afficher_vecteur(vecteur_creux3);
    
    printf("\nTest 3 :\n");
    float t4[] = {0, 0, 0, -5, 0, -7, 0, -3, 0, 0};
    PTR vecteur_creux4 = vecteur_creux(t4, 10);
    printf("vecteur_creux4 = ");
    afficher_vecteur(vecteur_creux4);
    
    PTR vecteur_creux5 = somme(vecteur_creux1, vecteur_creux4);
    printf("\nvecteur_creux1 + vecteur_creux4 = ");
    afficher_vecteur(vecteur_creux5);
    
    return 0;
}

