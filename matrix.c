#include "matrix.h"

void print_matrix(matrix mat)
{
  for(size_t y = 0; y < mat.row; y++)
  {
    for(size_t x = 0; x < mat.col; x++)
      printf("%d", mat.data[x + y * mat.col]);

    printf("\n");
  }
}

matrix load_matrix(FILE * file , size_t row , size_t col)
{
  matrix res;

  res.row = row;
  res.col = col;

  res.data = calloc(row * col , sizeof(int));

  for(size_t y = 0; y < row; y++)
  {
    for(size_t x = 0; x < col; x++)
      {
        char c[1];

        fscanf(file,"%c" , c);

        switch(c[0])
        {
          case 'T':
            res.data[x + y * col] = 1;
            break;

          case 'M':
            res.data[x + y * col] = 2;
            break;

          default:
            break;
        }

      }

      fscanf(file,"\n");
  }

  return res;
}

void free_matrix(matrix mat)
{
  free(mat.data);
}

int getValue(matrix mat , int x , int y)
{
  return mat.data[x + y * mat.col];
}

void setValue(int value , matrix mat , int x , int y)
{
  mat.data[x + y * mat.col ] = value;
}

matrix create_matrix(size_t row , size_t col)
{
  matrix res;
  res.col = col;
  res.row = row;

  res.data = calloc(row * col , sizeof(int));

  return res;
}