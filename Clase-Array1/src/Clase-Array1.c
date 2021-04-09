/*
 ============================================================================
 Name        : Clase-Array1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hacer una funcion que calcule el promedio de los valores del array que recibe y
 me devuelva el promedio.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "numeros.h"
#include "calculos.h"

#define EDADESLARGO 5

void imprimirArray(int listaDeEdades[], int largo);
int promediarArray(float* pPromedioResultado, int array[], int cantidadArray);

int main(void) {
	setbuf(stdout, NULL);

	int edad;
	int edades[EDADESLARGO];
	int i;
	float promedio;

	for(i=0; i<EDADESLARGO; i++)
	{
		if(utn_getNumero(&edad,"Ingrese edad","Error, ingrese edad entre 18 y 90 ",18,90,3)==0)
		{
			edades[i]=edad;
		}
	}
	imprimirArray(edades, EDADESLARGO);
	promediarArray(&promedio, edades, EDADESLARGO);

	printf("El promedio es %.2f", promedio);


	return EXIT_SUCCESS;
}
void imprimirArray(int listaDeEdades[], int largo)
{	int i;
	for(i=0; i<largo; i++)
	{
		printf("%d ", listaDeEdades[i]);
	}
}
int promediarArray(float* pPromedioResultado, int array[], int cantidadArray)
{
	int i;
	int acumulador=0;
	for(i=0; i<cantidadArray; i++)
	{
		acumulador = acumulador + array[i];
	}
	*pPromedioResultado = (float)acumulador/cantidadArray;

	return 0;
}
