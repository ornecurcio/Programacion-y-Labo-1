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
		if(aOrquesta[i].tipo==buscar && aOrquesta[i].isEmpty==0)
		{
			strcpy(descripcion, aOrquesta[i].nombre);
			retorno=0;
		}
	}
	return retorno;
}


//#include "Entidades.h"

int eMusicoOrquesta_Alta(
		eMusico arrayMusico[], int TAM_MUSICO,
		eOrquesta arrayOrquesta[], int TAM_ORQUESTA,
		eInstrumento arrayInstrumento[], int TAM_INSTRUMENTO)
{

	int retorno = 0;
	eMusico auxMusico;
	int idOrquesta;

	int posicion = eMusico_ObtenerposicionLibre(arrayMusico, TAM_MUSICO);

	if (posicion != -1) {
		auxMusico = eMusico_CargarDatos();

		//ID DE ORQUESTA
		eOrquesta_MostrarTodos(arrayOrquesta, TAM_ORQUESTA);
		idOrquesta = Get_Int("SELECCIONE ID DE ORQUESTA DE MUSICO: ",
				"ERROR. REINGRESE: ");

		while (eOrquesta_BuscarPorID(arrayOrquesta, TAM_ORQUESTA, idOrquesta) == -1) {
			puts("ID NO EXISTE.");
			idOrquesta = Get_Int("SELECCIONE ID DE ORQUESTA DE MUSICO: ",
					"ERROR. REINGRESE: ");
		}
		auxMusico.idOrquesta = idOrquesta;

		//ID DE INSTRUMENTO
		auxMusico.idInstrumento = 999;

		//TENGO TODO CARGADO
		if (Validate_Exit_SN("CONTINUAR SI[S] - NO[N]: ",
				"ERROR. REINGRESE: "))
		{
			auxMusico.iDMusico = eMusico_ObtenerID();
			auxMusico.isEmpty = 0;
			arrayMusico[posicion] = auxMusico;
			retorno = 1;
		}
	}
	return retorno;
}
void eMusicoOrquestaInstrumento_MostrarUno(eMusico Musico, eOrquesta o, eInstrumento i){

}
void Nada(void){
	/*eMusico m;

	int indiceOrquesta = eOrquesta_BuscarPorID(arrayOrquesta, TAM_Orq, m.idOrquesta);
	int indiceInstrumento = eInstrumento_BuscarPorID(arrayInstrumento, TAM_Ins, m.idInstrumento);
	*/
}
