#include <stdio.h>
#include <stdlib.h>
 
#include "ride.h"
 
int main()
{
  FILE * file = fopen("a_example.in","r");

  char r_s[6], c_s[6], f_s[5] , n_s[5] , b_s[6] , t_s[10];

  fscanf(file, "%s %s %s %s %s %s\n" , r_s , c_s , f_s , n_s , b_s , t_s);

  unsigned long Row = strtol(r_s , 0 , 10);
  unsigned long Col = strtol(c_s , 0 , 10);
  unsigned long Fleet = strtol(f_s , 0 , 10);
  unsigned long Nb = strtol(n_s , 0 , 10);
  unsigned long Bonus = strtol(b_s,0,10);
  unsigned long Time = strtol(t_s,0,10);

  Ride ** rides = malloc(sizeof(Ride*) * Nb);

  for(unsigned long i = 0; i < Nb; i++)
  {
  	rides[i] = parseRide(file);  
  	printRide(rides[i]);
  }

  fclose(file); 
 
  for(unsigned long i = 0; i < Nb; i++)
  	free(rides[i]);

  free(rides);

  return 0;
}
