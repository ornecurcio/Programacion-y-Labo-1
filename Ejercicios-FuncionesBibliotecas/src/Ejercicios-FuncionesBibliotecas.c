/*
 ============================================================================
 Name        : Ejercicios-FuncionesBibliotecas.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : A- Hacer el menú de un programa con las siguientes opciones:
 1. Loguearse, 2. Comprar, 3. Ver mis compras, 4. Vender, 5. Salir
 	 	 	   B- Al menú anterior chequear que no pueda ingresar a ninguna opción si no se logueó
 	 	 	   C- Al menú anterior chequear que no pueda ver sus compras, si no ingresó primero a comprar al menos una vez
		       D- Cuando se ingresa a la opción vender del menú, debe abrirse otro menú que contenga: 1. Vender 2. Hacer factura 3. Volver atrás
               E- A lo anterior sumarle que haya compras para poder vender. (Si compré una vez y vendí una vez no puedo ingresar a vender).
               F- Pasar las acciones de menú a funciones y llevarlas a una biblioteca

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int menu(int op);
int menuVenta(int opp);

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int opcionDos;
	int contadorCompra = 0;
	int flagUsuario = 0;

	menu(opcion);

	while(opcion!=5)
	{
	switch(opcion)
		{
		case 1:
			flagUsuario=1;
			break;
		case 2:
			if(flagUsuario==0)
			{
				printf("Error, primero debe loguearse");
			}
			contadorCompra++;
			break;
		case 3:
			if(flagUsuario==0)
			{
				printf("Error, primero debe loguearse");
			}
			else
			{
				if(contadorCompra==0)
				{
					printf("Error, primero debe comprar algo");
				}
			break;
		case 4:
			if(flagUsuario==0)
			{
				printf("Error, primero debe loguearse");
			}
			else
			{
				if(contadorCompra==0)
				{
					printf("Error, primero debe comprar algo");
				}
				else
				{
					while(opcionDos!=3)
								{
									printf("Ingrese nueva opcion:1. Vender 2. Hacer factura 3. Volver atrás");
									scanf("%d", opcionDos);
									switch(opcionDos)
									{
									case 1:
										if(contadorCompra!=0)
										{
											contadorCompra--;
										}
										break;
									case 2:
										break;
									case 3:
										break;
									}
								}//cierra el segundo while
				}
			}
			break;
		case 5:
			break;
		default
		printf("Error, ingrese opcion valida");
		}
	//printf("Ingrese una opcion: 1-Loguearse, 2-Comprar, 3-Ver mis compras, 4-Vender, 5-Salir");
	//scanf("%d", &opcion);

	}
		return EXIT_SUCCESS;
}

int menu(int op)
{
	printf("Ingrese una opcion: 1-Loguearse, 2-Comprar, 3-Ver mis compras, 4-Vender, 5-Salir");
	scanf("%d", &op);
	return op;
}
