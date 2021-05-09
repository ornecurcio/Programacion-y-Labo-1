/*
 ============================================================================
 Name        : ModeloParcialOrq.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"
#include "Nexo.h"

#define QTY_ORQUESTAS 50
#define QTY_INSTRUMENTOS 20
#define QTY_MUSICOS 1000

int main(void) {
	setbuf(stdout, NULL);

			int opcionPrincipal;
			int contador=0;
			int subMenu;
			int auxId;
			char auxChar[20];
			do{
					if(utn_getNumero(&opcionPrincipal, "\n1.ALTA, 2.BAJA, 3.MODIFICACION, 4.LISTADO, 5.ORDENADO, 6.INFORMES, 7.SALIR", "Error, Ingrese una opcion del 1 al 7.", 1, 7, 2)==0)
					{
						switch(opcionPrincipal)
						{
						case 1: //Agregar ORQUESTA

							break;
						case 2: //Modificar Not, se ingresa id, hacer submenu, modificar precio o tipo

							break;
						case 3://baja nootbook. x id

							break;
						case 4://LISTADO de notbooks

							break;
						case 5://Listar marcas

							break;
						case 6: //Listar tipos

							break;
						case 7: //listar servicios;
							break;
						case 8: //alta trabajo. se pide una notebook y un servicio
							break;
						case 9: // listar trabajos.

						}
					}
				}while(opcionPrincipal!=7);


		return EXIT_SUCCESS;
	}
