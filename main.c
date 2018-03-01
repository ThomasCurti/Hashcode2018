#include <stdio.h>
#include <stdlib.h>
 
#include "ride.h"
#include "list.h"

int main()
{
  FILE * file = fopen("e_high_bonus.in","r");

  char r_s[100], c_s[100], f_s[100] , n_s[100] , b_s[100] , t_s[100];

  fscanf(file, "%s %s %s %s %s %s\n" , r_s , c_s , f_s , n_s , b_s , t_s);

  unsigned long Row = strtol(r_s , 0 , 10);
  unsigned long Col = strtol(c_s , 0 , 10);
  unsigned long Fleet = strtol(f_s , 0 , 10);
  unsigned long Nb = strtol(n_s , 0 , 10);
  unsigned long Bonus = strtol(b_s,0,10);
  unsigned long Time = strtol(t_s,0,10);

  list * rides = malloc(sizeof(list));
  
  list_init(rides);

  for(unsigned long i = 0; i < Nb; i++)
  {
  	list * elm = malloc(sizeof(list));
  	
  	elm->data = parseRide(file);

  	list_insert(rides , elm);  
  }

  list_print(rides);

  list_clear(rides);

  free(rides);

  fclose(file); 
 
  return 0;
}
