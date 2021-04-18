/*
 ============================================================================
 Name        : Clase 6.c
 Author      : Ornela Curcio
 Version     :
 Copyright   : Your copyright notice
 Description : Realizar un programa que permita el ingreso de 10 números enteros (positivos y negativos).
 Necesito generar un listado de los números positivos de manera creciente y negativos de manera decreciente.
 (Como máximo 4 for)Ejemplo: Listado 1 : 4, 5, 6, 10, 18, 29 Listado 2 : -1,-5,-9,-12
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "numeros.h"

#define NUMEROS 10

int utn_SwapAscendiente(int listaDeArray[],int cantidadDeArray);
int utn_SwapDescendiente(int listaDeArray[],int cantidadDeArray);
void imprimirArray(int listaDeArray[], int cantidadDeArray);
void imprimirArrayDescendente(int listaDeArray[], int cantidadDeArray);
int main(void) {
	setbuf(stdout, NULL);

	int auxNum;
	int numero[NUMEROS];
	int i;

	for(i=0; i<NUMEROS; i++)
	{
		if(utn_getNumero(&auxNum,"Ingrese un numero","Error, ingrese un numero",-30, 40, 2)==0)
		{
			numero[i]=auxNum;
		}
	}
	utn_SwapAscendiente(numero, NUMEROS); //ordene de forma ascendente.

	for(i=0;i<NUMEROS;i++)
	{
		if(numero[i]<0)
		{
			imprimirArrayDescendente(numero, NUMEROS);
		}
		else
		{
			printf("%d", numero[i]);
		}
	}

	return EXIT_SUCCESS;
}
int utn_SwapAscendiente(int listaDeArray[],int cantidadDeArray)
{
	int i;
	int j;
	int aux;
	int retorno = -1;
	for(i=0; i<cantidadDeArray-1; i++)
	{
		for(j=i+1; j<cantidadDeArray; j++)
		{
			if(listaDeArray[i]>listaDeArray[j])
			{
				aux=listaDeArray[i];
				listaDeArray[i]=listaDeArray[j];
				listaDeArray[j]=aux;
			}

		}
		retorno=0;
	}
	return retorno;
}
int utn_SwapDescendiente(int listaDeArray[],int cantidadDeArray)
{
		int i;
		int j;
		int aux;
		int retorno = -1;
		for(i=0; i<cantidadDeArray-1; i++)
		{
			for(j=i+1; j<cantidadDeArray; j++)
			{
				if(listaDeArray[i]<listaDeArray[j])
				{
					aux=listaDeArray[i];
					listaDeArray[i]=listaDeArray[j];
					listaDeArray[j]=aux;
				}
			}
			retorno=0;
		}
		return retorno;
}
void imprimirArray(int listaDeArray[], int cantidadDeArray)
{	int i;
	for(i=0; i<cantidadDeArray; i++)
	{
		printf("%d ", listaDeArray[i]);
	}
}
void imprimirArrayDescendente(int listaDeArray[], int cantidadDeArray)
{	int i;
	for(i=cantidadDeArray; i>cantidadDeArray; i--)
	{
		printf("%d ", listaDeArray[i]);
	}
}
