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


#define QTY_CONTRIBUYENTE 3
#define QTY_RECAUDACION 3
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
				"\n7.Imprimir Contribuyentes\n8.Imprimir Recaudación\n9.Salir\n", 1, 9, 2)==0)
		{
			switch(respuestaMenuPrincipal)
			{
				case 1: //ALTA CONTRIBUYENTE
					if(altaContribuyente(vecContribuyente, QTY_CONTRIBUYENTE, &contadorContribuyente)==0)
					{
						printf("Carga exitosa\n");
					}
				break;
				case 2: //MODIFICAR CONTRIBUYENTE
					if(!(hayContribuyente(vecContribuyente, QTY_CONTRIBUYENTE)))
					{
						modifica1Contribuyente(vecContribuyente, buscaContribuyenteById(vecContribuyente, QTY_CONTRIBUYENTE, &auxInt));
					}
				break;
				case 3: //BAJA CONTRIBUYENTE
					if(!(hayContribuyente(vecContribuyente, QTY_CONTRIBUYENTE)))
					{
						posicion=buscaContribuyenteById(vecContribuyente, QTY_CONTRIBUYENTE, &auxInt);
						imprimir1Contribuyente(vecContribuyente[posicion]);
						recaudacionxContribuyente(vecRecaudacion, QTY_RECAUDACION, vecTipo, QTY_TIPO, auxInt);
						bajaContribuyente(vecContribuyente, posicion);
						bajaRecaudacionxContribuyente(vecRecaudacion, QTY_RECAUDACION, auxInt);
					}
				break;
				case 4: // RECAUDACION
					if(!(hayContribuyente(vecContribuyente, QTY_CONTRIBUYENTE)))
					{
						if((imprimirContribuyentes(vecContribuyente, QTY_CONTRIBUYENTE)==0)&&
						(altaRecaudacion(vecRecaudacion, QTY_RECAUDACION, vecContribuyente, QTY_CONTRIBUYENTE, &contadorRecaudacion)==0))
						{
							printf("Carga de recaudacion exitosa\n");
						}
					}
				break;
				case 5: // REFINANCIAR RECAUDACION
					if(!(hayContribuyente(vecContribuyente, QTY_CONTRIBUYENTE)))
					{
						auxInt=buscaIDRecaudacionRetIDCon(vecRecaudacion, QTY_RECAUDACION, contadorRecaudacion, &posicion);
						imprimir1Contribuyente(vecContribuyente[buscaContribuyenteXIdParametro(vecContribuyente, QTY_CONTRIBUYENTE, auxInt)]);
						estadoRecaudacionRefinanciar(vecRecaudacion, posicion, vecTipo, QTY_TIPO);
					}
				break;
				case 6: // SALDAR RECAUDACION
					if(!(hayContribuyente(vecContribuyente, QTY_CONTRIBUYENTE)))
					{
						auxInt=buscaIDRecaudacionRetIDCon(vecRecaudacion, QTY_RECAUDACION, contadorRecaudacion, &posicion);
						imprimir1Contribuyente(vecContribuyente[buscaContribuyenteXIdParametro(vecContribuyente, QTY_CONTRIBUYENTE, auxInt)]);
						estadoRecaudacionSaldar(vecRecaudacion, posicion, vecTipo, QTY_TIPO);
					}
				break;
				case 7: // IMPRIMIR CONTRIBUYENTES
					if(!(hayContribuyente(vecContribuyente, QTY_CONTRIBUYENTE)))
					{
						listarContribuyentes(vecRecaudacion, QTY_RECAUDACION, vecContribuyente, QTY_CONTRIBUYENTE, vecTipo, QTY_TIPO);
					}
					break;
				case 8: // IMPRIMIR RECAUDACION
					if(!(hayContribuyente(vecContribuyente, QTY_CONTRIBUYENTE)))
					{
						if(imprimirRecaudacionSaldadas(vecRecaudacion, QTY_RECAUDACION, vecTipo, QTY_TIPO, vecContribuyente, QTY_CONTRIBUYENTE)!=0)
						{
							printf("NO HAY RECAUDACIONES SALDADAS");
						}
					}
				break;
			}//FIN SWITCH
		}//FIN IF
	}while(respuestaMenuPrincipal!=9);










	return EXIT_SUCCESS;
}
