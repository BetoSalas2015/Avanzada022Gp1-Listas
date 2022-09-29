//  Sesión 19 - 29/09/2022
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
	if( nuevo == NULL )				//  No hay memoria disponible
	{
		printf("Nohay memoria disponible! \n");
		pausa;
		exit(1);		//	Código de error personalizado 1. No hay memoria
	}
	nuevo -> info = dato;		//  Preservamos la información en la lista
	if( raiz == NULL )			//  Lista vacía, no hay nodos
	{
		raiz = nuevo;			//  Insertamos el nodo en la lista
		raiz ->sig = NULL;		//  Se vuelve el último nodo de la lista
	}
	else				//  La lista no esta vacía, hay al menos 1 nodo
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

void insert1(char dato)
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) );
	if( nuevo == NULL )				//  No hay memoria disponible
	{
		printf("Nohay memoria disponible! \n");
		pausa;
		exit(1);		//	Código de error personalizado 1. No hay memoria
	}
	nuevo -> info = dato;		//  Preservamos la información en la lista
	nuevo->sig = raiz;
	raiz = nuevo;			//  Insertamos el nodo en la lista
}

void insertn(char dato, int n)
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc( sizeof(nodo) );
	if( nuevo == NULL )				//  No hay memoria disponible
	{
		printf("No hay memoria disponible! \n");
		pausa;
		exit(1);		//	Código de error personalizado 1. No hay memoria
	}
	nuevo -> info = dato;		//  Preservamos la información en la lista
	if( raiz == NULL )			//  Lista vacía, no hay nodos
	{
		raiz = nuevo;			//  Insertamos el nodo en la lista
		raiz ->sig = NULL;		//  Se vuelve el último nodo de la lista
		return;					//  Ya inserté el nodo. se acabo!
	}
	if( n == 1)
	{
		nuevo -> info = dato;		//  Preservamos la información en la lista
		nuevo->sig = raiz;
		raiz = nuevo;			//  Insertamos el nodo en la lista
	}
	else				//  La lista no esta vacía, hay al menos 1 nodo
	{
		nodo *recorre = raiz;
		int cont = 1;
		while(recorre ->sig != NULL && cont == n-2 )		// Estoy posicionado en el ultimo nodo?
		{
			recorre = recorre-> sig; 
			cont++;
		}
		nuevo->sig = recorre->sig;
		recorre->sig = nuevo;		// Insertamos el nodo en la lista ligada
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
	insert1('R');
	insert1('o');
	insert1('b');
	insert1('e');
	insert1('r');
	insert1('t');
	insert1('o');
	insertn('z', 3);

	imprimeLista();

	
	pausa;
	return 0;
}


