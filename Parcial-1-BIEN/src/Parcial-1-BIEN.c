/*
 ============================================================================
 Name        : Parcial-1-BIEN.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "UTN.h"
#include "Recaudacion.h"
#include "Contribuyente.h"
#include "Informe.h"

#define QTY_CONTRIBUYENTE 50
#define QTY_RECAUDACION 50
#define QTY_TIPO 3


int main(void) {
	setbuf(stdout, NULL);

	eTipo vecTipo[QTY_TIPO]={
			{1, "ARBA", 0},
			{2, "IIBB", 0},
			{3, "GANACIAS", 0},
	};

	eContribuyente vecContribuyente[QTY_CONTRIBUYENTE];
	eRecaudacion vecRecaudacion[QTY_RECAUDACION];

	int contadorContribuyente=1000;
	int contadorRecaudacion=100;
	int auxInt;
	int posicion;
	int respuestaMenuPrincipal;



	inicializarContribuyente(vecContribuyente, QTY_CONTRIBUYENTE);
	inicializarRecaudacion(vecRecaudacion, QTY_RECAUDACION);

	do{
		if(utn_getNumero(&respuestaMenuPrincipal, "1.Alta de Contribuyente\n2.Modificar datos del contribuyente\n3.Baja de contribuyente\n"
				"4.Recaudación\n5.Refinanciar Recaudación\n6.Saldar Recaudación\n"
				"7.Imprimir Contribuyentes\n8.Imprimir Recaudación",
				"ERROR INGRESE OPCION VALIDA:"
				"1.Alta de Contribuyente\n2.Modificar datos del contribuyente\n3.Baja de contribuyente"
				"\n4.Recaudación\n5.Refinanciar Recaudación\n6.Saldar Recaudación"
				"\n7.Imprimir Contribuyentes\n8.Imprimir Recaudación\n", 1, 8, 2)==0)
		{
			switch(respuestaMenuPrincipal)
			{
				case 1: //ALTA CONTRIBUYENTE
					if(altaContribuyente(vecContribuyente, QTY_CONTRIBUYENTE, &contadorContribuyente)==0)
					{
						printf("Carga exitosa\n");
					}
				break;
				case 2:
				break;
				case 3:
				break;
				case 4:
				break;
				case 5:
				break;
				case 6:
				break;
				case 7:
				break;
				case 8:
				break;
			}//FIN SWITCH
		}//FIN IF
	}while(respuestaMenuPrincipal!=9);










	return EXIT_SUCCESS;
}
