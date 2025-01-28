// pile.h
#ifndef PILE_H
#define PILE_H

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Pile Pile;

Pile *init(void);
bool est_vide(Pile *pile);
int sommet_pile(Pile *pile);
void empiler(int x, Pile *pile);
void depiler(Pile *pile);

#endif // PILE_H

// pile.c
#include "pile.h"

struct Pile {
    int *tab;
    int taille;
    int max;
};

Pile *creer_pile(void) {
    Pile *pile = malloc(sizeof(Pile));
    if (!pile) {
        fprintf(stderr, "Erreur : allocation de memoire pour la pile\n");
        return NULL;
    }
    pile->tab = malloc(20 * sizeof(int));
    if (!pile->tab) {
        fprintf(stderr, "Erreur : allocation de memoire pour les elements de la pile\n");
        free(pile);
        return NULL;
    }
    pile->taille = 0;
    pile->max = 20;
    return pile;
}

bool est_vide(Pile *pile) {
    return (pile->taille == 0);
}

int sommet_pile(Pile *pile) {
    assert(!est_vide(pile));
    return pile->tab[pile->taille - 1];
}

void redimensionner(Pile *pile) {
    int *new_tab = malloc(2 * pile->max * sizeof(int));
    for (int i = 0; i < pile->taille; i++) {
        new_tab[i] = pile->tab[i];
    }
    free(pile->tab);
    pile->tab = new_tab;
    pile->max *= 2;
}

void empiler(int x, Pile *pile) {
    if (pile->taille == pile->max) {
        redimensionner(pile);
    }
    pile->tab[pile->taille++] = x;
}

void depiler(Pile *pile) {
    assert(!est_vide(pile));
    pile->taille--;
}

// Exemple d'utilisation
#include <stdio.h>

int main() {
    Pile *ma_pile = creer_pile();

    empiler(10, ma_pile);
    empiler(20, ma_pile);
    empiler(30, ma_pile);

    printf("Sommet de la pile: %d\n", sommet_pile(ma_pile));

    depiler(ma_pile);
    printf("Apres depiler, sommet: %d\n", sommet_pile(ma_pile));

    depiler(ma_pile);
    depiler(ma_pile);

    printf("Pile vide: %s\n", est_vide(ma_pile) ? "oui" : "non");

    free(ma_pile->tab);
    free(ma_pile);

    return 0;
}
