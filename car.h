#include <stdio.h>
#include <stdlib.h>

#ifndef _CAR_H_
#define _CAR_H_

typedef struct Car {

  unsigned long x;
  unsigned long y;

} Car;

unsigned long  calculateDistanceToRide(Car * car, Ride * ride);

#endif