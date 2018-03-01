#include <stdio.h>
#include <stdlib.h>
 
#include "matrix.h"
 
int main()
{
  FILE * file = fopen("example.in","r");

  char r_s[5], c_s[5], l_s[5] , h_s[5];

  fscanf(file, "%s %s %s %s\n" , r_s , c_s , l_s , h_s);

  int Row = strtol(r_s , 0 , 10);
  int Col = strtol(c_s , 0 , 10);
  int Least = strtol(l_s , 0 , 10);
  int High = strtol(h_s , 0 , 10);

  printf("%d\n", Row);
  printf("%d\n", Col);
  printf("%d\n", Least);
  printf("%d\n", High);

  matrix pizza = load_matrix(file,Row,Col);

  print_matrix(pizza);

  free_matrix(pizza);

  fclose(file); 
 
  return 0;
}
