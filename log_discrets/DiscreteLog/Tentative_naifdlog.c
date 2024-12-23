#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

/* Tous les calculs sont effectues modulo 2**31 - 1 */
/* Les nombres sont representes par leur ecriture en binaire, en tant que chaine de caracteres de taille 31 */

char zero[] = "0000000000000000000000000000000";
char un[] = "0000000000000000000000000000001";
char sept[] = "0000000000000000000000000000111"; // A completer !
char q[] = "1111111111111111111111111111111"; //2^31-1

char sqrtq[] = "0000000000000001011010100000101"; //46341

void print_endline(char s[])
{
  printf("%s\n",s);
}

void print_bool(bool b)
{
  if (b)
    {
      printf("true\n");
    }
  else
    {
      printf("false\n");
    }
}

int str_len(char s[])
{
  int cpt = 0;
  for (int i = 0 ; s[i] != '\0'; i = i + 1){
      cpt++;
    }
    return cpt;
}






bool is_equal(char a[], char b[]) // a == b
{
  assert (31 == strlen(a));
  assert (31 == strlen(b));
  for (int i=0 ; a[i] != '\0'; i++) {
    if (a[i] != b[i]) {
      return false;
    }
    
  }
  return true;

}

void simplifier(char a[]){
  if (is_equal(a,q)) {
    for (int i = 0; i<31;i=i+1){
      a[i] = '0';
    }
  }
}



bool is_greater(char a[], char b[]) // a > b
{
  assert (31 == strlen(a));
  assert (31 == strlen(b));
  simplifier(a);simplifier(b);
  for (int i=0 ; a[i] != '\0'; i++)
    {
    if (a[i] > b[i]) {
      return true;
    }
    
  }
  return false;

}

void negate(char a[]) // a = -a
{
  assert (31 == strlen(a));
  for (int i=0; i!= 31;i++){
    if (a[i] == '0') {
      a[i] = '1';
    }
    else {
      a[i] = '0';
    }
  }
  simplifier(a);


}

void incr(char a[]) // a = a + 1
{
  assert (31 == strlen(a));
  simplifier(a);

  int i = 30;
  while ( (a[i] == '1') && (i>0)){
    i--;
  }
  a[i] = '1';
  for (int j = i+1;a[j] != '\0'; j=j+1){
    a[j] = '0';
  }
  simplifier(a);
}

void decr(char a[]) {
  assert (31 == strlen(a));
  if (is_equal(a,zero)) {
    for (int i = 0; i<31;i=i+1){
      a[i] = '1';
    }
  }
  int i = 30;
  while ( (a[i] == '0') && (i>0)){
    i--;
  }
  a[i] = '0';
  for (int j = i+1;a[j] != '\0'; j=j+1){
    a[j] = '1';
  }
}

void add_to(char a[], char b[]) // a = a + b
{
  assert (31 == strlen(a));
  assert (31 == strlen(b));
  bool retenue = false;
  simplifier(a); simplifier(b);
  for (int i=30;i>0;i--){
    if (a[i] == '1' && b[i] == '1') {
      if (retenue == true) {
	a[i] = '1';
      }

      else {
	a[i] = '0';
      }
      retenue = true;
    }

    else if (a[i] != b[i]) {
      if (retenue == true) {
	a[i] = '0';
      }
      else{
	a[i] = '1';
	retenue = false;
      }
    }
    
    else if (a[i] == '0' && b[i] == '0'){
      if (retenue == true) {
	a[i] = '1';
	retenue = false;
      }
      else{
	a[i] = '0';
      }
    }
  }
  simplifier(a);

}

void mult_by(char a[], char b[]) // a = a * b
{
  assert (31 == strlen(a));
  assert (31 == strlen(b));
  simplifier(a);simplifier(b);
  char b2[32];
  strncpy(b2,b,32);
  if (is_equal(b,zero) || is_equal(a,zero)){
    strncpy(a,zero,32);
  }
  else{
    while (! is_equal(b2,un)) {
      add_to(a,a);
      decr(b2);
    }
  }

  
  /* TODO */

}

void expo(char a[], char b[]) // a = a ** b
{
  assert (31 == strlen(a));
  assert (31 == strlen(b));
  simplifier(a);simplifier(b);
  if (is_equal(b,zero) || is_equal(a,un)) {
    strncpy(a,un,32);
  }
  else{
    char b2[32]; char a2[32];
    strncpy(b2,b,32); strncpy(a2,a,32);
    while (! is_equal(b2,un)) {
      printf("\n%s   ", a2);
      printf("%s   ", a);
      printf("%s\n   ", b2);
      mult_by(a,a2);
      decr(b2);
    }
  }
}

void naif_dlog(char a[], char b[]) // a = dlog_b(a)
{
  assert (31 == strlen(a));
  assert (31 == strlen(b));
  char res[] = strncpy(zero,32);
  char calc[] = strncpy(b,32);
  expo(calc, res);
  while (!is_equal(a,calc)){
    calc = strncpy(b);
    expo(calc, res);
    incr(res);
  }
  a = strncpy(calc,32);
}

void dlog(char a[], char b[]) // baby step - giant step
{
  assert (31 == strlen(a));
  assert (31 == strlen(b));

  /* TODO */

}

int main(int argc, char *argv[])
{
  char target0[] = "1111111111111111111111111111110";
  char target1[] = "0011111111001000010000000100110";
  char target2[] = "1011010001101011101011001100111";
  char x[] = "0111111111111111111111111111111";
  /*
  printf("len de test (str_len): %d", str_len("test"));

  printf("Is equal : ");
  print_bool(is_equal("1011010001101011101011001100111","1011010001101011101011001100111"));
  print_bool(is_equal("1011010001101011101011001100111","1011010001101011101011001100110"));

  printf("Is greater : ");
  print_bool(is_greater("1011010001101011101011001100111","1011010001101011101011001100111"));
  print_bool(is_greater("1011010001101011101011001100111","1011010001101011101011001100110"));


  //NEGATION
  printf("negate 1011010001101011101011001100111 :");
  char tab1[] = "1011010001101011101011001100111";
  negate(tab1);
  printf("%s\n\n", tab1);




   
  //INCREMENTATION
  printf("increment 1011010001101011101011001100111 : ");
  char tab2[] = "1011010001101011101011001100111";
  incr(tab2);
  printf("%s\n", tab2);


  
  printf("increment 1111111111111111111111111111111 : ");

  char tab3[] = "1111111111111111111111111111111";
  incr(tab3);
  printf("%s\n", tab3);
  printf("increment 1111111111111111111111111111110 : ");
  char tab4[] = "1111111111111111111111111111110";
  incr(tab4);
  printf("%s\n", tab4);

  //Addition
  printf("Addition 0000000000000000000000000000011 + 0000000000000000000000000000010 : ");
  char tab5[] = "0000000000000000000000000000011";
  char tab6[] = "0000000000000000000000000000010";
  add_to(tab6,tab5);
  printf("%s\n",tab6); 

  printf("Addition 0000000000000000000000000000001 + 0000000000000000000000000000001 : ");
  char tab7[] = "0000000000000000000000000000001";
  char tab8[] = "0000000000000000000000000000001";
  /*assert(is_equal(tab7,q));
  assert(31 == strlen(q));
  add_to(tab7,tab8);
  printf("%s\n",tab7);



  printf("Decrementation 1111111111111111111111111111111 : ");
  char tab9[] = "1111111111111111111111111111111";
  decr(tab9);
  printf("%s\n", tab9);
  incr(tab9);
  printf("%s\n", tab9);
  
  
  
  printf("Multiplication : 0000000000000000000000000000011 * 0000000000000000000000000000011 = ");
  char tab10[] = "0000000000000000000000000000011";
  char tab11[] = "0000000000000000000000000000011";
  mult_by(tab10,tab11);
  printf("%s\n",tab10);

  printf("Exponentiation : 0000000000000000000000000000011 ^ 0000000000000000000000000000010 = ");
  char tab12[] = "0000000000000000000000000000011";
  char tab13[] = "0000000000000000000000000000010";
  expo(tab12,tab13);
  printf("%s\n",tab12);
  
     */

  printf("DLOG NAIF ///\n");
  naif_dlog(target0,7);
  printf("Dlog_7(target0) == x: %s",is_equal(x,target0) ? "true" : "false");
  return 0;



}
