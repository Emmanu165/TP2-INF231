#include <stdio.h>
#include <stdlib.h>

// Structure pour un élément de la liste
typedef struct Element {
    int valeur;
    struct Element* suivant;
} Element;

// Fonction pour supprimer toutes les occurrences d'un élément
void supprimerOccurrences(Element** tete, int valeur) {
    Element* actuel = *tete;
    Element* precedent = NULL;

    while (actuel != NULL) {
        if (actuel->valeur == valeur) {
            if (precedent == NULL) {
                *tete = actuel->suivant;
            } else {
                precedent->suivant = actuel->suivant;
            }
            Element* temp = actuel;
            actuel = actuel->suivant;
            free(temp);
        } else {
            precedent = actuel;
            actuel = actuel->suivant;
        }
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
    Element* tete = (Element*)malloc(sizeof(Element));
    tete->valeur = 1;
    tete->suivant = (Element*)malloc(sizeof(Element));
    tete->suivant->valeur = 2;
    tete->suivant->suivant = (Element*)malloc(sizeof(Element));
    tete->suivant->suivant->valeur = 2;
    tete->suivant->suivant->suivant = (Element*)malloc(sizeof(Element));
    tete->suivant->suivant->suivant->valeur = 3;
    tete->suivant->suivant->suivant->suivant = NULL;

    printf("Liste avant suppression : ");
    afficherListe(tete);

    int valeurASupprimer;
    printf("Entrez la valeur à supprimer : ");
    scanf("%d", &valeurASupprimer);

    supprimerOccurrences(&tete, valeurASupprimer);

    printf("Liste après suppression : ");
    afficherListe(tete);

    return 0;
}
