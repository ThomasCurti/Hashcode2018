#include <stdio.h>
#include <stdlib.h>

#ifndef _RIDE_H_
#define _RIDE_H_
  
typedef struct Vector2
{
	unsigned long x;
	unsigned long y;
} Vector2;


typedef struct Ride
{
  Vector2 start;
  Vector2 end;

  unsigned long earlierStart;
  unsigned long lastedFinish;

  unsigned long distance;

  unsigned long lastedStart;

} Ride ;

Ride * parseRide(FILE * file );

void printRide(Ride * ride);

 
#endif /* _MATRIX_H_ */