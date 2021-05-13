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
int buscaLibre(ePantalla pArray[], int cantidadDeArray)
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
	if(aPantalla!=NULL && cantidadDeArray>0 && contadorId!=NULL)
	{
		posicion=buscaLibre(aPantalla, cantidadDeArray);
		if(posicion==-1)
		{
			printf("\nNo hay lugares libres");
		}
		else
		{
			if((utn_getNombre(aAuxiliar.name, "Ingrese nombre de Pantalla", "Error muy largo", 2, TAM)==0)&&
			(utn_getNumero(&aAuxiliar.tipo, "Ingrese 1. LCD, 2.LED", "Ingrese 1. LCD, 2.LED", 1, 2, 2)==0)&&
			(utn_getNumeroConDecimales(&aAuxiliar.precio,"Ingrese precio","Error, ingrese precio entre 200-3000",200,3000,2)==0)&&
			(utn_getNombre(aAuxiliar.direccion.calle, "Ingrese Calle", "Error muy largo", 2, TAM)==0)&&
			(utn_getNombre(aAuxiliar.direccion.localidad, "Ingrese Localidad", "Error muy largo", 2, TAM)==0)&&
			(utn_getNumero(aAuxiliar.direccion.altura, "Ingrese altura", "Error, numero invalido", 1, 5000, 2)==0))
			{
				aAuxiliar.idPantalla=0;
				printf("Estos son los datos, desea continuar:");
				imprimir1Pantalla(aAuxiliar);
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
void imprimir1Pantalla(ePantalla aPantalla)
{
	printf("\n %-5d  %-10s %-10s %-5d %-5.2f ", aPantalla.idPantalla, aPantalla.lastName, aPantalla.name, aPantalla.sector, aPantalla.salary);
}
int imprimirPantallas(ePantalla array[], int cantidadDeArray)
{
	int i;
	int retorno = -1;

	//CABECERA
	puts("\n\t> LISTADO Empleados");
	printf("%5s %10s %10s %8s %5s\n", "ID","APELLIDO","NOMBRE","SECTOR","SUELDO");
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
				imprimir1Pantalla(array[i]);
				retorno=0;
			}
		}
	}
	return retorno;
}
int buscaPantallaById(ePantalla aAuxiliar[], int cantidadDeArray)
{
	int retorno = -1;
	int i;
	int aID;
	if(aAuxiliar!=NULL && cantidadDeArray>0)
	{
		printf("Ingrese ID");
		scanf("%d", &aID);
		for(i=0; i<cantidadDeArray; i++)
		{
			if(aAuxiliar[i].idPantalla==aID && aAuxiliar[i].isEmpty==0)
			{
				retorno = i;
				break;
			}
			else
			{
				printf("El numero de ID %d no existe", aID);
				break;
			}
		}
	}
	return retorno;
}
int bajaPantalla(ePantalla aAuxiliar[], int posicion)
{
	int retorno = -1;
	char respuesta;
	if(aAuxiliar!=NULL && posicion!=-1)
	{
		imprimir1Pantalla(aAuxiliar[posicion]);
		printf("\nDesea borrar ese empleado, ingrese 's'");
		fflush(stdin);
		scanf("%c", &respuesta);
		if(respuesta=='s')
		{
			aAuxiliar[posicion].isEmpty=1;
			retorno = 0;
		}
	}
	return retorno;
}
int ordenarPantallas(ePantalla array[], int cantidadDeArray, int criterio)
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

int modifica1Pantalla(ePantalla aAuxiliar[], int posicion)
{
	int retorno = -1;
	int respuesta;
	if(aAuxiliar!=NULL && posicion!=-1)
	{
				imprimir1Pantalla(aAuxiliar[posicion]);
				printf("\n¿Desea modificar este empleado?");
				if(utn_getCaracterSN()==0)
				{
					printf("\nDesea modificar \n1. Apellido\n2.Nombre\n3.Salario\n4.Sueldo");
					scanf("%d", &respuesta);
					while(respuesta>4 || respuesta<1)
					{
						printf("\nDesea modificar \n1. Apellido\n2.Nombre\n3.Salario\n4.Sueldo");
						scanf("%d", &respuesta);
					}
					switch(respuesta)
					{
						case 1:
							utn_getString(aAuxiliar[posicion].lastName, "Ingrese Apellido", "Error, ingrese Apellido", 1);
							printf("Exito, los nuevos datos son: ");
							imprimir1Pantalla(aAuxiliar[posicion]);
							break;
						case 2:
							utn_getString(aAuxiliar[posicion].name, "Ingrese Nombre", "Error, ingrese Nombre", 1);
							printf("Exito, los nuevos datos son: ");
							imprimir1Pantalla(aAuxiliar[posicion]);
							break;
						case 3:
							utn_getNumeroConDecimales(&aAuxiliar[posicion].salary,"Ingrese salario","Error, ingrese salario entre 300-3000",300,3000,1);
							printf("Exito, los nuevos datos son: ");
							imprimir1Pantalla(aAuxiliar[posicion]);
							break;
						case 4:
							utn_getNumero(&aAuxiliar[posicion].sector, "Ingrese sector: 1.ADMISION, 2.SEGURIDAD, 3.ADMINISTRACION",
									"Error, ingrese: 1.Admision, 2.Seguridad, 3.Administracion", 1, 3, 1);
							printf("Exito, los nuevos datos son: ");
							imprimir1Pantalla(aAuxiliar[posicion]);
							break;
					}
					retorno = 0;
				}
		}
	return retorno;
}
int ePantallaPromSalario(float* pPromedioResultado, ePantalla array[], int cantidadDeArray)
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
}
int ePantallasListaSalario(ePantalla array[], int cantidadDeArray, float salary)
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
}

