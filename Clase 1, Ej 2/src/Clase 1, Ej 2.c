/*
 ============================================================================
 Name        : Ornela Curcio
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Pedir el sueldo al usuario. Sumarle un 10% e informarle cu�l
 ser� su sueldo con aumento
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int valorSueldo;
	int resultado;
	printf("Ingrese su sueldo");
	scanf("%d", &valorSueldo);
	resultado=valorSueldo+valorSueldo*10/100;
	printf("Su sueldo con aumento es: %d",resultado);

	return 0;
}