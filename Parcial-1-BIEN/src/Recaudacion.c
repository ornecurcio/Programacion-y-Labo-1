
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Recaudacion.h"
#include "UTN.h"

int inicializarRecaudacion(eRecaudacion pArray[], int cantidadDeArray)
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

int buscaLibreRecaudacion(eRecaudacion pArray[], int cantidadDeArray)
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
int getDescripcionRecaudacion(eTipo aTipo[], int cantidadTipo, int buscar, char* descripcion)
{
	int i;
	int retorno = -1;

	for(i=0; i<cantidadTipo; i++)
	{
		if(aTipo[i].tipo==buscar && aTipo[i].isEmpty==0)
		{
			strcpy(descripcion, aTipo[i].descripcion);
			retorno=0;
		}
	}
	return retorno;
}
int altaRecaudacion(eRecaudacion aArray[], int cantidadDeArray, eContribuyente aContribuyente[], int cantidadContribuyente, int* contadorId)
{
	int retorno = -1;
	eRecaudacion aAuxiliar;
	int posicion;
	int auxI;
	char descripcion[20];

	if(aArray!=NULL && cantidadDeArray>0 && aContribuyente!=NULL && cantidadContribuyente>0)
	{
		posicion=buscaLibreRecaudacion(aArray, cantidadDeArray);
		if(posicion==-1)
		{
			printf("\nNo hay lugares libres");
		}
		else
		{
			if(buscaContribuyenteById(aContribuyente, cantidadContribuyente, &auxI)!=-1)
			{
				if((utn_getNumero(&aAuxiliar.tipo, "Ingrese Tipo 1.ARBA, 2.IIBB, 3.GANANCIAS", "Error,ingrese Tipo 1.ARBA, 2.IIBB, 3.GANANCIAS",1,3,2)==0)&&
				(utn_getNumero(&aAuxiliar.mes, "Ingrese MES", "Error,ingrese MES del 1 al 12",1,12,2)==0)&&
				(utn_getNumeroFlotante(&aAuxiliar.importe, "Ingrese importe","Error, ingrese de 100 a 1000", 100, 1000, 2)==0))
				{
					aAuxiliar.idContribuyente=auxI;
					aAuxiliar.idRecaudacion=0;
					printf("Estos son los datos, desea continuar:");
					if(aAuxiliar.tipo==1)
					{
						strcpy(descripcion,"ARBA");
					}
					if(aAuxiliar.tipo==2)
					{
						strcpy(descripcion,"IIBB");
					}
					if(aAuxiliar.tipo==3)
					{
						strcpy(descripcion,"GANANCIAS");
					}
					imprimir1Recaudacion(aAuxiliar, descripcion);
					if(utn_getCaracterSN()==0)
					{
					   (*contadorId)++;
					   aAuxiliar.idRecaudacion=*contadorId;
					   aAuxiliar.estado=2;
					   aAuxiliar.isEmpty=0;
					   aArray[posicion]=aAuxiliar;
					   imprimir1Recaudacion(aAuxiliar, descripcion);
					   retorno=0;
					}
				}
			}
		}
	}
		return retorno;
}
void imprimir1Recaudacion(eRecaudacion aRecaudacion, char* descripcion)
{
	printf("\n %-5d %-5d %-10s %-5%d %-5.2f %-5d ", aRecaudacion.idRecaudacion, aRecaudacion.tipo,
			descripcion,aRecaudacion.mes, aRecaudacion.importe, aRecaudacion.idContribuyente);
}
int imprimirRecaudacion(eRecaudacion array[], int cantidadDeArray, eTipo aTipo[], int cantidadTipo)
{
	int i;
	int retorno = -1;
	char descripcion[20];
	//CABECERA
	puts("\n\t> LISTADO Recaudacion");
	printf("%5s %10s %10s %8s %12s\n", "ID","TIPO","DESCRIPCION","MES","IMPORTE","ID Contribuyente");
	if (array != NULL && cantidadDeArray> 0 && aTipo!=NULL && cantidadTipo>0)
	{
		for (i = 0; i < cantidadDeArray; i++)
		{
			if (array[i].isEmpty == 1)
			{
				continue;
			}
			else
			{
				getDescripcionRecaudacion(aTipo, cantidadTipo, array[i].tipo, descripcion);
				imprimir1Recaudacion(array[i], descripcion);
				retorno=0;
			}
		}
	}
	return retorno;
}
int buscaIDRecaudacionRetIDCon(eRecaudacion aAuxiliar[], int cantidadDeArray, int contadorRecauda, int* posicion)
{
	int retorno = -1;
	int i;
	int auxI;


	if(aAuxiliar!=NULL && cantidadDeArray>0)
	{
		printf("Ingrese ID Recaudacion");
		scanf("%d", &auxI);
		if(auxI>contadorRecauda || auxI<100)
		{
			printf("Error, no existe ID");
		}
		else
		{
			for(i=0; i<cantidadDeArray; i++)
			{
				if(aAuxiliar[i].idRecaudacion==auxI && aAuxiliar[i].isEmpty==0)
				{
					*posicion=i;
					retorno=aAuxiliar[i].idContribuyente;
					break;
				}
			}
		}
	}
	return retorno;
}
/*int buscaRecaudacionByCUIT(eRecaudacion aAuxiliar[], int cantidadDeArray, eContribuyente aContribuyente[], int cantidadContribuyente, eTipo aTipo[], int cantidadTipo)
{
	int retorno=-1;
	int auxI;
	int i;
	int j;
	char descripcion[30];
	char aCUIT[14];
	if(aAuxiliar!=NULL && cantidadDeArray>0 && aContribuyente!=NULL && cantidadContribuyente>0 && aTipo!=NULL && cantidadTipo>0)
	{
		if((auxI=buscaCUIT(aAuxiliar, cantidadDeArray,aCUIT))>0)
		{
			puts("\n\t> LISTADO Recaudacion");
			printf("%5s %10s %10s %8s %12s\n", "ID","ARCHIVO","CUIL","DIAS","ID Recaudacion");
			for(i=0; i<cantidadContribuyente; i++)
			{
				if(aAuxiliar[auxI].idContribuyente==aContribuyente[i].idContribuyente && aContribuyente[i].isEmpty==0)
				{
					getDescripcionContribuyente(aTipo, cantidadTipo, aContribuyente[i].idContribuyente, descripcion);
					imprimir1Recaudacion(aAuxiliar[auxI], descripcion);
					imprimir1Contribuyente(aContribuyente[i]);
					retorno=0;
				}
			}
		}
		if(auxI==0)
		{
			puts("\n\t> LISTADO Recaudacion");
			printf("%5s %10s %10s %8s %12s\n", "ID","ARCHIVO","CUIL","DIAS","ID Recaudacion");
			for(j=0; j<cantidadDeArray; j++)
			{
				for(i=0; i<cantidadContribuyente; i++)
				{
					if((stricmp(aAuxiliar[j].cuil, aCUIT)==0 && aAuxiliar[j].isEmpty==0)&&
					(aAuxiliar[j].idContribuyente==aContribuyente[i].idContribuyente && aContribuyente[i].isEmpty==0))
					{
						getDescripcionContribuyente(aTipo, cantidadTipo, aContribuyente[i].idContribuyente, descripcion);
						imprimir1Recaudacion(aAuxiliar[j], descripcion);
						imprimir1Contribuyente(aContribuyente[i]);
						retorno=0;
					}
				}
			}
		}
	}
	return retorno;
}*/
int buscaRecaudacionByIdContribuyente(eRecaudacion aAuxiliar[], int cantidadDeArray, int* aID)
{
	int retorno = -1;
	int i;
	int auxInt;
	if(aAuxiliar!=NULL && cantidadDeArray>0)
	{
		printf("Ingrese ID de Contribuyente");
		scanf("%d", &auxInt);
		*aID=auxInt;
		for(i=0; i<cantidadDeArray; i++)
		{
			if(aAuxiliar[i].idContribuyente==auxInt && aAuxiliar[i].isEmpty==0)
			{
				retorno = i;
				break;
			}
			else
			{
				printf("El numero de ID %d no existe", auxInt);
				break;
			}
		}
	}
	return retorno;
}
int bajaRecaudacion(eRecaudacion aAuxiliar[], int posicion, eTipo aTipo[], int cantidadTipo)
{
	int retorno = -1;
	char descripcion[20];

	if(aAuxiliar!=NULL && posicion!=-1)
	{
		getDescripcionRecaudacion(aTipo, cantidadTipo, aAuxiliar[posicion].tipo, descripcion);
		imprimir1Recaudacion(aAuxiliar[posicion], descripcion);
		printf("\n�Desea borrar esta contratacion?");
		if(utn_getCaracterSN()==0)
		{
			aAuxiliar[posicion].isEmpty=1;
			retorno = 0;
		}
	}
	return retorno;
}
int estadoRecaudacionRefinanciar(eRecaudacion aAuxiliar[], int posicion,eTipo aTipo[], int cantidadTipo)
{
	int retorno = -1;
	char descripcion[20];
	if(aAuxiliar!=NULL && posicion!=-1 && aTipo!=NULL && cantidadTipo>0)
	{
		getDescripcionRecaudacion(aTipo, cantidadTipo, aAuxiliar[posicion].tipo, descripcion);
		imprimir1Recaudacion(aAuxiliar[posicion], descripcion);
		printf("\n�Desea refinanciar esta Recaudacion?");
		if(utn_getCaracterSN()==0)
		{
			aAuxiliar[posicion].estado= REFINANCIAR;
			retorno = 0;
		}
	}
	return retorno;
}
int estadoRecaudacionSaldar(eRecaudacion aAuxiliar[], int posicion,eTipo aTipo[], int cantidadTipo)
{
	int retorno = -1;
	char descripcion[20];
	if(aAuxiliar!=NULL && posicion!=-1 && aTipo!=NULL && cantidadTipo>0)
	{
		getDescripcionRecaudacion(aTipo, cantidadTipo, aAuxiliar[posicion].tipo, descripcion);
		imprimir1Recaudacion(aAuxiliar[posicion], descripcion);
		printf("\n�Desea refinanciar esta Recaudacion?");
		if(utn_getCaracterSN()==0)
		{
			aAuxiliar[posicion].estado= SALDADO;
			retorno = 0;
		}
	}
	return retorno;
}

int bajaRecaudacionxContribuyente(eRecaudacion array[], int cantidadDeArray,int ID)
{
	int retorno = -1;
	int i;
	if(array!=NULL && cantidadDeArray>0)
		{
			for(i=0; i<cantidadDeArray; i++)
			{
				if(array[i].idContribuyente==ID)
				{
					array[i].isEmpty=1;
				}
			}
		}
	return retorno;
}
