// pile.h
#ifndef PILE_H
#define PILE_H

#include <stdbool.h>

// Definition d'une structure pour une pile
typedef struct Pile {
    int *elements; // tableau dynamique pour stocker les elements
    int capacite;  // taille maximale de la pile
    int sommet;    // indice du sommet actuel de la pile
} Pile;

// Prototypes des fonctions
Pile *creer_pile(int capacite);
void detruire_pile(Pile *pile);
bool est_vide(Pile *pile);
bool est_pleine(Pile *pile);
void empiler(Pile *pile, int valeur);
void depiler(Pile *pile, int *valeur);
int sommet_pile(Pile *pile);

#endif // PILE_H

// pile.c
#include "pile.h"
#include <stdlib.h>
#include <stdio.h>

Pile *creer_pile(int capacite) {
    Pile *pile = (Pile *)malloc(sizeof(Pile));
    if (!pile) {
        fprintf(stderr, "Erreur : allocation de memoire pour la pile\n");
        return NULL;
    }
    pile->elements = (int *)malloc(capacite * sizeof(int));
    if (!pile->elements) {
        fprintf(stderr, "Erreur : allocation de memoire pour les elements de la pile\n");
        free(pile);
        return NULL;
    }
    pile->capacite = capacite;
    pile->sommet = -1;
    return pile;
}

void detruire_pile(Pile *pile) {
    if (pile) {
        free(pile->elements);
        free(pile);
    }
}

bool est_vide(Pile *pile) {
    return pile->sommet == -1;
}

bool est_pleine(Pile *pile) {
    return pile->sommet == pile->capacite - 1;
}

void empiler(Pile *pile, int valeur) {
    if (est_pleine(pile)) {
        fprintf(stderr, "Erreur : la pile est pleine\n");
        return;
    }
    pile->elements[++pile->sommet] = valeur;
}

void depiler(Pile *pile, int *valeur) {
    if (est_vide(pile)) {
        fprintf(stderr, "Erreur : la pile est vide\n");
        return;
    }
    *valeur = pile->elements[pile->sommet--];
}

int sommet_pile(Pile *pile) {
    if (est_vide(pile)) {
        fprintf(stderr, "Erreur : la pile est vide\n");
        return -1; // Valeur d'erreur
    }
    return pile->elements[pile->sommet];
}

// Exemple d'utilisation
#include <stdio.h>

int main() {
    Pile *ma_pile = creer_pile(5);

    empiler(ma_pile, 10);
    empiler(ma_pile, 20);
    empiler(ma_pile, 30);

    printf("Sommet de la pile: %d\n", sommet_pile(ma_pile));

    int valeur;
    depiler(ma_pile, &valeur);
    printf("Depile: %d\n", valeur);

    depiler(ma_pile, &valeur);
    printf("Depile: %d\n", valeur);

    printf("Pile vide: %s\n", est_vide(ma_pile) ? "oui" : "non");

    detruire_pile(ma_pile);

    return 0;
}
