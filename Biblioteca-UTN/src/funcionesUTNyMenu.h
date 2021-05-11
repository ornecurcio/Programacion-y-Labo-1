/*
 * numeros.h
 *
 *  Created on: 1 abr. 2021
 *      Author: orne_
 */

#ifndef FUNCIONESUTNYMENU_H_
#define FUNCIONESUTNYMENU_H_
/**
 * \brief
 * \param char* cadena es un puntero donde se va a guardar el string
 * \param longitud, la longitud del cadena de caracteres
 * return Retorna 0 si se valido con exito la toma del string.
 */
int myGets(char* cadena, int longitud);
/**
 * \brief OBTIENE UN NUMERO ENTERO
 * \param pResultado es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * return Retorna 0 si se valido con exito o -1, si es error.
 */
static int getInt(int* pResultado);
/**
 * \brief valida que la cadena obtenida sea numerica
 * \param cadena es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud es la longitud maxima de la cadena de caracteres
 * return Retorna 1 si los caracteres son todos numericos, tomando en cuenta que puede haber
 * un signo + o menos en la posicion cero,  o 0, SI ES ERROR.
 */
static int esNumerica(char* cadena, int longitud);
int subMenu(void);
/*obtiene un numero entero, asigno el resultado a un espacio de memoria,
 * muestra un mensaje de ingreso de dato, un mensaje de error si la validacion esta mal,
 * valida contra minimo y maximo
 * estable cantidad de reintentos de error.
 * */
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

/**
 * \brief valida que la cadena obtenida es FLOTANTE
 * \param cadena es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * return Retorna 0 si el numero es flotante, -1, SI ES ERROR.
 */
static int getFloat(int* pResultado);
/**
 * \brief valida que la cadena obtenida sea flotante
 * \param cadena es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param longitud es la longitud maxima de la cadena de caracteres
 * return Retorna 1 si la cadena es flotante,o 0, SI ES ERROR.
 */
static int esFlotante(char* cadena, int longitud);
/**
 * \brief Solicita un numero FLOTANTE al usuario, luego de verificarlo devuelve el resultado
 * \param pResultado es un puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \param mensaje es el mensaje a ser mostrado al usuario
 * \param mensajeError es el mensaje a ser mostrado al usuario cuando lo ingresado es incorrecto
 * \param minimo es el numero minimo a ser aceptado
 * \param maximo es el numero maximo a ser aceptado
 *  \return Retorna 0 si se obtuvo el numero o, 1 SI ES ERROR.
 */
int utn_getNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos);

int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);
#endif /* FUNCIONESUTNYMENU_H_ */
