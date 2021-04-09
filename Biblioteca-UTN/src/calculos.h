/*
 * calculos.h
 *
 *  Created on: 31 mar. 2021
 *      Author: orne_
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
/*brief calcula la suma de dos numeros recibido por parametro
 * param1 recibe un numero entero para sumar
 * param2 recibe un numero entero para sumar
 * retorno devuelve  0 o la suma de los numeros recibidos por parametro
 * */
int sumar(int* pResultado, int numUno, int numDos);



int restar(int* pResultado, int numUno, int numDos);
int multiplicar(int* pResultado, int numUno, int numDos);
int dividir(int* pResultado, int numUno, int numDos);

int promediarArray(float* pPromedioResultado, int array[], int cantidadArray);

#endif /* CALCULOS_H_ */
