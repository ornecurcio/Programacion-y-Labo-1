/*
 * conversionTemperatura.c
 *
 *  Created on: 8 abr. 2021
 *      Author: orne_
 */
#include <stdio.h>
#include <stdlib.h>

int transformacion (int grado1, int grado2)
{
    int fahrenheit;
    int celsius;

    fahrenheit=(grado2*9/5)+32;
    celsius=(grado1-32)*5/9;

    printf("/n La temperatura de celsius a fahrenheit es %d y de fahrenheit a celsius es %d", fahrenheit, celsius);
    return 0;
}

