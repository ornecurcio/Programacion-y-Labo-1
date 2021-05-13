/*
 ============================================================================
 Name        : Ejercicio 1-1.c
 Author      : Ornela Curcio
 Version     :
 Copyright   : Your copyright notice
 Description :Ingresar dos números enteros, sumarlos y mostrar el resultado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	char aCUIT[]="27-34707599-5";
	int aAuxiliar=20;
	float resultado=1050.20;
/*
	int numeroUno;
	int numeroDos;
	int resultado;

	printf("Ingrese un numero");
	fflush(stdin);
	scanf("%d", &numeroUno);

	printf("Ingrese otro numero");
	fflush(stdin);
	scanf("%d", &numeroDos);

	resultado = numeroUno+numeroDos;

	printf("El resultado es %d", resultado);

*/
			printf("CLIENTE--------CONTRATACION------PRECIO");

	         printf("\n%-15s    %-8d      %-.2f",aCUIT, aAuxiliar, resultado);

	return EXIT_SUCCESS;
}
