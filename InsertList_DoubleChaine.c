#include <stdio.h>
#include <stdlib.h>

// Structure pour un élément de la liste
typedef struct Element {
    int valeur;
    struct Element* precedent;
    struct Element* suivant;
} Element;

// Fonction pour insérer un élément dans une liste triée
void insererElement(Element** tete, int valeur) {
    Element* nouvelElement = (Element*)malloc(sizeof(Element));
    nouvelElement->valeur = valeur;
    nouvelElement->precedent = NULL;
    nouvelElement->suivant = NULL;

    if (*tete == NULL || (*tete)->valeur >= valeur) {
        nouvelElement->suivant = *tete;
        if (*tete != NULL) {
            (*tete)->precedent = nouvelElement;
        }
        *tete = nouvelElement;
    } else {
        Element* actuel = *tete;
        while (actuel->suivant != NULL && actuel->suivant->valeur < valeur) {
            actuel = actuel->suivant;
        }
        nouvelElement->suivant = actuel->suivant;
        nouvelElement->precedent = actuel;
        if (actuel->suivant != NULL) {
            actuel->suivant->precedent = nouvelElement;
        }
        actuel->suivant = nouvelElement;
    }
}

// Fonction pour afficher la liste
void afficherListe(Element* tete) {
    while (tete != NULL) {
        printf("%d ", tete->valeur);
        tete = tete->suivant;
    }
    printf("\n");
}

int main() {
    // Créer une liste
    Element* tete = NULL;

    insererElement(&tete, 5);
    insererElement(&tete, 2);
    insererElement(&tete, 8);
    insererElement(&tete, 3);

    printf("Liste : ");
    afficherListe(tete);

    return 0;
}
