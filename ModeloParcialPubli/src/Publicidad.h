/*
 * Publicidad.h
 *
 *  Created on: 12 may. 2021
 *      Author: orne_
 */

#ifndef PUBLICIDAD_H_
#define PUBLICIDAD_H_
typedef struct
{
	int idPublicidad;
	int idPantalla;
	int cuil;
	char archivo[51];
	int dias;
	int isEmpty;
}ePublicidad;

/** \brief  inicializa en el campo isEmpty en 1, libre
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \return int Returo (-1) si Error (0) si todo Ok
*/
int inicializarPublidad(ePublicidad pArray[], int cantidadDeArray);
/** \brief  busca en el campo isEmpty del array, un 1 para ingresar datos
* \param pArray el puntero al primer array
* \param cantidadDeArray int, a recorrer
* \return int Retorno (-1) si Error, retorna un int de posicion si todo Ok
*/
int buscaLibre(ePublicidad pArray[], int cantidadDeArray);
/** \brief alta un empleado, llama a otras funciones que valida los datos de cada campo a cargar
* \param aEmployee array donde se cargan los datos
* \param cantidadDeArray int, recorrer array
* \param contadorId int como puntero, donde se cargara el ID de manera autoincremental
* \return int Retorno (-1) si ERROR (0) SI TODO Ok
*/
int altaPublicidad(ePublicidad aEmployee[], int cantidadDeArray, int* contadorId);
/** \brief imprime un empleado
* \param aEmpleado, recibe por valor la estructura de un empleado
*/
void imprimir1Publicidad(ePublicidad aEmpleado);

int buscaPublidadById(ePublicidad aAuxiliar[], int cantidadDeArray);

int bajaPublicidad(ePublicidad aAuxiliar[], int posicion);

int ordenarPublicidad(ePublicidad array[], int cantidadDeArray, int criterio);

int imprimirPublicidad(ePublicidad array[], int cantidadDeArray);

int modifica1Publicidad(ePublicidad aAuxiliar[], int posicion);

int eEmployeePromSalario(float* pPromedioResultado, ePantalla array[], int cantidadDeArray);

int eEmployeesListaSalario(ePantalla array[], int cantidadDeArray, float salary);


#endif /* PUBLICIDAD_H_ */
