//queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct queue_s queue_t;

queue_t *init(void);
bool is_empty(queue_t *s);
int top(queue_t *s);
void push(int x, queue_t *s);
void pop(queue_t *s);

#endif




//queue.c


#include "queue.h"

struct queue_s {
  int *tab;
  int taille;
  int tete;
  int max;
};

queue_t *init(void){
  queue_t *pile = malloc(sizeof(queue_t));
  (*pile).tab = malloc(20*sizeof(int));
  (*pile).taille =  0;
  (*pile).tete = 0;
  (*pile).max = 20;
  return pile;
}

bool is_empty(queue_t *queue){
  return (queue->taille == 0);
}

int top(queue_t *queue){
  assert(! is_empty(queue));
  return queue->tab[queue->tete];
}

void redimensionne(queue_t *queue){
  int *new_tab = malloc(2*queue->max*sizeof(int));
  for(int i ; i<queue->max ; i = i+1){
    new_tab[i] = queue->tab[i];
  }
  free(queue->tab);
  queue->max = queue->max *2;
  queue->tab = new_tab;
}

void push(int elt, queue_t *queue){
  if (queue->taille == queue->max){redimensionne(queue);}
  queue->tab[queue->taille] = elt;
  queue->taille++;
  
}

void pop(queue_t *queue){
  assert(! is_empty(queue));
  queue->taille--;
}
