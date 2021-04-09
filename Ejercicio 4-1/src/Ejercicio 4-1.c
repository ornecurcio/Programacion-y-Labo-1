/*
 ============================================================================
 Name        : Ejercicio 4-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Realizar un programa EN EL MAIN que permita calcular y mostrar el factorial de un número.
				Por ejemplo:
				5! = 5*4*3*2*1 = 120
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int numero;
	int resultado=1;
	int i;

	printf("Ingrese un numero");
	fflush(stdin);
	scanf("%d", &numero);


	if(numero==0)
		{
			resultado = 1;
		}
		else
		{
			if(numero>0)
			{
				for(i=numero; i>0; i--)
				{
					resultado=resultado*i;
				}
			}
			else
			{
				for(i=numero; i<0; i++)
				{
					resultado=resultado*i;
				}
			}
		}

	printf("El facturial del numero ingresado %d es %d ", numero, resultado);
	return EXIT_SUCCESS;
}

