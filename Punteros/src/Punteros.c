/*
 ============================================================================
 Name        : Punteros.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 puntero: es una variable que tiene asignada un espacio de memoria.
 */

#include <stdio.h>
#include <stdlib.h>
int dividir(int operadorUno, int operadorDos,float* pResultado); //le cambiamos a pResultado

int main(void) {
	setbuf(stdout, NULL);

	int a;
	int b;
	float resultado;
	int huboError;

	a=20;
	b=10;

	huboError = dividir(a, b, &resultado); //&paso la direccion de memoria, sabiendo la direccion de memoria
								// puedo escribir adentro, si tengo la direccion.
								// los valores se van pisando.
	if(huboError==0)
	{
	printf("El resultado de la division es %f", resultado);
	}
	else
	{
		printf("No es posible dividir por cero");
	}
	return EXIT_SUCCESS;
}

int dividir(int operadorUno, int operadorDos,float* pResultado)
{
	float result;
	int hayError;
	if(operadorDos!=0)
	{
		result=(float)operadorUno/operadorDos;
		*pResultado = result;
		hayError=0;
	}
	else
	{
		hayError=1;
	}
	return hayError;
}
