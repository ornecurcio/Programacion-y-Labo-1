/*
 ============================================================================
 Name        : Biblioteca-UTN.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "numeros.h"

int main(void) {
	setbuf(stdout, NULL);
	int edad;
	int peso;


	utn_getNumero(&edad, "\nIngrese la edad\n", "Su edad debe ser entre 18 y 90",18,90,2);
	if(utn_getNumero(&edad, "\nIngrese la edad\n", "Su edad debe ser entre 18 y 90",18,90,2)== 0)
	{
		printf("\nLa edad es %d", &edad);
	}
	else
	{
		printf("\nError");
	}

	if(utn_getNumero(&peso, "\nIngrese peso", "Error, debe ser entre 50 y 100",50,100,3)==0)
	{
		printf("\nEl peso es%d", &peso);
	}
	else
	{
		printf("\nError");
	}
	return EXIT_SUCCESS;
}
