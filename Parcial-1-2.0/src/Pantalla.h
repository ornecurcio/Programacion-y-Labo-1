/*
 * Pantalla.h
 *
 *  Created on: 12 may. 2021
 *      Author: orne_
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_

typedef struct
{
	int tipo;
	char descripcion[50];
	int isEmpty;
}eTipo;

typedef struct
{
	char calle[50];
	int altura;
	char localidad[50];
}eDireccion;

typedef struct
{
	int tipo;
	int idPantalla;
	char name[51];
	eDireccion direccion;
	float precio;
	int isEmpty;
}ePantalla;


/** \brief  inicializa en el campo isEmpty en 1, libre
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \return int Returo (-1) si Error (0) si todo Ok
*/
int inicializarPantalla(ePantalla pArray[], int cantidadDeArray);
/** \brief  busca en el campo isEmpty del array, un 1 para ingresar datos
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \return int Retorno (-1) si Error, retorna un int de posicion si todo Ok
*/
int buscaLibrePantalla(ePantalla pArray[], int cantidadDeArray);
/** \brief alta un empleado, llama a otras funciones que valida los datos de cada campo a cargar
* \param aEmployee array donde se cargan los datos
* \param cantidadDeArray int, recorrer array
* \param contadorId int como puntero, donde se cargara el ID de manera autoincremental
* \return int Retorno (-1) si ERROR (0) SI TODO Ok
*/
int altaPantalla(ePantalla aEmployee[], int cantidadDeArray, int* contadorId);
/** \brief imprime un empleado
* \param aEmpleado, recibe por valor la estructura de un empleado
*/
void imprimir1Pantalla(ePantalla aPantalla, char* descripcion);

int imprimirPantallas(ePantalla array[], int cantidadDeArray, eTipo aTipos[], int cantidadTipos);

int buscaPantallaById(ePantalla aAuxiliar[], int cantidadDeArray, int* aID);

int bajaPantalla(ePantalla aAuxiliar[], int posicion, eTipo aTipos[], int cantidadTipos);

int ordenarPantalla(ePantalla array[], int cantidadDeArray, int criterio);

int modifica1Pantalla(ePantalla aAuxiliar[], int posicion, eTipo aTipos[], int cantidadTipos);

int getDescripcionPantalla(eTipo aTipo[], int cantidadDeArray, int buscar, char* descripcion);

//int eEmployeePromSalario(float* pPromedioResultado, ePantalla array[], int cantidadDeArray);

//int eEmployeesListaSalario(ePantalla array[], int cantidadDeArray, float salary);

#endif /* PANTALLA_H_ */
