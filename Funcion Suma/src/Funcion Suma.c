/*
 ============================================================================
 Name        : Funcion.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sumar(int num1, int num2); // en el prototipo son parametros formales y en la funcion ej: num1

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

	printf("\nLa suma de los numeros es ", res);

	return EXIT_SUCCESS;
}
int sumar(int num1, int num2)
{
	int resultado;

	resultado = num1+num2;

	return resultado;
}

