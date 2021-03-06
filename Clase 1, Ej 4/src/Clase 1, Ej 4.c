/*
 ============================================================================
 Name        : Ornela Curcio
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Pedirle al usuario su edad y su estado civil ('c'-casado, 's'-soltero, 'v'-viudo, 'd'-divorciado)
Si ingresa una edad menor a 18 a?os y un estado civil distinto a "Soltero",
mostrar el siguiente mensaje: 'Es muy peque?o para NO ser soltero.'
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int edadIngresada;
	char estadoCivilIngresado;

	printf("Ingrese la edad");
	scanf("%d", &edadIngresada);

	printf("Ingrese su estado civil: c-casado, s-soltero, v-viudo");
	fflush(stdin);
	scanf("%c", &estadoCivilIngresado);

	if(edadIngresada<18 && estadoCivilIngresado!= 's')
	{
		printf("Usted es muy peque?o para no ser Soltero");
	}
	else
	{
		printf("Su edad es %d y su estado civil es %c", edadIngresada, estadoCivilIngresado);
	}
	return EXIT_SUCCESS;
}
