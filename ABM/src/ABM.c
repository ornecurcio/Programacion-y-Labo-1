/*
 ============================================================================
 Name        : ABM.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	setbuf(stdout, NULL);
	int opcionPrincipal;
	int contador="poner numero";
	int subMenu;
	int auxId;
	char auxChar[20];
	do{
			if(utn_getNumero(&opcionPrincipal, "\n1.ALTA, 2.BAJA, 3.MODIFICACION, 4.LISTADO, 5.ORDENADO, 6.INFORMES, 7.SALIR", "Error, Ingrese una opcion del 1 al 7.", 1, 7, 2)==0)
			{
				switch(opcionPrincipal)
				{
				case 1: //ALTA

					break;
				case 2: //BAJA

					break;
				case 3://MODIFICACION

					break;
				case 4://LISTADO

					break;
				case 5://ORDENADO

					break;
				case 6: //INFORMES
					utn_getNumero(&subMenu, "1. , 2. , 3. 4.", "Error, entre 1 y 4", 1, 4, 2);
					switch(subMenu)
					{
					case 1:
						break;
					case 2:
						break;
					case 3:
						break;
					case 4:
						break;
					}
					break;
				}
			}
		}while(opcionPrincipal!=7);

	return EXIT_SUCCESS;
}
