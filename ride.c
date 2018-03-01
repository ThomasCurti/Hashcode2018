#include "ride.h"
#include "list.h"

Ride * parseRide(FILE * file)
{
	char a_s[6], b_s[6], x_s[6] , y_s[6] , s_s[10] , f_s[10];

	fscanf(file, "%s %s %s %s %s %s\n" , a_s , b_s , x_s , y_s , s_s , f_s);

	Ride * res = malloc(sizeof(Ride));

	res->start.x = strtol(a_s , 0 , 10);;
	res->start.y = strtol(b_s , 0 , 10);

	res->end.x = strtol(x_s , 0 , 10);
	res->end.y = strtol(y_s , 0 , 10);

	res->earlierStart = strtol(s_s , 0 , 10);
	res->lastedFinish = strtol(f_s, 0 ,10);

	res->distance = abs(res->start.x - res->end.x) + abs(res->start.y - res->end.y);

	res->lastedStart = res->lastedFinish - res->distance;

	return res;
}

void travel() {

	FILE * file = fopen("a_example.in","r");

  char r_s[6], c_s[6], f_s[5] , n_s[5] , b_s[6] , t_s[10];

  fscanf(file, "%s %s %s %s %s %s\n" , r_s , c_s , f_s , n_s , b_s , t_s);

  unsigned long Row = strtol(r_s , 0 , 10);
  unsigned long Col = strtol(c_s , 0 , 10);
  unsigned long Fleet = strtol(f_s , 0 , 10);
  unsigned long Nb = strtol(n_s , 0 , 10);
  unsigned long Bonus = strtol(b_s,0,10);
  unsigned long Time = strtol(t_s,0,10);

  //Ride ** rides = malloc(sizeof(Ride*) * Nb);

  for(unsigned long i = 0; i < Nb; i++)
  {
  	rides[i] = parseRide(file);
  	//printRide(rides[i]);
  }

  fclose(file);

	Car ** cars = malloc(sizeof(Car*) * Fleet);

	for(unsigned long k = 0; k < Fleet; k++)
	{
		cars[k] = malloc(sizeof(Car));

		cars[k] -> x = 0;
		cars[k] -> y = 0;
	}

	unsigned long value = 0;
	unsigned long var = 0;

	unsigned long *isOccuped = calloc(sizeof(unsigned long), Fleet);

	unsigned long nbEtapes = 0;
	list *rides = rides->next;
	while(rides != NULL)
	{
		while(nbEtapes != rides->data->earlierStart)
		{
			nbEtapes++;
			for(unsigned long k = 0; k < Fleet; k++)
			{
				if (isOccuped[k] != 0)
					isOccuped--;
			}
		}
		//int value = calculateDistanceToRide(, )
		/*for(unsigned long i = 0; i < Fleet)
		{
			//calculateDistanceToRide(Car * car, Ride * ride)
		}*/
		rides = rides->next;
	}



/*		for(unsigned long i = 0; i < Nb; i++)
		{
			value = calculateDistanceToRide(cars[0], rides[i]);
			var = 0;
			for(unsigned long j = 0; j < Fleet; j++)
			{
				if(isOccuped[j] == 0)
				{
					if(value > calculateDistanceToRide(cars[j], rides[i]))
					{
							var = j;
							value = calculateDistanceToRide(cars[j], rides[i]);
					}
				} else {
					isOccuped[j] -= 1;
				}
			}
			isOccuped[var] = rides[i]->distance;
			cars[var]->x = rides[i]->end.x;
			cars[var]->y = rides[i]->end.y;
			printf("%lu\n", var);

		}*/




}


unsigned long calculateDistanceToRide(Car * car, Ride * ride)
{
	unsigned long res = 0;

	res = abs(car->x-ride->start.x) + abs(car->y-ride->start.y);
	return res;
}


void printRide(Ride * ride)
{
	printf("Ride : ");

	printf("%lu ", ride->distance);

	printf("Begin at %lu - " , ride->earlierStart);
	printf("End at%lu\n", ride->lastedFinish);
}
