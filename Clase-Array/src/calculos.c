#include <stdio.h>
#include <stdlib.h>

int sumar(int numUno, int numDos)
{
	int resultado = 0;

	if(numUno>0 || numDos<0)
		{
			resultado = numUno+numDos;
		}

	return resultado;
}
int promediarArray(float* pPromedioResultado, int array[], int cantidadArray)
{
	int i;
	int acumulador=0;
	float resultado;
	for(i=0; i<cantidadArray; i++)
	{
		acumulador = acumulador + array[i];
	}

	*pPromedioResultado = (float)acumulador/cantidadArray;

	return 0;
}

