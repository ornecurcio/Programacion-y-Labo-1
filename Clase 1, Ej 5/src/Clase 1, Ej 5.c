/*
 ============================================================================
 Name        : Ornela Curcio
 Author      : 
 Version     :
 Copyright   :
 Description : d-Operadores Logicos
Aplicando el concepto de Operadores Lógicos con valores booleanos en el condicional:
Solicitar un número al usuario
Informar si el mismo es par o impar.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int numeroIngresado;
	setbuf(stdout, NULL);

	printf("Ingrese un numero");
	fflush(stdin);
	scanf("%d", &numeroIngresado);

	if(numeroIngresado%2==0)
	{
		printf("El numero es par");
	}
	else
	{
		printf("El numero es impar");
	}
	return EXIT_SUCCESS;
}
