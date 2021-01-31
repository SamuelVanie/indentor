#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

/**
* Retourne une Pile vide
* @return Une Pile vide
*/
Stack new_stack(void)
{
	return NULL;
}

/*-----------------------------------------------------------------*/

/**
* Vérifie si une Pile est vide
* @param st La pile à tester
* @return true si la Pile est vide, faux sinon
*/
Bool is_empty_stack(Stack st)
{
	if(st == NULL)
		return true;

	return false;
}

/*-----------------------------------------------------------------*/

/**
* Empile un entier dans la Pile
* @param st La Pile
* @param x L'entier à ajouter
* @return La nouvelle Pile
*/
Stack push_stack(Stack st, int x)
{
	StackElement *element;

	element = malloc(sizeof(*element));

	if(element == NULL)
	{
		fprintf(stderr, "Probleme allocation dynamique.\n");
		exit(EXIT_FAILURE);
	}

	element->value = x;
	element->next = st;

	return element;
}

/*-----------------------------------------------------------------*/

/**
* Dépile un entier de la Pile
* @param st La Pile
* @param La pile sans le premier élément
*/
Stack pop_stack(Stack st)
{
	StackElement *element;

	if(is_empty_stack(st))
		return new_stack();

	element = st->next;
	free(st);

	return element;
}

/*-----------------------------------------------------------------*/

/**
* Affiche une Pile
* @param st La Pile
*/
void print_stack(Stack st)
{
	if(is_empty_stack(st))
	{
		printf("Rien a afficher, la Pile est vide.\n");
		return;
	}

	while(!is_empty_stack(st))
	{
		printf("[%d]\n", st->value);
		st = st->next;
	}
}

/*-----------------------------------------------------------------*/

/**
* Retourne l'entier au sommet de la Pile
* @param st La Pile
* @return Le nombre entier au sommet de la Pile
*/
int top_stack(Stack st)
{
	if(is_empty_stack(st))
	{
		printf("Aucun sommet, la Pile est vide.\n");
		exit(EXIT_FAILURE);
	}

	return st->value;
}

/*-----------------------------------------------------------------*/

/**
* Retourne la hauteur (longueur) de la Pile
* @param st La Pile
* @return La taille de la Pile
*/
int stack_length(Stack st)
{
	int length = 0;

	while(!is_empty_stack(st))
	{
		length++;
		st = st->next;
	}

	return length;
}

/*-----------------------------------------------------------------*/

/**
* Vide la Pile de ses éléments
* @param st La Pile à nettoyer
* @return Une Pile vide
*/
Stack clear_stack(Stack st)
{
	while(!is_empty_stack(st))
		st = pop_stack(st);

	return new_stack();
}