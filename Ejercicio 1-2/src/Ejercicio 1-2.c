/*
 ============================================================================
 Name        : Ejercicio 1-2.c
 Author      : Ornela Curcio
 Version     :
 Copyright   :
 Description : ingresar 3 números y mostrar el mayor de los tres.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {


	setbuf(stdout, NULL);

	 	int i
		int numeroIngresado;
		int numeroMayor;

		for(i=0; i<3; i++)
		{
			printf("Ingrese un numero");
			fflush(stdin);
			scanf("%d", &numeroIngresado);

			if(i==0) // if(numeroIngresado==0 || numeroIngresado>numeroMayor)
			{
				numeroMayor=numeroIngresado;
			}
			else //esta parte se borra si escribo arriba con un 'o'
			{
				if(numeroIngresado>numeroMayor)
				{
					numeroMayor=numeroIngresado;
				}
			}
		}

		printf("El mayor numero de los 3 es %d", numeroMayor);




		return EXIT_SUCCESS;

}
