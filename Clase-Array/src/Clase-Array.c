/*
 ============================================================================
 Name        : Clase-Array.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Pedirle al usuario 5 edades y luego imprimir las 5 edades. Definir un array de 5 porciones
 y usar la funcion getNumero()para pedir valores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "calculos.h"
#include "numeros.h"

#define EDADESLARGO 5
int main(void) {
	setbuf(stdout, NULL);

	int edad;
	int edades[EDADESLARGO];
	int i;

	for(i=0; i<EDADESLARGO; i++)
	{
		if(utn_getNumero(&edad,"Ingrese edad","Error, ingrese edad entre 18 y 90 ",18,90,3)==0)
		{
			edades[i]=edad;
		}
	}

	for(i=0; i<EDADESLARGO; i++)
	{
		printf("%d ", edades[i]);
	}
	return EXIT_SUCCESS;
}
