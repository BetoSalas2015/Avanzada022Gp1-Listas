//  Sesi�n 20 - 30/09/2022
#include <stdio.h>				//  Para la I/O de programa
#include <stdlib.h>				//  Para las rutinas de utileria
#include <malloc.h>				//  Para la gesti�	n de memoria din�mica

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

void insert1(char dato)
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
		exit(1);		//	C�digo de error personalizado 1. No hay memoria
	}
	nuevo -> info = dato;		//  Preservamos la informaci�n en la lista
	if( raiz == NULL )			//  Lista vac�a, no hay nodos
	{
		raiz = nuevo;			//  Insertamos el nodo en la lista
		raiz ->sig = NULL;		//  Se vuelve el �ltimo nodo de la lista
		return;					//  Ya insert� el nodo. se acabo!
	}
	if( n == 1)
	{
		nuevo -> info = dato;		//  Preservamos la informaci�n en la lista
		nuevo->sig = raiz;
		raiz = nuevo;			//  Insertamos el nodo en la lista
	}
	else				//  La lista no esta vac�a, hay al menos 1 nodo
	{
		nodo *recorre = raiz;
		int cont = 1;
		while(recorre ->sig != NULL && cont < n - 1 )		// Estoy posicionado en el ultimo nodo?
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

char remueve()
{
	nodo *recorre = raiz;
	char dato;
	if( recorre == NULL)				//  La lista est� vacia
	{
		printf("La lista est� vac�a, no hay nada que remover.\n");
		pausa;
		return '\0';
	}
	if(	recorre->sig == NULL )			// Estoy posicionado en el �ltimo
	{
		dato = recorre->info;			//  Preservo el dato
		raiz = NULL;					//  Vacio la lista
		free(recorre);					//  Libero memoria reservada por malloc()
		return dato;					//  Regresamos el dato extra�do de la lista
	}
	else
	{
		nodo *ultimo = recorre->sig;	//  Posicionamos ultimo en el "ultimo?"
		while( ultimo->sig != NULL)		// No estoy posicionado en el ultimo?
		{
			recorre = recorre->sig;		//  Recorre avanza al siguiente
			ultimo = ultimo->sig;		//  Ultimo avanza al siguiente
		}
		recorre->sig = NULL;			//  Recorre se vuelve el �ltmo nodo
		dato = ultimo->info;			//  Preservo la informaci�n
		free(ultimo);					//  Libero memoria reservada por malloc()
		return dato;					//  Regresamos el dato extra�do de la lista
	}
}

char remueve1()
{
	nodo *recorre = raiz;
	char dato;
	if( recorre == NULL)				//  La lista est� vacia
	{
		printf("La lista est� vac�a, no hay nada que remover.\n");
		pausa;
		return '\0';
	}
	dato = recorre->info;			//  Preservo el dato
	raiz = raiz->sig;				//  apunto a lo que sigue (null u otro nodo)
	free(recorre);					//  Libero memoria reservada por malloc()
	return dato;					//  Regresamos el dato extra�do de la lista
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
	insertn('z', 40);

	imprimeLista();

	printf("Salio de la lista: %c \n", remueve() );

	imprimeLista();

	printf("Salio de la lista: %c \n", remueve1() );

	imprimeLista();

	
	pausa;
	return 0;
}


