#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct maillon {
    int numero;
    struct maillon *suiv, *prec;
} MAILLON, *PTR;

typedef struct lcb {
    PTR tete, queue;
} LCB;

typedef struct abr {
    char nom[50];           
    LCB pages;            
    struct abr *gauche;   
    struct abr *droite;    
} *ABR;

LCB ajout_numero(int num, LCB numeros) {
    PTR new_node = (PTR)malloc(sizeof(MAILLON));
    new_node->numero = num;
    new_node->suiv = NULL;
    new_node->prec = NULL;

    if (numeros.tete == NULL) {
        numeros.tete = new_node;
        numeros.queue = new_node;
        return numeros;
    }

    if (num < numeros.tete->numero) {
        new_node->suiv = numeros.tete;
        numeros.tete->prec = new_node;
        numeros.tete = new_node;
        return numeros;
    }

    if (num > numeros.queue->numero) {
        new_node->prec = numeros.queue;
        numeros.queue->suiv = new_node;
        numeros.queue = new_node;
        return numeros;
    }

    PTR temp = numeros.tete;
    while (temp != NULL && temp->numero < num) {
        if (temp->numero == num) {
            free(new_node);
            return numeros;
        }
        temp = temp->suiv;
    }

    new_node->prec = temp->prec;
    new_node->suiv = temp;
    temp->prec->suiv = new_node;
    temp->prec = new_node;

    return numeros;
}

ABR ajout_nompropre(char* nom, int t[], int nombre, ABR a) {
    if (a == NULL) {
        ABR nouveau = (ABR)malloc(sizeof(struct abr));
        strcpy(nouveau->nom, nom);
        nouveau->pages.tete = NULL;
        nouveau->pages.queue = NULL;
        nouveau->gauche = NULL;
        nouveau->droite = NULL;
        
        for (int i = 0; i < nombre; i++) {
            nouveau->pages = ajout_numero(t[i], nouveau->pages);
        }
        return nouveau;
    }
    
    int cmp = strcmp(nom, a->nom);
    
    if (cmp < 0) {
        a->gauche = ajout_nompropre(nom, t, nombre, a->gauche);
    } else if (cmp > 0) {
        a->droite = ajout_nompropre(nom, t, nombre, a->droite);
    } else {
       printf("Le nom que vous voulez ajouter existe déjà \n");
        for (int i = 0; i < nombre; i++) {
            a->pages = ajout_numero(t[i], a->pages);
        }
    }
    
    return a;
}

ABR supprimer_numero(char *nom, int numero, ABR a) {
    if (a == NULL) {
        printf("l'arbre est vide\n");
        return NULL;
    }
    int cmp = strcmp(nom, a->nom);
    
    if (cmp < 0) {
        a->gauche = supprimer_numero(nom, numero, a->gauche);
    } else if (cmp > 0) {
        a->droite = supprimer_numero(nom, numero, a->droite);
    } else {

        if (a->pages.tete == NULL) {
            printf("Aucun numéro de page \n");
            return a;
        }
        PTR courant = a->pages.tete;
        while (courant != NULL && courant->numero != numero) {
            courant = courant->suiv;
        }
        if (courant == NULL) {
            printf("Le numéro %d n'existe pas pour ce nom\n", numero);
            return a;
        }
        if (a->pages.tete == a->pages.queue) {
            a->pages.tete = NULL;
            a->pages.queue = NULL;
        }
        else if (courant == a->pages.tete) {
            a->pages.tete = courant->suiv;
            a->pages.tete->prec = NULL;
        }
        else if (courant == a->pages.queue) {
            a->pages.queue = courant->prec;
            a->pages.queue->suiv = NULL;
        }
        else {
            courant->prec->suiv = courant->suiv;
            courant->suiv->prec = courant->prec;
        }
        free(courant);
    }
    
    return a;
}

void afficher_index(ABR a) {
    if (a == NULL)
        return;

    afficher_index(a->gauche);
    printf("%s : ", a->nom);
    PTR temp = a->pages.tete;
    if (temp == NULL) {
        printf("aucune page");
    } else {
        while (temp != NULL) {
            printf("%d", temp->numero);
            if (temp->suiv != NULL) {
                printf(", ");
            }
            temp = temp->suiv;
        }
    }
    printf("\n");
    afficher_index(a->droite);
}

// Fonction pour compter le nombre de nœuds dans l'arbre
int compter_noeuds(ABR a) {
    if (a == NULL)
        return 0;
    return 1 + compter_noeuds(a->gauche) + compter_noeuds(a->droite);
}

// Fonction pour transformer l'arbre en une liste chaînée (première étape de DSW)
ABR arbre_vers_liste(ABR a) {
    if (a == NULL)
        return NULL;
    
    // Traiter d'abord le sous-arbre droit
    a->droite = arbre_vers_liste(a->droite);
    
    // Traiter ensuite le sous-arbre gauche
    if (a->gauche != NULL) {
        ABR temp = a->gauche;
        // Trouver le nœud le plus à droite du sous-arbre gauche
        while (temp->droite != NULL) {
            temp = temp->droite;
        }
        // Faire pointer ce nœud vers la racine
        temp->droite = a;
        // Faire pointer la racine vers le sous-arbre gauche
        a = a->gauche;
        // Mettre à NULL le pointeur gauche de l'ancienne racine
        temp->droite->gauche = NULL;
    }
    
    return a;
}

// Fonction pour transformer la liste en arbre équilibré (deuxième étape de DSW)
ABR liste_vers_arbre(ABR a, int n) {
    if (n <= 0 || a == NULL)
        return NULL;
    
    // Calculer le nombre de nœuds dans le sous-arbre gauche
    int m = 1;
    while (m <= n) {
        m = 2 * m + 1;
    }
    m = m / 2;
    
    // Trouver le nœud médian
    ABR temp = a;
    for (int i = 0; i < n - m - 1; i++) {
        temp = temp->droite;
    }
    
    // Créer la nouvelle racine
    ABR racine = temp->droite;
    temp->droite = NULL;
    
    // Construire récursivement les sous-arbres
    racine->gauche = liste_vers_arbre(a, n - m - 1);
    racine->droite = liste_vers_arbre(racine->droite, m);
    
    return racine;
}

// Fonction principale pour rééquilibrer l'arbre
ABR reequilibrer_arbre(ABR a) {
    if (a == NULL)
        return NULL;
    
    // Compter le nombre de nœuds
    int n = compter_noeuds(a);
    
    // Transformer l'arbre en liste
    a = arbre_vers_liste(a);
    
    // Transformer la liste en arbre équilibré
    a = liste_vers_arbre(a, n);
    
    return a;
}


