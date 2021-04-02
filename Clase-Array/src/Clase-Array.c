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

void imprimirArray(int listaDeEdades[]);

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
	imprimirArray(edades);

	return EXIT_SUCCESS;
}
void imprimirArray(int listaDeEdades[])
{	int i;
	for(i=0; i<EDADESLARGO; i++)
	{
		printf("%d ", listaDeEdades[i]);
	}
}
// El nombre del array es la direccion de memoria donde comienza el array

/* void imprimirArray(int array[]) //es por referencia.
 * {
 * 	int j;
 * 	array[2]=3; // aca lee
 * 	j = array[3]+7; // aca escribe
 * }
 */
/*void imprimirArray(int* e)
 * {
 * 		e=9;    //pasaje por referencia; leo o escribo el valor
 * 	}
 *
 * void imprimirArray(int e)
 * {
 *     e=9; pasaje por valor; no puedo escribir el valor, solo leer
 *
 *     e+7 = j;
 * }
 */
