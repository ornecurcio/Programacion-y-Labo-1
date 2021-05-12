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
#include "UTN.h"

int main(void) {
	setbuf(stdout, NULL);
	float numf;
	int numInt;
	char nombre[50];

	utn_getNumeroFlotante(&numf, "decimal", "error", -7.5, 12.5, 2);
	//getFloat(&numf);
	utn_getNumero(&numInt, "numero", "error", -100, 100,2);
	utn_getNombre(nombre, "nombre", "error", 2, 50);
	utn_getTelefono(nombre, "Ingrese Telefono", "error", 8, 12, 15000000, 1599999999, 2);

	printf("%f", numf);
	return EXIT_SUCCESS;
}
