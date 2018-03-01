#include <stdio.h>
#include <stdlib.h>

void ReadFile (char *title) {
  FILE *file = fopen(title, "r");

  if(file == NULL) {
    printf("T'as dû te fail dans le nom\n");
    return;
  }

  /*ICI LE CODE AVEC file COMME FICHIER OPEN EN READ*/
  int s = getc(file);
  while (s != EOF) {
    s = getc(file);
  }
  

}
