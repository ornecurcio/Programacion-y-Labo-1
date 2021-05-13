/*
 ============================================================================
 Name        : ModeloParcialPubli.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"
#include "Pantalla.h"
#include "Publicidad.h"

#define QTY_PANTALLA 3
#define QTY_CLIENTE 2
int main(void) {
	setbuf(stdout, NULL);

		eTipo
		ePantalla vecPantallas[QTY_PANTALLA];
		ePublicidad vecClientes[QTY_CLIENTE];
		int contadorPantallas=0;
		int submenu;
		int auxInt;
		int respuestaMenuPrincipal;
		float auxFloat;

		inicializarPantalla(vecPantallas, QTY_PANTALLA);
		inicializarPublidad(vecClientes, QTY_CLIENTE);
	do{
			if(utn_getNumero(&respuestaMenuPrincipal, "\n1.Alta de pantalla \n2.Modificar Pantalla\n3.Baja de pantalla"
					"\n4.Contratar unaa publicidad\n5.Modificar contrataciones\n6.Cancelar contratacion"
					"\n7.Consulta facturacion\n8.Listar contrataciones\n9.Listar Pantallas\n10.Informes",
					"ERROR INGRESE OPCION VALIDA: \n1.Alta de pantalla \n2.Modificar Pantalla\n3.Baja de pantalla"
					"\n4.Contratar unaa publicidad\n5.Modificar contrataciones\n6.Cancelar contratacion"
					"\n7.Consulta facturacion\n8.Listar contrataciones\n9.Listar Pantallas\n10.Informes", 1, 10, 2)==0)
			{
				switch(respuestaMenuPrincipal)
				{
					case 1: //ALTA PANTALLA
						if(altaPantalla(vecPantallas, QTY_PANTALLA, &contadorPantallas)==0)
						{
							printf("Carga exitosa\n");
						}
						break;
					case 2://MODIFICAR PANTALLA
						if(contadorPantallas==0)
						{
							printf("Error, primero debe ingresar una pantalla");
						}
						else
						{
							modifica1Pantalla(vecPantallas, buscaPantallaById(vecPantallas, QTY_PANTALLA));
						}
						break;
					case 3://BAJA PANTALLA
						if(contadorPantallas==0)
						{
							printf("Error, primero debe ingresar una pantalla");
						}
						else
						{
							bajaPantalla(vecPantallas, buscaPantallaById(vecPantallas, QTY_PANTALLA));
						}
						break;
					case 4: // ALTA PUBLICIDAD
						if(contadorPantallas==0)
						{
							printf("Error, primero debe ingresar una pantalla");
						}
						else
						{
							imprimirPantallas(vecPantallas, QTY_PANTALLA);
						}
						break;
					case 5://MODIFICA PUBLICIDAD
						if(contadorPantallas==0)
						{
							printf("Error, primero debe ingresar una pantalla");
						}
						else
						{

						}
						break;
					case 6: // CANCELA PUBLICDAD
						if(contadorPantallas==0)
						{
							printf("Error, primero debe ingresar una pantalla");
						}
						else
						{

						}
						break;
					case 7: // FACTURACION
						if(contadorPantallas==0)
						{
							printf("Error, primero debe ingresar una pantalla");
						}
						else
						{

						}
						break;
					case 8: // IMPRIME PUBLICIDAD
						if(contadorPantallas==0)
						{
							printf("Error, primero debe ingresar una pantalla");
						}
						else
						{

						}
						break;
					case 9: //IMPRIME PANTALLAS
						if(contadorPantallas==0)
						{
							printf("Error, primero debe ingresar una pantalla");
						}
						else
						{

						}
						break;
					case 10: //INFORMES
						if(contadorPantallas==0)
						{
							printf("Error, primero debe ingresar una pantalla");
						}
						else
						{

						}
						break;
				}
			}
		}while(respuestaMenuPrincipal!=5);

		return EXIT_SUCCESS;
	}
