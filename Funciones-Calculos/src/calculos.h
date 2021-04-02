/*
 * calculos.h
 *
 *  Created on: 1 abr. 2021
 *      Author: orne_
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_

int sumar(int operadorUno, int operadorDos);
/*brief calcula la suma de dos numeros recibido por parametro
 * param1 recibe un numero entero para sumar
 * param2 recibe un numero entero para sumar
 * retorno devuelve la suma de los numeros recibidos por parametro
 * */
int restar(int operadorUno, int operadorDos);
/*brief calcula la suma de dos numeros recibido por parametro
 * param1 recibe un numero entero para sumar
 * param2 recibe un numero entero para sumar
 * retorno devuelve la resta de los numeros recibidos por parametro
 * */
int multiplicar(int operadorUno, int operadorDos, int* pResultado);
/*brief calcula la suma de dos numeros recibido por parametro
 * param1 recibe un numero entero para sumar
 * param2 recibe un numero entero para sumar
 * param3 recibe la direccion de mememoria para imprimir el resultado
 * retorno devuelve  0 cuando se realiza la multiplicacion o -1 cuando no se puede multiplicar por cero  */
int dividir(int operadorUno, int operadorDos, float* pResultado);
/*brief calcula la suma de dos numeros recibido por parametro
 * param1 recibe un numero entero para sumar
 * param2 recibe un numero entero para sumar
 * param3 recibe la direccion de mememoria para imprimir el resultado
 * retorno devuelve  0 cuando se realiza division o -1 cuando no se puede multiplicar por cero  */

#endif /* CALCULOS_H_ */
