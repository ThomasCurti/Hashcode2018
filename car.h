#include <stdio.h>
#include <stdlib.h>

#include "ride.h"

#ifndef _CAR_H_
#define _CAR_H_

typedef struct Car {

  unsigned long x;
  unsigned long y;

  int free;

  unsigned long end;

  int rides [100] ; 

  int it;

} Car;

unsigned long  calculateDistanceToRide(Car * car, Ride * ride);

unsigned long  assignRide(Ride * ride , Car ** cars , unsigned long Fleet , unsigned long step , unsigned long id);


#endif