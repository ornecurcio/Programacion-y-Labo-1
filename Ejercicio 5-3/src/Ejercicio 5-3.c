/*
 ============================================================================
 Name        : Ejercicio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 5-3:Realizar un programa que permita el ingreso de 10 números
 enteros distintos de cero.
 La carga deberá ser aleatoria (todos los elementos se inicializarán en cero por default.
 Determinar el promedio de los positivos, y del menor de los negativos la suma de los antecesores.
 Utilizar funciones y vectores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define NUMEROS 10

int getNumero(int numeroEnElArray[], int cantidadDeArray);

int main(void) {
	setbuf(stdout, NULL);

	int numeroIngresado[NUMEROS]=0;
	return EXIT_SUCCESS;
}
void imprimirArray(int indiceDeArray[], int cantidadDeArray)
{	int i;
	for(i=0; i<cantidadDeArray; i++)
	{
		printf("%d ", indiceDeArray[i]);
	}
}
int getNumero(int numeroEnElArray[], int cantidadDeArray)
{
	int i;
	int bufferInterno;
	for(i=0; i<cantidadDeArray; i++)
	{
		printf("Ingrese un numero distinto de cero")
		scanf()
	}


}
