#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct maillon {
  int value;
  struct maillon *next;
  struct maillon *prev;
};


typedef struct maillon * dcll;

dcll init(void){
  dcll liste = malloc(sizeof(struct maillon));
  liste->prev = NULL;
  liste->next = NULL;
  return liste;
}

bool is_empty(dcll liste){
  return (liste->prev == NULL && liste->prev == NULL);

}


void push(int x, dcll liste){
  if (is_empty(liste)) {
    liste->value = x
  }
  else{
    dcll pushed = malloc(sizeof(struct maillon));
    pushed->value = x;
    
  }
}
