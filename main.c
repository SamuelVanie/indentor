# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "./fonctions/fonctions.h"
# include "./stack-int/stack.h"
# define NOMBRE_ESPACE 4

int main(int argc, char **argv){
    FILE **files = includes_writer(argv[1]);
    FILE *fic2 = files[1];
    FILE *fic1 = files[0];
    Stack pile = new_stack();
    pile = push_stack(pile, 0);
    bool isInParenthesis = false;
    while(!feof(fic1)){
        char p = getc(fic1);
        if(p == '('){
            isInParenthesis = true;
            fputc(p, fic2);
        }else if(p == ')'){
            isInParenthesis = false;
            fputc(p, fic2);
            char s = getc(fic1);
            if(s == ' '){
                fputs("\n", fic2);
                put_space(fic2, top_stack(pile));
            }else if(s == '{'){
                fputc('{', fic2);
                fputs("\n", fic2);
                pile = push_stack(pile, top_stack(pile)+NOMBRE_ESPACE);
                put_space(fic2, top_stack(pile));
            }else if(s == ';'){
                fputc(s, fic2);
                fputs("\n", fic2);
                put_space(fic2, top_stack(pile));
            }else{
                fputc(p, fic2);
            }
        }else{
            if(!isInParenthesis){
                if(p == '{'){
                    fputc(p, fic2);
                    fputs("\n", fic2);
                    pile = push_stack(pile, top_stack(pile)+NOMBRE_ESPACE);
                    put_space(fic2, top_stack(pile));
                }else if(p == ';'){
                    fputc(p, fic2);
                    fputs("\n", fic2);
                    char k = getc(fic1);
                    if(k == '}'){
                        pile = pop_stack(pile);
                        put_space(fic2, top_stack(pile));
                        fputc(k, fic2);
                        fputs("\n", fic2);
                        put_space(fic2, top_stack(pile));
                    }else{
                        put_space(fic2, top_stack(pile));
                        fputc(k, fic2);
                    }
                }else if(p == '}'){
                    fputs("\n", fic2);
                    pile = pop_stack(pile);
                    put_space(fic2, top_stack(pile));
                    fputc(p, fic2);
                    fputs("\n", fic2);
                }else{
                    fputc(p, fic2);
                }
            }else{
                fputc(p, fic2);
            }
        }
    }
    fclose(fic2); fclose(fic1);
    if(argc == 2){
        rename("temp.txt", argv[1]);
        remove("noSpace.txt");
    }else{
        FILE *result;
        result = fopen(argv[2], "a");
        char g;
        fic2 = fopen("temp.txt", "r");
        fputc('\n', result);
        while(!feof(fic2)){
            g = getc(fic2);
            fputc(g, result);
        }
        fclose(result);fclose(fic2);
        remove("temp.txt");
        remove("noSpace.txt");
    }
    return 0;
}