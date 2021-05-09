
#include "Instrumento.h"


void eInstrumento_Inicializar(eInstrumento array[], int cantidadDeArray)
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

int eInstrumento_BuscaLibre(eInstrumento array[], int cantidadDeArray)
{
	int retorno = -1;
	int i;

	if (array != NULL && cantidadDeArray > 0)
	{
		for (i = 0; i < cantidadDeArray; i++)
		{
			if (array[i].isEmpty == 1)
			{
				//devuelvo por el retorno la posicion libre
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int eInstrumento_BuscarPorID(eInstrumento array[], int cantidadDeArray, int ID)
{
	int retorno = -1;
	int i;

	if (array != NULL && cantidadDeArray > 0)
	{
		for (i = 0; i < cantidadDeArray; i++)
		{
			if (array[i].iDInstrumento == ID && array[i].isEmpty == 0)
			{
				//devuelvo por el retorno la posicion donde esta el id que busco
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

void eInstrumento_MostrarUno(eInstrumento aInstrumento)
{
	//printf("\n       ID        NOMBRE        TIPO      \n");
	//printf("********************************************\n\n");

	printf("     %3d         %8s	      %2d          	\n", aInstrumento.iDInstrumento, aInstrumento.nombre, aInstrumento.tipo);

	//printf("%5d \n", Instrumento.iDInstrumento);
}

int eInstrumento_MostrarTodos(eInstrumento array[], int cantidadDeArray)
{
	int i;
	int retorno = -1;

	//CABECERA
	puts("\n\t> LISTADO Instrumento");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	if (array != NULL && cantidadDeArray > 0)
	{
		for (i = 0; i < cantidadDeArray; i++)
		{
			if (array[i].isEmpty == 0)
			{
				eInstrumento_MostrarUno(array[i]);
				retorno=0;
			}
		}
	}
	return retorno;
}

int eInstrumento_MostrarDadosDeBaja(eInstrumento array[], int cantidadDeArray)
{
	int i;
	int retorno = -1;

	//CABECERA
	puts("\t> Instrumento\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	if (array != NULL && cantidadDeArray > 0)
	{
		for (i = 0; i < cantidadDeArray; i++)
		{
			if (array[i].isEmpty == -1)
			{
				eInstrumento_MostrarUno(array[i]);
				retorno=0;
			}
		}
	}

	return retorno;
}

eInstrumento eInstrumento_CargarDatos(void)
{
	eInstrumento auxiliar;
	/** CARGAR DATOS NECESARIOS PARA EL ALTA*/
	/** IMPORTANTE - NO CARGAR ID NI ESTADO - SE HACE EN EL eInstrumento_Alta() */
	return auxiliar;
}

eInstrumento eInstrumento_ModificarUno(eInstrumento Instrumento)
{
	eInstrumento auxiliar = Instrumento;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eInstrumento_Alta(eInstrumento array[], int cantidadDeArray)
{
	int retorno = -1;
	eInstrumento auxInstrumento;

	//BUSCO ESPACIO EN ARRAY
	int posicion = eInstrumento_BuscaLibre(array, cantidadDeArray);

	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (posicion != -1)
	{
		//PIDO DATOS - CARGO Instrumento AUXILIAR
		auxInstrumento = eInstrumento_CargarDatos();
		//SETEO ID UNICO - VARIABLE AUTOINCREMENTAL
		auxInstrumento.iDInstrumento = eInstrumento_ObtenerID(); //cambiar esto
		//CAMBIO SU ESTADO A "OCUPADO"
		auxInstrumento.isEmpty = 0;

		//SETEO EL ARRAY CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		array[posicion] = auxInstrumento;
		//RETORNO 0 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		retorno = 0;
	}
	return retorno;
}

int eInstrumento_Baja(eInstrumento array[], int cantidadDeArray)
{
	int retorno = -1;
	int idInstrumento;
	int posicion;
	int flag = 0;

	//LISTO TODOS LOS Instrumento
	if (eInstrumento_MostrarTodos(array, cantidadDeArray))
	{
		//BANDERA EN 1 SI HAY Instrumento DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Instrumento PARA DAR DE BAJA
	if (flag)
	{
		//PIDO ID A DAR DE BAJA
		idInstrumento = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		//BUSCO INDEX POR ID EN ARRAY
		while (eInstrumento_BuscarPorID(array, cantidadDeArray, idInstrumento) == -1) {
			puts("NO EXISTE ID.");
			idInstrumento = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		}

		//OBTENGO INDEX DEL ARRAY DE Instrumento A DAR DE BAJA
		posicion = eInstrumento_BuscarPorID(array, cantidadDeArray, idInstrumento);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[posicion].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECcantidadDeArrayENTE
		retorno = 1;
	}

	return retorno;
}

int eInstrumento_Modificacion(eInstrumento array[], int cantidadDeArray) {
	int retorno = 0;
	int idInstrumento;
	int posicion;
	int flag = 0;
	eInstrumento auxiliar;

	//LISTO TODOS LOS Instrumento
	if (eInstrumento_MostrarTodos(array, cantidadDeArray))
	{
		//BANDERA EN 1 SI HAY Instrumento DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Instrumento PARA MODIFICAR
	if (flag)
	{
		//PIDO ID A MODIFICAR
		idInstrumento = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		//BUSCO INDEX POR ID EN ARRAY
		while (eInstrumento_BuscarPorID(array, cantidadDeArray, idInstrumento) == -1) {
			puts("NO EXISTE ID.");
			idInstrumento = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		}

		//OBTENGO INDEX DEL ARRAY DE Instrumento A MODIFICAR
		posicion = eInstrumento_BuscarPorID(array, cantidadDeArray, idInstrumento);

		//LLAMO A FUNCION QUE MODIFICA Instrumento
		auxiliar = eInstrumento_ModificarUno(array[posicion]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[posicion] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECcantidadDeArrayENTE
		retorno = 1;
	}

	return retorno;
}

int eInstrumento_Sort(eInstrumento array[], int cantidadDeArray, int criterio) {
	int retorno = 0;
	int i;
	int j;
	eInstrumento aux;

	/** EJEMPLO DE SORT CON ID DE Instrumento */
	/** MODIFICAR "CRITERIO DE ORDENAMIENTO" PARA OTROS CASOS DE ORDENAMIENTO */

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && cantidadDeArray > 0)
	{
		switch (criterio)
		{
		case -1:
			for (i = 0; i < cantidadDeArray - 1; i++)
			{
				for (j = i + 1; j < cantidadDeArray; j++)
				{
					//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
					if (array[i].isEmpty == 0 && array[j].isEmpty == 0)
					{
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idInstrumento > array[j].idInstrumento)
						{
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			retorno = 1;
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
						if (array[i].idInstrumento < array[j].idInstrumento)
						{
							//INTERCAMBIO POSICIONES EN ARRAY
							aux = array[i];
							array[i] = array[j];
							array[j] = aux;
						}
					}
				}
			}
			retorno = 1;
			break;
		default:
			//CRITERIO DE ORDENAMIENTO MAL INGRESADO
			retorno = 0;
			break;
		}
	}
	return retorno;
}



