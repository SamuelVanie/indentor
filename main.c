# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "./fonctions/fonctions.h"
# include "./stack-int/stack.h"

int main(int argc, char **argv){
    FILE *fic1 = fopen("fichier.txt","r");
    FILE *fic2 = fopen("temp.txt","w");
    Stack pile = new_stack();
    pile = push_stack(pile, 0);
    bool isInParenthesis = false;
    while(!feof(fic1)){
        int p = getc(fic1);
        if(p == '('){
            isInParenthesis = true;
            fputc(p, fic2);
        }else if(p == ')'){
            isInParenthesis = false;
            fputc(p, fic2);
            int s = getc(fic1);
            if(s == ' '){
                fputs("\n", fic2);
                put_space(fic2, top_stack(pile));
                pile = push_stack(pile, top_stack(pile)+4);
            }else if(s == '{'){
                fputc('{', fic2);
                fputs("\n", fic2);
                pile = push_stack(pile, top_stack(pile)+4);
                put_space(fic2, top_stack(pile));
            }
        }else{
            if(!isInParenthesis){
                if(p == '{'){
                    fputc(p, fic2);
                    fputs("\n", fic2);
                    pile = push_stack(pile, top_stack(pile)+4);
                    put_space(fic2, top_stack(pile));
                }else if(p == ';'){
                    fputc(p, fic2);
                    fputs("\n", fic2);
                    put_space(fic2, top_stack(pile));
                }else if(p == '}'){
                    fputs("\n", fic2);
                    pile = pop_stack(pile);
                    put_space(fic2, top_stack(pile));
                    fputc(p, fic2);
                }else{
                    fputc(p, fic2);
                }
            }else{
                fputc(p, fic2);
            }
        }
    }
    fclose(fic2);
    fclose(fic1);
}