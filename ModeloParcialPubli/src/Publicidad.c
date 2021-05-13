/*
 * Publicidad.c
 *
 *  Created on: 12 may. 2021
 *      Author: orne_
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Publicidad.h"
#include "UTN.h"

int inicializarPublidad(ePublicidad pArray[], int cantidadDeArray)
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
int buscaLibrePublicidad(ePublicidad pArray[], int cantidadDeArray)
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
int altaPublicidad(ePublicidad aArray[], int cantidadDeArray, ePantalla aPantalla[], int cantidadPantalla, int* contadorId)
{
	int retorno = -1;
	ePublicidad aAuxiliar;
	int posicion;
	int auxI;
	if(aArray!=NULL && cantidadDeArray>0 && aPantalla!=NULL && cantidadPantalla>0)
	{
		posicion=buscaLibrePublicidad(aArray, cantidadDeArray);
		if(posicion==-1)
		{
			printf("\nNo hay lugares libres");
		}
		else
		{
			if(buscaPantallaById(aPantalla, cantidadPantalla, &auxI)==0)
			{
				if((utn_getCUIT(aAuxiliar.cuil, "Ingrese CUIT", "Error,ingrese CUIT", 2)==0)&&
				(utn_getString(aAuxiliar.archivo, "Ingrese Nombre", "Error, ingrese Nombre", 2)==0)&&
				(utn_getNumero(&aAuxiliar.dias, "Ingrese dias de contratacion","Error, ingrese de 1 a 365", 1, 365, 2)==0))
				{
					aAuxiliar.idPantalla=auxI;
					aAuxiliar.idPublicidad=0;
					printf("Estos son los datos, desea continuar:");
					imprimir1Publicidad(aAuxiliar);
					if(utn_getCaracterSN()==0)
					{
					   (*contadorId)++;
					   aAuxiliar.idPublicidad=*contadorId;
					   aAuxiliar.isEmpty=0;
					   aArray[posicion]=aAuxiliar;
					   retorno=0;
					}
				}
			}
		}
	}
		return retorno;
}
void imprimir1Publicidad(ePublicidad aPublicidad)
{
	printf("\n %-5d  %-10s %-10s %-5d %-5d ", aPublicidad.idPublicidad, aPublicidad.archivo, aPublicidad.cuil, aPublicidad.dias, aPublicidad.idPublicidad);
}
int imprimirPublicidad(ePublicidad array[], int cantidadDeArray)
{
	int i;
	int retorno = -1;

	//CABECERA
	puts("\n\t> LISTADO PUBLICIDAD");
	printf("%5s %10s %10s %8s %12s\n", "ID","ARCHIVO","CUIL","DIAS","ID PUBLICIDAD");
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
				imprimir1Publicidad(array[i]);
				retorno=0;
			}
		}
	}
	return retorno;
}
int buscaPublidadById(ePublicidad aAuxiliar[], int cantidadDeArray)
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
			if(aAuxiliar[i].idPublicidad==aID && aAuxiliar[i].isEmpty==0)
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
int bajaPublicidad(ePublicidad aAuxiliar[], int posicion)
{
	int retorno = -1;
	char respuesta;
	if(aAuxiliar!=NULL && posicion!=-1)
	{
		imprimir1Publicidad(aAuxiliar[posicion]);
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
/*int ordenarPublicidad(ePublicidad array[], int cantidadDeArray, int criterio)
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
int modifica1Publicidad(ePublicidad aAuxiliar[], int posicion)
{
	int retorno = -1;
	int respuesta;
	if(aAuxiliar!=NULL && posicion!=-1)
	{
				imprimir1Publicidad(aAuxiliar[posicion]);
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
							imprimir1Employee(aAuxiliar[posicion]);
							break;
						case 2:
							utn_getString(aAuxiliar[posicion].name, "Ingrese Nombre", "Error, ingrese Nombre", 1);
							printf("Exito, los nuevos datos son: ");
							imprimir1Employee(aAuxiliar[posicion]);
							break;
						case 3:
							utn_getNumeroFlotante(&aAuxiliar[posicion].salary,"Ingrese salario","Error, ingrese salario entre 300-3000",300,3000,1);
							printf("Exito, los nuevos datos son: ");
							imprimir1Employee(aAuxiliar[posicion]);
							break;
						case 4:
							utn_getNumero(&aAuxiliar[posicion].sector, "Ingrese sector: 1.ADMISION, 2.SEGURIDAD, 3.ADMINISTRACION",
									"Error, ingrese: 1.Admision, 2.Seguridad, 3.Administracion", 1, 3, 1);
							printf("Exito, los nuevos datos son: ");
							imprimir1Employee(aAuxiliar[posicion]);
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
					imprimir1Employee(array[i]);
				}
			}
		}
	}
	return retorno;
}
int bajaPublicidadxPantalla(ePublicidad array[], int cantidadDeArray,int ID)
{
	int retorno = -1;
	int i;
	if(array!=NULL && cantidadDeArray>0)
		{
			for(i=0; i<cantidadDeArray; i++)
			{
				if(array[i].idPantalla==ID)
				{
					array[i].isEmpty=1;
				}
			}
		}
	return retorno;
}
