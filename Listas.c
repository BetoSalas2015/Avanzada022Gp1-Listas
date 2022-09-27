//  Sesi�n 18 - 27/09/2022
#include <stdio.h>				//  Para la I/O de programa
#include <stdlib.h>				//  Para las rutinas de utileria
#include <malloc.h>				//  Para la gesti�n de memoria din�mica

//  Macros
#define pausa system("pause")
#define cls system("cls")

struct Nodo 
{
	char info;
	struct Nodo *sig;
} *raiz = NULL;						// Creamos la lista vac�a o nula

typedef struct Nodo nodo;			//  Definimos formalemtne el nuevo tipo de dato nodo

//  Primitivas de la lista ligada
void insert(char dato)
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) );
	if( nuevo == NULL )				//  No hay memoria disponible
	{
		printf("Nohay memoria disponible! \n");
		pausa;
		exit(1);		//	C�digo de error personalizado 1. No hay memoria
	}
	nuevo -> info = dato;		//  Preservamos la informaci�n en la lista
	if( raiz == NULL )			//  Lista vac�a, no hay nodos
	{
		raiz = nuevo;			//  Insertamos el nodo en la lista
		raiz ->sig = NULL;		//  Se vuelve el �ltimo nodo de la lista
	}
	else				//  La lista no esta vac�a, hay al menos 1 nodo
	{
		nodo *recorre = raiz;
		while(recorre ->sig != NULL)		// Estoy posicionado en el ultimo nodo?
		{
			recorre = recorre-> sig; 
		}
		recorre->sig = nuevo;		// Insertamos el nodo en la lista ligada
		nuevo ->sig = NULL;
	}
}

void imprimeLista()
{
	nodo *recorre = raiz;
	while(recorre != NULL)		// Estoy posicionado en el ultimo nodo?
	{
		printf("%c, ", recorre->info );
		recorre = recorre-> sig; 
	}
	putchar('\n');
}

int main()
{	
	system("color 7");
	imprimeLista();
	insert('R');
	insert('o');
	insert('b');
	insert('e');
	insert('r');
	insert('t');
	insert('o');

	imprimeLista();

	
	pausa;
	return 0;
}


