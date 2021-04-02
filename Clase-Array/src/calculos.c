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


