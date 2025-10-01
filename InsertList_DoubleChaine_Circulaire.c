#include <stdio.h>
#include <stdlib.h>

// Structure pour un élément de la liste
typedef struct Element {
    int valeur;
    struct Element* precedent;
    struct Element* suivant;
} Element;

// Fonction pour insérer un élément en tête
void insererEnTete(Element** tete, int valeur) {
    Element* nouvelElement = (Element*)malloc(sizeof(Element));
    nouvelElement->valeur = valeur;

    if (*tete == NULL) {
        *tete = nouvelElement;
        nouvelElement->suivant = *tete;
        nouvelElement->precedent = *tete;
    } else {
        Element* dernier = (*tete)->precedent;
        nouvelElement->suivant = *tete;
        nouvelElement->precedent = dernier;
        dernier->suivant = nouvelElement;
        (*tete)->precedent = nouvelElement;
        *tete = nouvelElement;
    }
}

// Fonction pour insérer un élément en queue
void insererEnQueue(Element** tete, int valeur) {
    Element* nouvelElement = (Element*)malloc(sizeof(Element));
    nouvelElement->valeur = valeur;

    if (*tete == NULL) {
        *tete = nouvelElement;
        nouvelElement->suivant = *tete;
        nouvelElement->precedent;
    } else {
        Element* dernier = *tete;
        while (dernier->suivant != *tete) {
            dernier = dernier->suivant;
        }
        dernier->suivant = nouvelElement;
        nouvelElement->suivant = *tete;
    }
}

// Fonction pour afficher la liste
void afficherListe(Element* tete) {
    if (tete == NULL) return;

    Element* actuel = tete;
    do {
        printf("%d ", actuel->valeur);
        actuel = actuel->suivant;
    } while (actuel != tete);
    printf("\n");
}

int main() {
    // Créer une liste
    Element* tete = NULL;

    insererEnTete(&tete, 5);
    insererEnQueue(&tete, 2);
    insererEnTete(&tete, 8);
    insererEnQueue(&tete, 3);

    printf("Liste : ");
    afficherListe(tete);

    return 0;
}