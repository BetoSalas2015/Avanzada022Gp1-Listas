//  Sesión 17 - 23/09/2022
#include <stdio.h>				//  Para la I/O de programa
#include <stdlib.h>				//  Para las rutinas de utileria
#include <malloc.h>				//  Para la gestión de memoria dinámica

//  Macros
#define pausa system("pause")
#define cls system("cls")

struct Nodo 
{
	char info;
	struct Nodo *sig;
} *raiz = NULL;						// Creamos la lista vacía o nula

typedef struct Nodo nodo;			//  Definimos formalemtne el nuevo tipo de dato nodo

//  Primitivas de la lista ligada
void insert(char dato)
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) );
}

int main()
{
	

	system("color 7");
	pausa;
	return 0;
}


