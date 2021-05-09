/*
 * Producto.c
 *
 *  Created on: 8 may. 2021
 *      Author: orne_
 */
#include "Producto.h"
#include <stdio.h>
#include <stdlib.h>

int subMenu(void)
{
	int retorno=-1;
	int submenu;
	do{
			if(utn_getNumero(&submenu, "\n1.ALTA, 2.BAJA, 3.MODIFICACION, 4.LISTADO, 5.ORDENADO, 6.INFORMES, 7.SALIR", "Error, Ingrese una opcion del 1 al 7.", 1, 7, 2)==0)
			{
				switch(submenu)
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
					case 6:

						break;
					case 7:
				}
				retorno=0;
			}
		}while(submenu!=7);


	return retorno;
}
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInterno;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			scanf("%d", &bufferInterno);
			if(bufferInterno>=minimo && bufferInterno<=maximo && isdigit(bufferInterno)==0)
			{
				*pResultado=bufferInterno;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getNumeroConDecimales(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
	int retorno = -1;
	float bufferInterno;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			scanf("%f", &bufferInterno);
			if(bufferInterno>=minimo && bufferInterno<=maximo)
			{
				*pResultado=bufferInterno;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[40];

	if(aux != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%s", bufferString);

			if(strlen(bufferString)<20)
			{
				strcpy(aux, bufferString);
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}

int inicializarIsEmpty(eProducto pArray[], int cantidadDeArray)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && cantidadDeArray>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			pArray[i].isEmpty=1;
		}
		retorno=0;
	}
	return retorno;
}
int buscarLibre(eProducto pArray[], int cantidadDeArray)
{
	int retorno = -1;
	int i;

	if(pArray != NULL && cantidadDeArray>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			if(pArray[i].isEmpty==1)
			{
				retorno = i;
				break;
			}
		}

	}
	return retorno;
}
int cargar1Producto(eProducto pArray[], int cantidadDeArray, int* contadorId)
{
	eProducto aAuxiliar;
	int retorno = -1;
	int posicion;
	if(pArray!=NULL && cantidadDeArray>0 && contadorId!=NULL)
	{
		posicion=buscarLibre(pArray, cantidadDeArray);
		if(posicion==-1)
		{
			printf("\nNo hay lugares libres");
		}
		else
		{
			if((utn_getString(aAuxiliar.descripcion, "Ingrese Nombre de producto", "Error, ingrese Nombre de producto", 2)==0)&&
			(utn_getNumero(&aAuxiliar.tipo, "Ingrese : 1. IPHONE, 2.MAC, 3.IPAD, 4.ACCESORIOS","Error, ingrese: 1. IPHONE, 2.MAC, 3.IPAD, 4.ACCESORIOS", 1, 4, 2)==0)&&
			(utn_getNumero(&aAuxiliar.nacionalidad, "Ingrese 1. EEUU, 2. CHINA, 3.OTRO", "Error, ingrese 1. EEUU, 2. CHINA, 3.OTRO", 1, 3, 2)==0)&&
			(utn_getNumeroConDecimales(&aAuxiliar.precio, "Ingrese Precio", "Error, ingrese precio entre 100 y 1000", 100, 1000, 2)==0))
			{
				aAuxiliar.idProducto=*contadorId;
				aAuxiliar.isEmpty=0;
				pArray[posicion]=aAuxiliar;
				(*contadorId)++;
				retorno=0;
			}
		}
	}
		return retorno;
}
