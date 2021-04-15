/*
 ============================================================================
 Name        : hola.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // contiene strcpy

int main(void) {
	setbuf(stdout, NULL);

	char texto[]="Nona mama";

	printf("\n El texto es %s", texto);
	return EXIT_SUCCESS;
}
