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
