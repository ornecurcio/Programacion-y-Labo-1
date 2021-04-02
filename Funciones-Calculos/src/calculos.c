#include <stdio.h>
#include <stdlib.h>
int sumar(int operadorUno, int operadorDos)
{
	int resultado;
	resultado = operadorUno+operadorDos;
	return resultado;
}
int restar(int operadorUno, int operadorDos)
{
	int resultado;
	resultado = operadorUno-operadorDos;
	return resultado;
}
int multiplicar(int operadorUno, int operadorDos, int* pResultado)
{
	int result;
	int retorno = -1;
		if(operadorDos!=0)
		{
			result=operadorUno*operadorDos;
			*pResultado = result;
			retorno=0;
		}
	return retorno;
}
int dividir(int operadorUno, int operadorDos,float* pResultado)
{
	float result;
	int retorno = -1;
	if(operadorDos!=0)
	{
		result=(float)operadorUno/operadorDos;
		*pResultado = result;
		retorno=0;
	}
	return retorno;
}
