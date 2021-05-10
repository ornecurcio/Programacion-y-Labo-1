/*
 * Orquesta.c
 *
 *  Created on: 8 may. 2021
 *      Author: orne_
 */


#ifndef ORQUESTA_C_
#define ORQUESTA_C_

#include "Orquesta.h"

/**IMPORTANTE - SETEAR VALOR INICIAL CON EL PREFERIDO PARA COMENZAR IDs*/
//ID AUTOINCREMENTAL
int Orquesta_idIncremental = 0;

int eOrquesta_ObtenerID() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return Orquesta_idIncremental += 1;
}

void eOrquesta_Inicializar(eOrquesta array[], int cantidadDeArray)
{
	int i;

	if (array != NULL && cantidadDeArray > 0)
	{
		for (i = 0; i < cantidadDeArray; i++)
		{
			array[i].isEmpty = 1;
		}
	}
}
int eOrquesta_BuscaLibre(eOrquesta array[], int cantidadDeArray)
{
	int retorno = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && cantidadDeArray > 0)
	{
		for (i = 0; i < cantidadDeArray; i++)
		{
			if (array[i].isEmpty == 1)
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}

int eOrquesta_BuscarPorID(eOrquesta array[], int cantidadDeArray, int ID)
{
	int retorno = -1;
	int i;

	if (array != NULL && cantidadDeArray > 0)
	{
		for (i = 0; i < cantidadDeArray; i++)
		{
			if (array[i].idOrquesta == ID && array[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

void eOrquesta_MostrarUno(eOrquesta Orquesta)
{
	//PRINTF DE UN SOLO Orquesta
	printf("%5d %5d %15s %15s\n", Orquesta.idOrquesta, Orquesta.tipo, Orquesta.nombre, Orquesta.lugar);
}

int eOrquesta_MostrarTodos(eOrquesta array[], int cantidadDeArray)
{
	int i;
	int retorno = -1;

	//CABECERA
	puts("\n\t> LISTADO Orquesta");
	printf("%5s %5s %15s %15s\n\n", "ID", "TIPO", "NOMBRE", "LUGAR"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && cantidadDeArray > 0)
	{
		for (i = 0; i < cantidadDeArray; i++)
		{
			if (array[i].isEmpty == 0)
			{
				//MUESTRO UN SOLO Orquesta
				eOrquesta_MostrarUno(array[i]);
				//CONTADOR DE Orquesta
				retorno++;
			}
		}
	}
	return retorno;
}
int eOrquesta_MostrarDadosDeBaja(eOrquesta array[], int cantidadDeArray)
{
	int i;
	int retorno = -1;

	//CABECERA
	puts("\t> Orquesta\n");
	printf("%5s %5s %15s %15s\n\n", "ID", "TIPO", "NOMBRE", "LUGAR"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && cantidadDeArray > 0)
	{
		for (i = 0; i < cantidadDeArray; i++)
		{
			if (array[i].isEmpty == BAJA)
			{
				eOrquesta_MostrarUno(array[i]);
				//CONTADOR DE Orquesta
				retorno++;
			}
		}
	}

	return retorno;
}

eOrquesta eOrquesta_CargarDatos(void)
{
	eOrquesta auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL eOrquesta_Alta() */

	Get_OnlyAlphabetStringWithSpaces("INGRESE NOMBRE: ", "ERROR. REINGRESE: ",
			auxiliar.nombre, MAX_CHARS_CADENAS);
	Get_String("INGRESE LUGAR: ", "ERROR. REINGRESE: ", auxiliar.lugar,
	MAX_CHARS_CADENAS);
	auxiliar.fecha.dia = Get_IntRange("INGRESE DIA: ", "ERROR. REINGRESE: ", 1,
			31);
	auxiliar.fecha.mes = Get_IntRange("INGRESE MES: ", "ERROR. REINGRESE: ", 1,
			12);
	auxiliar.fecha.dia = Get_IntRange("INGRESE DIA: ", "ERROR. REINGRESE: ",
			1900, 2022);

	printf("\nSELECCIONE TIPO\n\t1- SINFONICA\n\t2- FILARMONICA\n\t3-CAMARA\n");

	switch (Get_IntRange("OPCION: ", "ERROR. REINGRESE: ", 1, 3))
	{
		case SINFONICA:
			auxiliar.tipo = SINFONICA;
			break;
		case FILARMONICA:
			auxiliar.tipo = FILARMONICA;
			break;
		case CAMARA:
			auxiliar.tipo = CAMARA;
			break;
	}
	return auxiliar;
}

eOrquesta eOrquesta_ModificarUno(eOrquesta Orquesta)
{
	eOrquesta auxiliar = Orquesta;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eOrquesta_Alta(eOrquesta array[], int cantidadDeArray)
{
	int retorno = -1;
	eOrquesta auxOrquesta;

	//BUSCO ESPACIO EN ARRAY
	int posicion = eOrquesta_BuscaLibre(array, cantidadDeArray);

	//SI posicion == -1 ARRAY LLENO
	//SI posicion != -1 TENGO EN posicion POSICION DE ARRAY LIBRE
	if (posicion != -1)
	{
		//PIDO DATOS - CARGO Orquesta AUXILIAR
		auxOrquesta = eOrquesta_CargarDatos();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxOrquesta.isEmpty = 0;

		//MOSTRAR EL DATO

		if (Validate_Exit_SN("DESEA CONTINUAR SI[S] - NO[N]: ",
				"ERROR. REINGRESE."))
		{
			//SETEO ID UNICO - VARIABLE AUTOINCREMENTAL
			auxOrquesta.idOrquesta = eOrquesta_ObtenerID();
			//SETEO EL ARRAY CON AUXILIAR EN posicion LIBRE OBTENIDO PREVIAMENTE
			array[posicion] = auxOrquesta;
			//RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
			retorno = 1;
		}
	}

	return retorno;
}

int eOrquesta_Baja(eOrquesta array[], int cantidadDeArray)
{
	int retorno = -1;
	int idOrquesta;
	int posicion;
	int flag = 0;

	//LISTO TODOS LOS Orquesta
	if (eOrquesta_MostrarTodos(array, cantidadDeArray))
	{
		//BANDERA EN 1 SI HAY Orquesta DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Orquesta PARA DAR DE BAJA
	if (flag)
	{
		//PIDO ID A DAR DE BAJA
		idOrquesta = Get_IntPositive("INGRESE ID A DAR DE BAJA: ",
				"ERROR. REINGRESE: ");
		/**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		//BUSCO posicion POR ID EN ARRAY
		while (eOrquesta_BuscarPorID(array, cantidadDeArray, idOrquesta) == -1)
		{
			puts("NO EXISTE ID.");
			idOrquesta = Get_IntPositive("INGRESE ID A DAR DE BAJA: ",
					"ERROR. REINGRESE: ");
		}

		//OBTENGO posicion DEL ARRAY DE Orquesta A DAR DE BAJA
		posicion = eOrquesta_BuscarPorID(array, cantidadDeArray, idOrquesta);

		if (Validate_Exit_SN("DESEA CONTINUAR SI[S] - NO[N]: ", "ERROR. REINGRESE."))
		{
			/**PREGUNTAR SI DESEA CONTINUAR*/

			/**for(int i = 0; i<T_MUSICOS; i++){
				if(idOrquesta == musico.idOrquesta){
					musico.isEmpty = BAJA;
				}
			}*/

			//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
			array[posicion].isEmpty = BAJA;

			//RETORNO 0 SI SE DIO DE BAJA CORRECcantidadDeArrayENTE
			retorno = 0;
		}
	}
	return retorno;
}

int eOrquesta_Modificacion(eOrquesta array[], int cantidadDeArray)
{
	int retorno = -1;
	int idOrquesta;
	int posicion;
	int flag = 0;
	eOrquesta auxiliar;

	//LISTO TODOS LOS Orquesta
	if (eOrquesta_MostrarTodos(array, cantidadDeArray))
	{
		//BANDERA EN 1 SI HAY Orquesta DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Orquesta PARA MODIFICAR
	if (flag)
	{
		//PIDO ID A MODIFICAR
		idOrquesta = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		//BUSCO posicion POR ID EN ARRAY
		while (eOrquesta_BuscarPorID(array, cantidadDeArray, idOrquesta) == -1)
		{
			puts("NO EXISTE ID.");
			idOrquesta = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		}

		//OBTENGO posicion DEL ARRAY DE Orquesta A MODIFICAR
		posicion = eOrquesta_BuscarPorID(array, cantidadDeArray, idOrquesta);

		//LLAMO A FUNCION QUE MODIFICA Orquesta
		auxiliar = eOrquesta_ModificarUno(array[posicion]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[posicion] = auxiliar;

		//RETORNO 0 SI SE MODIFICO CORRECcantidadDeArrayENTE
		retorno = 0;
	}
	return retorno;
}

int eOrquesta_Sort(eOrquesta array[], int cantidadDeArray, int criterio)
{
	int retorno = -1;
	int i;
	int j;
	eOrquesta aux;

	/** EJEMPLO DE SORT CON ID DE Orquesta */
	/** MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO */

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && cantidadDeArray > 0)
	{
		switch (criterio) {
		case -1:
			for (i = 0; i < cantidadDeArray - 1; i++)
			{
				for (j = i + 1; j < cantidadDeArray; j++)
				{
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == 0
							&& array[j].isEmpty == 0)
					{
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idOrquesta > array[j].idOrquesta)
						{
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			retorno = 0;
			break;
		case 1:
			for (i = 0; i < cantidadDeArray - 1; i++)
			{
				for (j = i + 1; j < cantidadDeArray; j++)
				{
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == 0 && array[j].isEmpty == 0)
					{
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idOrquesta < array[j].idOrquesta)
						{
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			retorno = 0;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			retorno = 0;
			break;
		}
	}
	return retorno;
}

#endif
