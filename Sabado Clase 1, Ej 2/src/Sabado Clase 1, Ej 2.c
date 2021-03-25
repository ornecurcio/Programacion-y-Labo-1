/*
 ============================================================================
 Name        : Sabado.Clase 1, Ej 2
 Author      : Ornela Curcio
 Version     :
 Copyright   :
 Description : Ejercicio 2:
Ingresar 5 números. Determinar cuál es el máximo y el mínimo e indicar en
qué orden fue ingresado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int numeroIngresado;
	int i;
	int numeroMinimo;
	int ordenIngresadoMinimo;
	int numeroMaximo;
	int ordenIngresadoMaximo;

	for(i=0; i<5; i++)
	{
		printf("Ingrese un numero entero");
		//fflush(stdin);
		scanf("%d", &numeroIngresado);

		if(i==0 || numeroIngresado>numeroMaximo)
		{
			numeroMaximo = numeroIngresado;
			ordenIngresadoMaximo = i+1;
		}

		if(i==0 || numeroIngresado<numeroMinimo)
		{
			numeroMinimo = numeroIngresado;
			ordenIngresadoMinimo = i+1;
		}

	}//fin for
	printf("El numero maximo es %d y el minimo numero es %d", numeroMaximo, numeroMinimo);
	printf("\nEl orden de ingreso del numero maximo es %d y el orden de ingreso del numero minimo es %d", ordenIngresadoMaximo, ordenIngresadoMinimo);

	return EXIT_SUCCESS;
}
