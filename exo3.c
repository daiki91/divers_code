#include <stdio.h>
#include <stdlib.h>

typedef struct Maillon {
    int valeur;
    struct Maillon* suivant;
} Maillon;


Maillon* liste1 = NULL;
Maillon* liste2 = NULL;
Maillon* liste3 = NULL;


Maillon* creer_liste() {
    Maillon* liste = NULL;
    Maillon* dernier = NULL;

    for(int i = 0; i < 10; i++) {
        Maillon* newnode = (Maillon*)malloc(sizeof(Maillon));
        printf("Entrez la valeur %d : ", i+1);
        scanf("%d", &newnode->valeur);
        newnode->suivant = NULL;

        if(liste == NULL) {
            liste = newnode;
            dernier = newnode;
        } else {
            dernier->suivant = newnode;
            dernier = newnode;
        }
    }
    return liste;
}

int egalite_listes(Maillon* l1, Maillon* l2) {
    Maillon* temp1 = l1;
    Maillon* temp2 = l2;

    while(temp1 != NULL && temp2 != NULL) {
        if(temp1->valeur != temp2->valeur){
            printf("\nLes listes sont differentes\n");
            return 0;
        }
         
            
        temp1 = temp1->suivant;
        temp2 = temp2->suivant;
    }
    if(temp1 == NULL && temp2 == NULL){
        printf("\nLes listes sont egales\n");
        return 1;
        
    }
    else{
        printf("\nLes listes sont differentes\n");
        return 0;
    }
   
}


void concatenation_newlist(Maillon* l1, Maillon* l2, Maillon** l3) {
    *l3 = NULL;
    Maillon* dernier = NULL;

    Maillon* temp = l1;
    while(temp != NULL) {
        Maillon* newnode = (Maillon*)malloc(sizeof(Maillon));
        newnode->valeur = temp->valeur;
        newnode->suivant = NULL;

        if(*l3 == NULL) {
            *l3 = newnode;
            dernier = newnode;
        } else {
            dernier->suivant = newnode;
            dernier = newnode;
        }
        temp = temp->suivant;
    }

    temp = l2;
    while(temp != NULL) {
        Maillon* newnode = (Maillon*)malloc(sizeof(Maillon));
        newnode->valeur = temp->valeur;
        newnode->suivant = NULL;

        dernier->suivant = newnode;
        dernier = newnode;
        temp = temp->suivant;
    }
}

void concatenationsimple(Maillon** l1, Maillon* l2) {
    if(*l1 == NULL) {
        *l1 = l2;
        return;
    }

    Maillon* temp = *l1;
    while(temp->suivant != NULL) {
        temp = temp->suivant;
    }

    temp->suivant = l2;
}


void afficher_liste(Maillon* debut) {
    Maillon* temp = debut;
    printf("Liste : ");
    while(temp != NULL) {
        printf("%d -> ", temp->valeur);
        temp = temp->suivant;
    }
    printf("NULL\n");
}

int main() {
    printf("Creation de la premiere liste :\n");
    liste1 = creer_liste();
    printf("Premiere liste :\n");
    afficher_liste(liste1);

    printf("\nCreation de la deuxieme liste :\n");
    liste2 = creer_liste();
    printf("Deuxieme liste :\n");
    afficher_liste(liste2);

    egalite_listes(liste1, liste2);

    printf("\nConcatenation dans une troisieme liste :\n");
    concatenation_newlist(liste1, liste2, &liste3);
    afficher_liste(liste3);

    printf("\nConcatenation sans creer une troisieme liste :\n");
    concatenationsimple(&liste1, liste2);
    afficher_liste(liste1);
}   