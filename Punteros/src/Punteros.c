/*
 ============================================================================
 Name        : Punteros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define TAM 5
void funcion1(int aArray[], int cantidadDeArray);
void funcion2(int aArray[], int cantidadDeArray);
void funcion2(int aArray[], int cantidadDeArray);
void funcion3(int* aArray, int cantidadDeArray);
void funcion4(int* aArray, int cantidadDeArray);
int main(void) {
	setbuf(stdout, NULL);

	int vec[TAM];

	//funcion1(vec, TAM);
	//funcion2(vec, TAM);
	//funcion3(vec, TAM);
	funcion4(vec, TAM);
	return EXIT_SUCCESS;
}

void funcion1(int aArray[], int cantidadDeArray)
{
	for(int i=0; i<TAM; i++)
	{
		aArray[i]=i+1;
	    printf("\n%d", aArray[i]);
	}
}
void funcion2(int aArray[], int cantidadDeArray)
{
	for(int i=0; i<TAM; i++)
	{
		*(aArray+i)=i+1;
	    printf("%d", *(aArray+i));
	}
}
void funcion3(int* aArray, int cantidadDeArray)
{
	for(int i=0; i<TAM; i++)
	{
		aArray[i]=i+1;
		printf("%d", aArray[i]);
	}
}
void funcion4(int* aArray, int cantidadDeArray)
{
	for(int i=0; i<TAM; i++)
	{
		*(aArray+i)=i+1;
		printf("%d",*(aArray+i));
	}
}

