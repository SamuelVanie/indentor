CC = gcc
EXEC = indentor

all : $(EXEC)

$(EXEC) : main.o ./stack-int/stack.o ./fonctions/fonctions.o
	$(CC) -o $(EXEC) main.o ./stack-int/stack.o ./fonctions/fonctions.o

fonctions : ./fonctions/fonctions.c
	$(CC) -o fonctions.o -c ./fonctions/fonctions.c -I ./fonctions

stack : ./stack-int/stack.c
	$(CC) -o stack.o -c ./stack-int/stack.c -I ./stack-int