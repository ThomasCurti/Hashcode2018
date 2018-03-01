#include "car.h"

unsigned long calculateDistanceToRide(Car * car, Ride * ride)
{
	unsigned long res = 0;

	res = abs(car->x-ride->start.x) + abs(car->y-ride->start.y);
	return res;
}
