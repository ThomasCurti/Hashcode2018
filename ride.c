#include "ride.h"

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
	printf("End at %lu\n", ride->lastedFinish);
}