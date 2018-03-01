#include <stdio.h>
#include <stdlib.h>
 
#include "ride.h"
#include "list.h"
#include "car.h"

void runToStep(Car ** cars , unsigned long Nb , unsigned long Step);


int main()
{
  FILE * file = fopen("c_no_hurry.in","r");

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

  fclose(file); 

  Car ** cars = calloc(Fleet , (sizeof (Car * )));

  for(unsigned long i = 0; i < Fleet; i++)
  {
  	cars[i] = calloc(1,(sizeof (Car)));

  	for(int j = 0; j < 100; j++)
  		cars[i]->rides[j] = -1;
  }

  unsigned long id = 0;

  unsigned long step = 0;

  rides = rides->next;

  while(rides != NULL)
  {
  	if(step < rides->data->earlierStart)
  	{
  		step = rides->data->earlierStart;

  		runToStep(cars , Fleet , step);
  	}


  	assignRide(rides->data , cars , Fleet , step , id);


  	id ++;

  	free(rides->data);

  	list * old = rides;
  	rides = rides->next;

  	free(old);
  }


  free(rides);

  
  FILE * output = fopen("b_chall.out","w");

  for(unsigned long i = 0; i < Fleet; i++)
  {
  	printf("%d\n", cars[i]->it);

  	fprintf(output, "%d", cars[i]->it);

  		for(int j = 0; j < cars[i]->it; j++)
  			fprintf(output, " %d", cars[i]->rides[j]);

  		fprintf(output, "\n");
  }

  fclose(output);

  return 0;
}

void runToStep(Car ** cars , unsigned long Nb , unsigned long Step)
{
	for(unsigned long i = 0; i < Nb; i++)
	{
		if(cars[i]->free == 1)
		{
			if(cars[i]->end <= Step)
				cars[i]->free = 0;
		}
	}
}