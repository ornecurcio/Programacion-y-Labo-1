/*
 ============================================================================
 Name        : Ejercicio 4-2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Realizar un programa que permita la carga de temperaturas en celsius y fahrenheit ,
 validando que las temperaturas ingresadas estén entre el punto de congelación y ebullición del agua para cada tipo de escala.
Las validaciones se hacen en una biblioteca.
Las funciones de transformación de fahrenheit a celsius y de celsius a fahrenheit se hacen en otra biblioteca.

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "transformacion.h"
int main()
{
    int temp1;
    int temp2;
    int pasaje1;
    int pasaje2;

    printf("Igrese temperatura en fahrenheit ");
    scanf("%d", &temp1);

    temp1= validar(temp1);

    printf("Ingrese temperatura en celsius ");
    scanf("%d", &temp2);

    temp2=validar(temp2);

    transformacion(temp1, temp2);

    return 0;
}

