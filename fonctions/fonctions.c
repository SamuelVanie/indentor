# include <stdio.h>
# include "fonctions.h"

void put_space(FILE *fp, int spaceNumber){
    for(int i=0; i<spaceNumber; ++i)
        fputc(' ', fp);
}