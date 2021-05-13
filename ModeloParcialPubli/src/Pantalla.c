/*
 * Pantalla.c
 *
 *  Created on: 12 may. 2021
 *      Author: orne_
 */
#include "Pantalla.h"
#include "UTN.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50
int inicializarPantalla(ePantalla pArray[], int cantidadDeArray)
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
int buscaLibrePantalla(ePantalla pArray[], int cantidadDeArray)
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
int altaPantalla(ePantalla aPantalla[], int cantidadDeArray, int* contadorId)
{
	int retorno = -1;
	ePantalla aAuxiliar;
	int posicion;
	char descripcion[30];
	if(aPantalla!=NULL && cantidadDeArray>0 && contadorId!=NULL)
	{
		posicion=buscaLibrePantalla(aPantalla, cantidadDeArray);
		if(posicion==-1)
		{
			printf("\nNo hay lugares libres");
		}
		else
		{
			if((utn_getNombre(aAuxiliar.name, "Ingrese nombre de Pantalla", "Error muy largo", 2, TAM)==0)&&
			(utn_getNumero(&aAuxiliar.tipo, "Ingrese 1. LCD, 2.LED", "Ingrese 1. LCD, 2.LED", 1, 2, 2)==0)&&
			(utn_getNumeroFlotante(&aAuxiliar.precio,"Ingrese precio","Error, ingrese precio entre 200-3000",200,3000,2)==0)&&
			(utn_getNombre(aAuxiliar.direccion.calle, "Ingrese Calle", "Error muy largo", 2, TAM)==0)&&
			(utn_getNombre(aAuxiliar.direccion.localidad, "Ingrese Localidad", "Error muy largo", 2, TAM)==0)&&
			(utn_getNumero(&aAuxiliar.direccion.altura, "Ingrese altura", "Error, numero invalido", 1, 9999, 2)==0))
			{
				aAuxiliar.idPantalla=0;
				if(aAuxiliar.tipo==1)
				{
					strcpy(descripcion,"LCD");
				}
				if(aAuxiliar.tipo==2)
				{
					strcpy(descripcion,"LED");
				}
				printf("Estos son los datos, desea continuar:");
				imprimir1Pantalla(aAuxiliar, descripcion);
				if(utn_getCaracterSN()==0)
				{
				   (*contadorId)++;
				   aAuxiliar.idPantalla=*contadorId;
				   aAuxiliar.isEmpty=0;
				   aPantalla[posicion]=aAuxiliar;
				   retorno=0;
				}
			}
		}
	}
		return retorno;
}
void imprimir1Pantalla(ePantalla aPantalla, char* descripcion)
{
	printf("\n %-5d %-5d %-5s %-15s %-15s %-15s %-5d %-5.2f ", aPantalla.idPantalla, aPantalla.tipo, descripcion, aPantalla.name,aPantalla.direccion.localidad,
			aPantalla.direccion.calle, aPantalla.direccion.altura, aPantalla.precio);
}
int imprimirPantallas(ePantalla array[], int cantidadDeArray, eTipo aTipos[], int cantidadTipos)
{
	int i;
	int retorno = -1;
	char descripcion[30];

	//CABECERA
	puts("\n\t> LISTADO PANTALLAS");
	printf("%5s %10s %10s %10s %10s %5s %5s\n", "ID","TIPO","NOMBRE","LOCALIDAD","CALLE","ALTURA","PRECIO");
	if (array != NULL && cantidadDeArray> 0)
	{
		for (i = 0; i < cantidadDeArray; i++)
		{
			if (array[i].isEmpty == 1)
			{
				continue;
			}
			else
			{
				getDescripcionPantalla(aTipos, cantidadTipos, array[i].tipo,descripcion);
				imprimir1Pantalla(array[i], descripcion);
				retorno=0;
			}
		}
	}
	return retorno;
}
int buscaPantallaById(ePantalla aAuxiliar[], int cantidadDeArray, int* aID)
{
	int retorno = -1;
	int i;
	int auxI;
	if(aAuxiliar!=NULL && cantidadDeArray>0)
	{
		printf("\nIngrese ID Pantalla");
		scanf("%d", &auxI);
		*aID=auxI;
		for(i=0; i<cantidadDeArray; i++)
		{
			if(aAuxiliar[i].idPantalla==auxI && aAuxiliar[i].isEmpty==0)
			{
				retorno = i;
				break;
			}
			else
			{
				printf("El numero de ID %d no existe", auxI);
				break;
			}
		}
	}
	return retorno;
}
int bajaPantalla(ePantalla aAuxiliar[], int posicion, eTipo aTipos[], int cantidadTipos)
{
	int retorno = -1;
	char descripcion[20];
	if(aAuxiliar!=NULL && posicion!=-1)
	{
		getDescripcionPantalla(aTipos, cantidadTipos, aAuxiliar[posicion].tipo, descripcion);
		imprimir1Pantalla(aAuxiliar[posicion], descripcion);
		printf("\nDesea borrar esta pantalla");
		if(utn_getCaracterSN()==0)
		{
			aAuxiliar[posicion].isEmpty=1;

			retorno = 0;
		}
	}
	return retorno;
}
int modifica1Pantalla(ePantalla aAuxiliar[], int posicion, eTipo aTipos[], int cantidadTipos)
{
	int retorno = -1;
	int respuesta;
	char descripcion[20];

	if(aAuxiliar!=NULL && posicion!=-1 && aTipos!=NULL && cantidadTipos>0)
	{
		getDescripcionPantalla(aTipos, cantidadTipos, aAuxiliar[posicion].tipo, descripcion);
		imprimir1Pantalla(aAuxiliar[posicion], descripcion);
		printf("\n¿Desea modificar esta pantalla?");
		if(utn_getCaracterSN()==0)
		{
			printf("\nDesea modificar \n1.Nombre\n2.Tipo\n3.Direccion\n4.Precio");
			scanf("%d", &respuesta);
			while(respuesta>4 || respuesta<1)
			{
				printf("\nDesea modificar \n1.Nombre\n2.Tipo\n3.Direccion\n4.Precio");
				scanf("%d", &respuesta);
			}
			switch(respuesta)
			{
				case 1:
					utn_getNombre(aAuxiliar[posicion].name, "Ingrese nombre de Pantalla", "Error muy largo", 2, TAM);
					printf("Exito, los nuevos datos son: ");
					getDescripcionPantalla(aTipos, cantidadTipos, aAuxiliar[posicion].tipo, descripcion);
					imprimir1Pantalla(aAuxiliar[posicion], descripcion);
					break;
				case 2:
					utn_getNumero(&aAuxiliar[posicion].tipo, "Ingrese 1. LCD, 2.LED", "Ingrese 1. LCD, 2.LED", 1, 2, 2);
					printf("Exito, los nuevos datos son: ");
					getDescripcionPantalla(aTipos, cantidadTipos, aAuxiliar[posicion].tipo, descripcion);
					imprimir1Pantalla(aAuxiliar[posicion], descripcion);
					break;
				case 3:
					utn_getNombre(aAuxiliar[posicion].direccion.calle, "Ingrese Calle", "Error muy largo", 2, TAM);
					utn_getNumero(&aAuxiliar[posicion].direccion.altura, "Ingrese altura", "Error, numero invalido", 1, 9999, 2);
					utn_getNombre(aAuxiliar[posicion].direccion.localidad, "Ingrese Localidad", "Error muy largo", 2, TAM);
					printf("Exito, los nuevos datos son: ");
					getDescripcionPantalla(aTipos, cantidadTipos, aAuxiliar[posicion].tipo, descripcion);
					imprimir1Pantalla(aAuxiliar[posicion], descripcion);
					break;
				case 4:
					utn_getNumeroFlotante(&aAuxiliar[posicion].precio,"Ingrese precio","Error, ingrese precio entre 200-3000",200,3000,2);
					printf("Exito, los nuevos datos son: ");
					getDescripcionPantalla(aTipos, cantidadTipos, aAuxiliar[posicion].tipo, descripcion);
					imprimir1Pantalla(aAuxiliar[posicion], descripcion);
					break;
			}
			retorno = 0;
		}
	}
	return retorno;
}
int getDescripcionPantalla(eTipo aTipo[], int cantidadDeArray, int buscar, char* descripcion)
{
	int i;
	int retorno = -1;

	for(i=0; i<cantidadDeArray; i++)
	{
		if(aTipo[i].tipo==buscar && aTipo[i].isEmpty==0)
		{
			strcpy(descripcion, aTipo[i].descripcion);
			retorno=0;
		}
	}
	return retorno;
}
/*int ordenarPantallas(ePantalla array[], int cantidadDeArray, int criterio)
{
		int flagDesordenado = -1;
		int i;
		ePantalla aux;
		int retorno=-1;

		if(array!=NULL && cantidadDeArray>0)
		{
			do {
				flagDesordenado=0;
				for (i = 0; i < cantidadDeArray-1; ++i)
				{
					if(criterio == 0)
					{
							if(strcmp(array[i].lastName,array[i+1].lastName)>0)
							{
								flagDesordenado=1;
								aux=array[i];
								array[i]=array[i+1];
								array[i+1]=aux;
							}
							else
							{
									if(strcmp(array[i].lastName,array[i+1].lastName)==0 && array[i].sector > array[i+1].sector)
									{
										flagDesordenado=1;
										aux=array[i];
										array[i]=array[i+1];
										array[i+1]=aux;
									}
							}
						}
						else
						{
							if(criterio == 1)
							{
								if(strcmp(array[i+1].lastName,array[i].lastName)>0)
								{
									flagDesordenado=1;
									aux=array[i];
									array[i]=array[i+1];
									array[i+1]=aux;
								}
								else
								{
									if(strcmp(array[i].lastName,array[i+1].lastName)==0 && array[i+1].sector > array[i].sector)
									{
										flagDesordenado=1;
										aux=array[i];
										array[i]=array[i+1];
										array[i+1]=aux;
									}
								}
							}
						}
					}
				} while (flagDesordenado==0);
				retorno=0;
		}
		return retorno;
}
*/
/*int ePantallaPromSalario(float* pPromedioResultado, ePantalla array[], int cantidadDeArray)
{
	int retorno = -1;
	int i;
	int acumulador=0;
	int contador=0;

	if(pPromedioResultado != NULL && array!=NULL && cantidadDeArray>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			if(array[i].isEmpty==0)
			{
			acumulador =+ array[i].salary;
			contador++;
			}
		}
		*pPromedioResultado = acumulador/contador;
		printf("El salario promedio es: %.2f", *pPromedioResultado);
		retorno = 0;
	}
	return retorno;
}*/
/*int ePantallasListaSalario(ePantalla array[], int cantidadDeArray, float salary)
{
	int retorno=-1;
	int i;

	if(array!=NULL && cantidadDeArray>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			if(array[i].isEmpty==0)
			{
				if(array[i].salary>=salary)
				{
					imprimir1Pantalla(array[i]);
				}
			}
		}
	}

	return retorno;
}*/
