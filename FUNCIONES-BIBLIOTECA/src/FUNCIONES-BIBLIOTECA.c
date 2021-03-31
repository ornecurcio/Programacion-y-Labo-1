/*
 ============================================================================
 Name        : FUNCIONES-BIBLIOTECA.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"


int main(void) {
	setbuf(stdout, NULL);

	int numero1;
	int numero2;
	int res;

	printf("Ingrese un numero");
	scanf("%d", &numero1);

	printf("Ingrese un numero");
	scanf("%d", &numero2); // hace un pasaje de valor/parametro por referencia, no por valor, sino por donde esta en la memoria.

	res = sumar(numero1, numero2); //llamado a la funcion// parametros actuales-reales-verdaderos el ej: numero1

	if(res)
	{
		printf("\nLa suma de los numeros es ", res);
	}
	else
	{
		printf("\nNo hay nada que sumar");
	}

	return EXIT_SUCCESS;
}
