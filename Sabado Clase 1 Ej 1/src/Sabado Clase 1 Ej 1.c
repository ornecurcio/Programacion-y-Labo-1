/*
 ============================================================================
 Name        : Sabado. Clase 1. Ej 1.
 Author      : Ornela Curcio
 Version     :
 Copyright   :
 Description : Ingresar n?meros enteros, hasta que el usuario lo decida. Calcular y mostrar:
a) El promedio de los n?meros positivos.
b) El promedio de los n?meros negativos.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int numeroIngresado;
	int contadorNumerosPositivos = 0;
	int acumuladorNumerosPositivos = 0;
	float promedioPositivos;
	int contadorNumerosNegativos = 0;
	int acumuladorNumerosNegativos = 0;
	float promedioNegativos;

	char respuesta;

	respuesta = 's';

	while(respuesta=='s')
	{
		printf("Ingrese un numero entero");
		fflush(stdin);
		scanf("%d", &numeroIngresado);

		if(numeroIngresado>0)
		{
			contadorNumerosPositivos = contadorNumerosPositivos + 1;
			acumuladorNumerosPositivos = acumuladorNumerosPositivos + numeroIngresado;
		}
		else
		{
			contadorNumerosNegativos = contadorNumerosNegativos + 1;
			acumuladorNumerosNegativos = acumuladorNumerosNegativos + numeroIngresado;

		}
		printf("Desea ingresar otro numero? ingrese 's'");
		fflush(stdin);
		scanf("%c", &respuesta);
	} //fin while

	promedioPositivos = (float)acumuladorNumerosPositivos/contadorNumerosPositivos;
	promedioNegativos = (float)acumuladorNumerosNegativos/contadorNumerosNegativos;

	printf("\nEl promedio de los numeros positivos es %.2f", promedioPositivos);
	printf("\nEl promedio de los numeros negativos es %.2f", promedioNegativos);

	return EXIT_SUCCESS;
}
