# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "stack-int/stack.h"

int main(int argc, char **argv){
    if(argc == 1){
        FILE *fic1 = fopen(argv[1],"r");
        FILE *fic2 = fopen("temp.txt","w");
        Stack pile = new_stack();
        pile = push_stack(pile, 0);
        bool isInParenthesis = false;
        while(!feof(fic1)){
            char p = fgetc(fic1);
            if(p == "("){
                isInParenthesis = true;
                fputc(p, fic2);
            }else if(p == ")"){
                isInParenthesis = false;
                fputc(p, fic2);
                if(fgetc(fic2) == " "){
                    fputc("\n", fic2);
                    fputs(" "*top_stack(pile), fic2);
                    pile = push_stack(pile, top_stack(pile)+4);
                }
            }else{
                if(!isInParenthesis){
                    if(p == ";" || p == "{"){
                        fputc(p, fic2);
                        fputc("\n", fic2);
                        fputs("    ", fic2);
                        pile = push_stack(pile, top_stack(pile)+4);
                    }else if(p == "}"){

                    }else{
                        fputc(p, fic2);
                    }
                    continue;
                }else{
                    fputc(p, fic2);
                }
            }
        }
    }
}