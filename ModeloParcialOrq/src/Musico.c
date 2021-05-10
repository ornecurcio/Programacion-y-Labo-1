#include "Musico.h"

/**IMPORTANTE - SETEAR VALOR INICIAL CON EL PREFERIDO PARA COMENZAR IDs*/
//ID AUTOINCREMENTAL
int Musico_idIncremental = 0;

int eMusico_ObtenerID() {
	//INCREMENTA VARIABLE ESTATICA CADA VEZ QUE SE LLAMA ESTA FUNCION
	return Musico_idIncremental += 1;
}

void eMusico_Inicializar(eMusico array[], int cantidadDeArray)
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

int eMusico_BuscaLibre(eMusico array[], int cantidadDeArray)
{
	int retorno = -1;
	int i;

	if (array != NULL && cantidadDeArray > 0)
	{
		for (i = 0; i < cantidadDeArray; i++)
		{
			if (array[i].isEmpty == 1)
			{
				//OBTENGO EL PRIMER posicion DEL VECTOR "LIBRE" Y SALGO
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int eMusico_BuscarPorID(eMusico array[], int cantidadDeArray, int ID)
{
	int retorno = -1;
	int i;

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && cantidadDeArray > 0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < cantidadDeArray; i++)
		{
			//BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (array[i].iDMusico == ID && array[i].isEmpty == 0)
			{
				//SI ENCONTRE EL ID
				//DEVUELVO EL posicion DE DONDE ESTA EL ID BUSCADO Y SALGO
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

void eMusico_MostrarUno(eMusico Musico)
{
	//PRINTF DE UN SOLO Musico
	printf("%5d\n", Musico.iDMusico);
}

int eMusico_MostrarTodos(eMusico array[], int cantidadDeArray)
{
	int i;
	int retorno = 0;

	//CABECERA
	puts("\n\t> LISTADO Musico");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && cantidadDeArray > 0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < cantidadDeArray; i++)
		{
			//PREGUNTO POR SU ESTADO "OCUPADO"
			if (array[i].isEmpty == 0)
			{
				//MUESTRO UN SOLO Musico
				eMusico_MostrarUno(array[i]);
				//CONTADOR DE Musico
				retorno++;
			}
		}
	}

	return retorno;
}

int eMusico_MostrarDadosDeBaja(eMusico array[], int cantidadDeArray)
{
	int i;
	int retorno = -1;

	//CABECERA
	puts("\t> Musico\n");
	printf("%5s\n\n", "ID"); //AGREGAR TITULOS DE COLUMNA (QUITAR DE VER QUE NO ES NECESARIO)

	//SI EXISTE EL ARRAY Y EL LIMITE ES VALIDO
	if (array != NULL && cantidadDeArray > 0)
	{
		//RECORRO TODO EL ARRAY
		for (i = 0; i < cantidadDeArray; i++)
		{
			//PREGUNTO POR SU ESTADO "BAJA"
			if (array[i].isEmpty == BAJA)
			{
				//MUESTRO UN SOLO Musico
				eMusico_MostrarUno(array[i]);
				//CONTADOR DE Musico
				retorno++;
			}
		}
	}
	return retorno;
}

eMusico eMusico_CargarDatos(void)
{
	eMusico auxiliar;

	Get_OnlyAlphabetStringWithSpaces("INGRESE NOMBRE: ", "ERROR. REINGRESE: ", auxiliar.nombre, MAX_CHARS_CADENAS);
	Get_OnlyAlphabetStringWithSpaces("INGRESE APELLIDO: ", "ERROR. REINGRESE: ", auxiliar.apellido, MAX_CHARS_CADENAS);
	auxiliar.edad = Get_IntRange("INGRESE EDAD: ", "ERROR. REINGRESE: ", 1, 100);

	return auxiliar;
}

eMusico eMusico_ModificarUno(eMusico Musico)
{
	eMusico auxiliar = Musico;
	/** MODIFICAR DATOS NECESARIOS PARA EL "MODIFICAR" */
	/** IMPORTANTE - MODIFICAR EL AUXILIAR QUE ES LA COPIA DEL ORIGINAL */
	return auxiliar;
}

int eMusico_Alta(eMusico array[], int cantidadDeArray)
{
	int retorno = -1;
	eMusico auxMusico;

	//BUSCO ESPACIO EN ARRAY
	int posicion = eMusico_BuscaLibre(array, cantidadDeArray);

	//SI posicion == -1 ARRAY LLENO
	//SI posicion != -1 TENGO EN posicion POSICION DE ARRAY LIBRE
	if (posicion != -1) {
		//PIDO DATOS - CARGO Musico AUXILIAR
		auxMusico = eMusico_CargarDatos();
		//SETEO ID UNICO - VARIABLE AUTOINCREMENTAL
		auxMusico.iDMusico = eMusico_ObtenerID();
		//CAMBIO SU ESTADO A "OCUPADO"
		auxMusico.isEmpty = 0;

		//SETEO EL ARRAY CON AUXILIAR EN posicion LIBRE OBTENIDO PREVIAMENTE
		array[posicion] = auxMusico;
		//RETORNO 0 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		retorno = 0;
	}
	return retorno;
}

int eMusico_Baja(eMusico array[], int cantidadDeArray)
{
	int retorno = 0;
	int idMusico;
	int posicion;
	int flag = 0;

	//LISTO TODOS LOS Musico
	if (eMusico_MostrarTodos(array, cantidadDeArray)) {
		//BANDERA EN 1 SI HAY Musico DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Musico PARA DAR DE BAJA
	if (flag) {
		//PIDO ID A DAR DE BAJA
		idMusico = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		//BUSCO posicion POR ID EN ARRAY
		while (eMusico_BuscarPorID(array, cantidadDeArray, idMusico) == -1) {
			puts("NO EXISTE ID.");
			idMusico = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		}

		//OBTENGO posicion DEL ARRAY DE Musico A DAR DE BAJA
		posicion = eMusico_BuscarPorID(array, cantidadDeArray, idMusico);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//BAJA ACEPTADA - CAMBIO ESTADO A "BAJA"
		array[posicion].isEmpty = BAJA;

		//RETORNO 1 SI SE DIO DE BAJA CORRECcantidadDeArrayENTE
		retorno = 1;
	}

	return retorno;
}

int eMusico_Modificacion(eMusico array[], int cantidadDeArray) {
	int retorno = 0;
	int idMusico;
	int posicion;
	int flag = 0;
	eMusico auxiliar;

	//LISTO TODOS LOS Musico
	if (eMusico_MostrarTodos(array, cantidadDeArray)) {
		//BANDERA EN 1 SI HAY Musico DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	//SI HAY Musico PARA MODIFICAR
	if (flag) {
		//PIDO ID A MODIFICAR
		idMusico = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/

		//BUSCO posicion POR ID EN ARRAY
		while (eMusico_BuscarPorID(array, cantidadDeArray, idMusico) == -1) {
			puts("NO EXISTE ID.");
			idMusico = 1; /**USAR FUNCION GET_INT DE LIBRERIA DE INPUTS*/
		}

		//OBTENGO posicion DEL ARRAY DE Musico A MODIFICAR
		posicion = eMusico_BuscarPorID(array, cantidadDeArray, idMusico);

		//LLAMO A FUNCION QUE MODIFICA Musico
		auxiliar = eMusico_ModificarUno(array[posicion]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[posicion] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECcantidadDeArrayENTE
		retorno = 1;
	}

	return retorno;
}

int eMusico_Sort(eMusico array[], int cantidadDeArray, int criterio)
{
	int retorno = 0;
	int i;
	int j;
	eMusico aux;

	/** EJEMPLO DE SORT CON ID DE Musico */
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
					if (array[i].isEmpty == 0 && array[j].isEmpty == 0)
					{
						//CRITERIO DE ORDENAMIENTO
						if (array[i].idMusico > array[j].idMusico)
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
						if (array[i].iDMusico < array[j].iDMusico)
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
