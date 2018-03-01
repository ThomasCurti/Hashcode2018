#include <stdio.h>
#include <stdlib.h>

#ifndef _MATRIX_H_
#define _MATRIX_H_
  
typedef struct matrix
{
  int * data;

  size_t row;
  size_t col;

} matrix ;


void print_matrix(matrix mat);

matrix load_matrix(FILE * file , size_t row , size_t col);

void free_matrix(matrix mat);

int getValue(matrix mat , int x , int y);
void setValue(int value , matrix mat , int x , int y);

matrix create_matrix(size_t row , size_t col);
 
#endif /* _MATRIX_H_ */