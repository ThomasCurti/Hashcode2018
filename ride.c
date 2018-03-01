#include "ride.h"
#include "list.h"
#include "car.h"

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

void printRide(Ride * ride)
{
	printf("Ride : ");

	printf("%lu ", ride->distance);

	printf("Begin at %lu - " , ride->earlierStart);
	printf("End at%lu\n", ride->lastedFinish);
}

unsigned long assignRide(Ride * ride , Car ** cars , unsigned long Fleet , unsigned long step , unsigned long id)
{
	unsigned long min = 1000000000;

	Car * car;

	for(unsigned long i = 0; i < Fleet ; i++)
	{
		if(cars[i]->free == 0 && min > calculateDistanceToRide(cars[i] , ride))
		{
			min = calculateDistanceToRide(cars[i] , ride);
			car = cars[i];
		}
	}

	if(min < 1000000000)
	{
		car->free = 1;
		
		unsigned long steparrived = step + min;

		if( steparrived < ride->earlierStart)
			steparrived = ride->earlierStart;

		car->end = steparrived + ride->distance;

		car->rides[car->it] = id;
		car->it ++;

		car->x = ride->end.x;
		car->y = ride->end.y;
	}

	return min;
}