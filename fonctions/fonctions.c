# include <stdio.h>
# include <stdlib.h>
# include "fonctions.h"

void put_space(FILE *fp, int spaceNumber){
    for(int i=0; i<spaceNumber; ++i)
        fputc(' ', fp);
}

FILE** includes_writer(char nomFichier[]){
    int c;
    FILE **files = malloc(2*sizeof(FILE*));
    FILE *fp = fopen(nomFichier, "r");
    FILE *noSpace = fopen("noSpace.txt", "w");
    FILE *temp = fopen("temp.txt", "w");
    while(!feof(fp)){
        char f = getc(fp);
        if(f == '#'){
            c++;
            fputc(f, noSpace);
        }else if(f == '\n' || f == '\t'){
            continue;
        }else if(f == ' '){
            char l = getc(fp);
            if(l == ' '){
                continue;
            }else{
                fputc(f, noSpace);
                fputc(l, noSpace);
            }
        }else{
            fputc(f, noSpace);
        }
    }
    fclose(noSpace);fclose(fp);
    noSpace = fopen("noSpace.txt", "r");
    while(!feof(noSpace)){
        char p = getc(noSpace);
        if(c != 0){
            if(p == '#'){
                fputc(p, temp);
            }else if(p == '>' || p == '"'){
                c--;
                fputc(p, temp);
                fputs("\n", temp);
            }else{
                fputc(p, temp);
            }
        }else{
            if(p == '>' || p == '"'){
                fputc(p, temp);
                fputs("\n", temp);
            }else{
                fputs("\n", temp);
                fputc(p, temp);
            }
            remove(nomFichier);
            files[0] = noSpace;
            files[1] = temp;
            return files;
        }
    }
    /* Va ecrire les lignes includes dans le fichier, des qu'on trouve un chevron ou des griffes
    on retourne a la ligne 
    Il va prendre le fichier ou ecrire et aussi le fichier a lire
    Apres avoir ecris dedans, il faudra rouvrir dans le programme principal mais en mode 
    d'ajout*/
}