# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
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
        char p = fgetc(fic1);
        if(p == '('){
            isInParenthesis = true;
            fputc(p, fic2);
        }else if(p == ')'){
            isInParenthesis = false;
            fputc(p, fic2);
            int s = fgetc(fic1);
            if(s == ' '){
                fputs("\n", fic2);
                if(stack_length(pile) != 1)
                    put_space(fic2, top_stack(pile));
                else
                    break;
            }else if(s == '{'){
                fputc('{', fic2);
                fputs("\n", fic2);
                pile = push_stack(pile, top_stack(pile)+NOMBRE_ESPACE);
                if(stack_length(pile) != 1)
                    put_space(fic2, top_stack(pile));
                else
                    break;
            }else if(s == ';'){
                fputc(s, fic2);
                fputs("\n", fic2);
                if(stack_length(pile) != 1)
                    put_space(fic2, top_stack(pile));
                else
                    break;
            }else{
                fputc(p, fic2);
            }
        }else{
            if(!isInParenthesis){
                if(p == '{' || p == ':'){
                    fputc(p, fic2);
                    fputs("\n", fic2);
                    pile = push_stack(pile, top_stack(pile)+NOMBRE_ESPACE);
                    if(stack_length(pile) != 1)
                        put_space(fic2, top_stack(pile));
                    else
                        break;
                }else if(p == ';'){
                    fputc(p, fic2);
                    fputs("\n", fic2);
                    char k0 = fgetc(fic1);
                    char sCase[4];
                    char defaultCase[7];
                    sCase[0] = k0;
                    defaultCase[0] = k0;
                    if(k0 == '}'){
                        if(stack_length(pile) != 1){
                            pile = pop_stack(pile);
                            put_space(fic2, top_stack(pile));
                            fputc(k0, fic2);
                            fputs("\n", fic2);
                            put_space(fic2, top_stack(pile));
                        }
                        else
                            break;
                        
                    }else if(k0 == 'c'){
                        sCase[1] = fgetc(fic1);
                        if(sCase[1] == 'a'){
                            sCase[2] = fgetc(fic1);
                            if(sCase[2] == 's')
                                sCase[3] = fgetc(fic1);
                            else;
                        }
                        if(strcmp(sCase, "case") != 0){
                            if(stack_length(pile) != 1){
                                pile = pop_stack(pile);
                                put_space(fic2, top_stack(pile));
                                fputs("case", fic2);
                            }else{
                                break;
                            }
                        }else{
                            if(stack_length(pile) != 1)
                                put_space(fic2, top_stack(pile));
                            else
                                break;
                            for(int i=0; i<=3; i++){
                                if(sCase[i])
                                    putc(sCase[i], fic2);
                            }
                        }
                    }else if(k0 == 'd'){
                        defaultCase[1] = fgetc(fic1);
                        if(defaultCase[1] == 'e'){
                            defaultCase[2] = fgetc(fic1);
                            if(defaultCase[2] == 'f'){
                                defaultCase[3] = fgetc(fic1);
                                if(defaultCase[3] == 'a'){
                                    defaultCase[4] = fgetc(fic1);
                                    if(defaultCase[4] == 'u'){
                                        defaultCase[5] = fgetc(fic1);
                                        if(defaultCase[5] == 'l'){
                                            defaultCase[6] = fgetc(fic1);
                                        }
                                    }
                                }
                            }
                        }
                        if(strcmp(defaultCase, "default") != 0){
                            if(stack_length(pile) != 1){
                                pile = pop_stack(pile);
                                put_space(fic2, top_stack(pile));
                                fputs("default", fic2);
                            }else{
                                break;
                            }
                        }else{
                            if(stack_length(pile) != 1)
                                put_space(fic2, top_stack(pile));
                            else
                                break;
                            for(int i=0; i<=6; i++){
                                if(defaultCase[i])
                                    putc(defaultCase[i], fic2);
                            }
                        }
                    }else{
                        if(stack_length(pile) != 1){
                            put_space(fic2, top_stack(pile));
                            fputc(k0, fic2);
                        }
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