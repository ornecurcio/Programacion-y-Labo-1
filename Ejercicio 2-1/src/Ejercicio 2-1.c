/*
 ============================================================================
 Name        : Ejercicio.c
 Author      : Ornela Curcio
 Version     :
 Copyright   : Your copyright notice
 Description : Ingresar 5 números enteros calcular y mostrar el promedio de los números. Probar la
aplicación con distintos valores.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

		 	int contadorNumero;
			int numeroIngresado;
			int acumuladorNumero = 0;
			float resultado;

			for(contadorNumero=0; contadorNumero<5; contadorNumero++)
			{
				printf("Ingrese un numero");
				fflush(stdin);
				scanf("%d", &numeroIngresado);

				acumuladorNumero = acumuladorNumero + numeroIngresado;
			}

			resultado = (float)acumuladorNumero/contadorNumero;

			printf("El promedio es %.2f", resultado);

	return EXIT_SUCCESS;
}
