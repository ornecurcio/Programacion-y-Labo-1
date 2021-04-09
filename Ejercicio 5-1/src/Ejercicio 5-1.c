/*
 ============================================================================
 Name        : Ejercicio.c
 Author      : Ornela Ivana Curcio
 Version     :
 Copyright   : Your copyright notice
 Description : Ejercicio 5-1:Pedir el ingreso de 5 números.
 Mostrarlos y calcular la sumatoria de los mismos.
 ============================================================================
 */

/*#include <stdio.h>
#include <stdlib.h>

#define NUMEROS 5


int main(void) {
	setbuf(stdout, NULL);

	int numero[NUMEROS];
	int i;
	int suma=0;

	for(i=0; i<NUMEROS; i++)
	{
		printf("Ingrese un numero");
		scanf("%d", &numero[i]);
		suma = suma+numero[i];
	}
	printf("Los numeros son %d, %d, %d, %d, %d y la suma es %d", numero[0],numero[1], numero[2], numero[3], numero[4], suma);

	return EXIT_SUCCESS;
}*/
//Ornela Ivana Curcio
// Ingresar 10 empleados, (numero de legajo), edad y sueldo y sueldo promedio.
#include <stdio.h>
#include <stdlib.h>

#define NUMEROS 10

int main(void) {
	setbuf(stdout, NULL);

	int edad[NUMEROS];
	int i;
	int legajo;
	float sueldo[NUMEROS];
	float sumaSueldo=0;
	float promedio;

	for(i=0; i<NUMEROS; i++)
	{
		printf("Ingrese una edad");
		scanf("%d", &edad[i]);
		printf("Ingrese un sueldo");
		scanf("%f", &sueldo[i]);
		sumaSueldo = sumaSueldo+sueldo[i];
	}

	for(i=0; i<NUMEROS; i++)
	{
		legajo=i;
		printf("El sueldo de el legajo %d, es %.2f y tiene %d años\n", legajo, sueldo[i], edad[i]);
	}
	promedio=sumaSueldo/NUMEROS;

	printf("El sueldo promedio es %.2f", promedio);

	return EXIT_SUCCESS;
}

