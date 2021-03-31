/*
 ============================================================================
 Name        : Ejercicios-FuncionesBibliotecas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : A- Hacer el menú de un programa con las siguientes opciones:
 1. Loguearse, 2. Comprar, 3. Ver mis compras, 4. Vender, 5. Salir
 	 	 	   B- Al menú anterior chequear que no pueda ingresar a ninguna opción si no se logueó
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

	int opcion;

	printf("Ingrese una opcion: 1-Loguearse, 2-Comprar, 3-Ver mis compras, 4-Vender, 5-Salir");
	scanf("%d", &opcion);

	switch(opcion)
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	}
	return EXIT_SUCCESS;
}
