/*
 * Nexo.c
 *
 *  Created on: 8 may. 2021
 *      Author: orne_
 */

int cargar1Musico(eMusico pArray[], int cantidadDeArray, int* contadorId)
{
	eMusico aAuxiliar;
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
			if((utn_getString(aAuxiliar.apellido, "Ingrese Apellido", "Error, ingrese Apellido", 2)==0)&&
			(utn_getString(aAuxiliar.nombre, "Ingrese Nombre", "Error, ingrese Nombre", 2)==0)&&
			(utn_getNumero(&aAuxiliar.idOrquesta, "Ingrese idOrquesta","Error, ingrese: entre 1 y 50", 1, 50, 2)==0)&&
			(utn_getNumero(&aAuxiliar.edad, "Ingrese edad", "Error, ingrese edad entre 18 y 70", 18, 70, 2)==0)&&
			(utn_getNumero(&aAuxiliar.idInstrumento, "Ingrese idInstrumento","Error, ingrese entre 1 y 20", 1, 50, 2)==0))
			{
				aAuxiliar.iDMusico=*contadorId;
				aAuxiliar.isEmpty=0;
				pArray[posicion]=aAuxiliar;
				(*contadorId)++;
				retorno=0;
			}
		}
	}
		return retorno;
}
int cargar1Orquesta(eOrquesta pArray[], int cantidadDeArray, int* contadorId)
{
	eOrquesta aAuxiliar;
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
			if((utn_getString(aAuxiliar.nombre, "Ingrese Nombre", "Error, ingrese Nombre", 2)==0)&&
			(utn_getString(aAuxiliar.lugar, "Ingrese Lugar", "Error, ingrese Lugar", 2)==0)&&
			(utn_getNumero(&aAuxiliar.idTipo, "Ingrese tipo 1: Sinfonica, 2.Filarmonica, 3.Camara", "Error, ingrese edad entre 18 y 70", 18, 70, 2)==0))
			{
				aAuxiliar.idOrquesta=*contadorId;
				aAuxiliar.isEmpty=0;
				pArray[posicion]=aAuxiliar;
				(*contadorId)++;
				retorno=0;
			}
		}
	}
		return retorno;
}
int cargar1Instrumento(eInstrumento pArray[], int cantidadDeArray, int* contadorId)
{
	eInstrumento aAuxiliar;
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
			if((utn_getString(aAuxiliar.nombre, "Ingrese Nombre", "Error, ingrese Nombre", 2)==0)&&
			(utn_getNumero(&aAuxiliar.idTipo, "Ingrese tipo 1: Sinfonica, 2.Filarmonica, 3.Camara", "Error, ingrese edad entre 18 y 70", 18, 70, 2)==0))
			{
				aAuxiliar.iDInstrumento=*contadorId;
				aAuxiliar.isEmpty=0;
				pArray[posicion]=aAuxiliar;
				(*contadorId)++;
				retorno=0;
			}
		}
	}
		return retorno;
}

int getDescripcionCarrera(eOrquesta aOrquesta[], int cantidadDeArray, int buscar, char* descripcion)
{
	int i;
	int retorno = -1;

	for(i=0; i<cantidadDeArray; i++)
	{
		if(aOrquesta[i].idTipo==buscar && aOrquesta[i].isEmpty==0)
		{
			strcpy(descripcion, aOrquesta[i].nombre);
			retorno=0;
		}
	}
	return retorno;
}
