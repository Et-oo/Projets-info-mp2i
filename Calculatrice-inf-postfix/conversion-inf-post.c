#include <stdlib.h>
#include <stdio.h>
#include "pile.h"
#include <assert.h>
//https://www.geeksforgeeks.org/convert-infix-expression-to-postfix-expression/
const char operateurs[] =  "^*/-+";
const int nb_op = 5;
const char entiers[] = "1234567890!";
const int nb_int = 11; // Je prend aussi en compte le ! puisque qu'il ne bouge pas en postfixé

bool is_in_string(char x, const char tab[], int len){
  for (int i = 0 ; i<len;i++){
    if (tab[i] == x) {return true;}
  }
  return false;
}


bool parenthesage(char chaine[], int len){
  int i = 0;
  Pile *parentheses = init();
  while (chaine[i] != '\0'){
    if (chaine[i] == '('){
      empiler(1,parentheses);
    }
    if (chaine[i] == ')') {
      if (! est_vide(parentheses)){
	depiler(parentheses);
      }
      else{
	return false;
      }
    }
  }
  return true;
}


bool est_simple(char chaine[],int len){
  int cptint = 0;
  int cptop = 0;
  for (int i =0;i<len;i++){
    if (is_in_string(chaine[i], operateurs, nb_op)){
      cptop++;
    }
    if (is_in_string(chaine[i], entiers, 10)){
	if (! is_in_string(chaine[i-1], entiers, 10)){
	  cptint++;
	}
    }
      
    
  
  }
  return ((cptint == 2) && (cptop == 1));
}

bool est_prio(char op1, char op2){// Renvoie true si op1 est prioritaire strictement sur op2 (si ils ont la même priorité : false)
  assert( is_in_string(op1,operateurs,nb_op) && is_in_string(op2,operateurs,nb_op));
  if (op2 == '^'){return false;}
  if (op1=='^'){return true;}
  if (is_in_string(op1,"*/",2 && (! is_in_string(op2,"*/",2)))){return true;}
  return false;
}


void Conversion(char chaine[], int a){
  char *infixe = malloc(a * sizeof(char));
  int charindex = 0;
  Pile *p_Operateurs = init();
  for(int i =0;i<a;i++){                                   //Scanner la liste de gauche à droite
    char car = chaine[i]
    if (is_in_string(car, entiers, 10)) {            //Si le caractère est un operande on le met dans l'output
	infixe[charindex] =  car;
	charindex++;
      }
    else{                                                  //Sinon C'est un opérateur : 
      if (est_prio(car,
      if (is_in_string(chaine[i], operateurs,nb_op)){
	  empiler(chaine[i],p_Operateurs);
	}
      
    }
    
  }
  
}





