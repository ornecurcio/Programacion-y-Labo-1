/*
 ============================================================================
 Name        : MemoriaDinamica.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Realizar una funcion que reciba como parametro un array de enteros, su tamaño y un entero.
 La funcion se encargara de buscar el valor y borrara la primer ocurrencia del mismo, el array deberá reestructurarse dinamicamente.
 ============================================================================
 */
/*
#include <stdio.h>
#include <stdlib.h>
int borrarPosicionDinamica(int* listadoEnteros,int* lengArray, int valorBusqueda);
int main(void)
{
	setbuf(stdout,NULL);
	int *arrayEnteros;
	int i;
	int lengArray = 5;
	arrayEnteros = (int *)malloc(sizeof(int)*lengArray);
	if(arrayEnteros != NULL)
	{
		*(arrayEnteros+0) = 2;
		*(arrayEnteros+1) = 6;
		*(arrayEnteros+2) = 7;
		*(arrayEnteros+3) = 2;
		*(arrayEnteros+4) = 6;
		//	2		 6 		 7 		 2 		 6
		borrarPosicionDinamica(arrayEnteros,&lengArray,6);
		printf("\nEl array de enteros esta compuesto por:\n\n");
		for (i = 0; i < lengArray; i++)
		{
			printf("\t %d \t",*(arrayEnteros+i));
		}
	}
	return EXIT_SUCCESS;
}
int borrarPosicionDinamica(int* listadoEnteros,int* lengArray, int valorBusqueda)
{
	int i;
	int j;
	int ret=-1;
	int* pAux = NULL;
	int contadorOcurrencias = 0;
	if(listadoEnteros != NULL && lengArray>0 && lengArray !=NULL)
	{
		for (i = 0; i < *lengArray; i++)
		{
			if(*(listadoEnteros+i) == valorBusqueda)
			{
				contadorOcurrencias++;
				for(j=i;j<*lengArray;j++)
				{
					*(listadoEnteros+j) = *(listadoEnteros+j+1);

				}//FIN FOR j
			}
		}//FIN FOR i
		*lengArray = *lengArray-contadorOcurrencias;
		pAux = (int *)realloc(listadoEnteros,*lengArray*sizeof(int));
		if(pAux != NULL)
		{
			listadoEnteros = pAux;
			ret = 0;
		}

	}

	return ret;
}
*/

#include <stdio.h>
#include <stdlib.h>
int borraNumArray(int* array, int* cantidadDeArray, int num);
int main(void) {
	setbuf(stdout,NULL);

	int* numeros=NULL;
	int cantidadDeArray=5;
	numeros=(int*)calloc(5,sizeof(int));
	if(numeros!=NULL)
	{
		printf("%p\n", numeros);
		printf("%d, %d, %d\n",*(numeros+0), *(numeros+1), *(numeros+2));
	}
	*(numeros+0)=2;
	*(numeros+1)=4;
	*(numeros+2)=2;
	*(numeros+3)=8;
	*(numeros+4)=1;

	printf("inicializados: %d, %d, %d, %d, %d\n",*(numeros+0), *(numeros+1), *(numeros+2), *(numeros+3), *(numeros+4));

	borraNumArray(numeros, &cantidadDeArray, 2);

	printf("array definitivo: ");
	for(int i=0; i<cantidadDeArray; i++)
	{
		printf("%d, ",*(numeros+i));
	}
	return EXIT_SUCCESS;
}
int borraNumArray(int* array, int* cantidadDeArray, int num)
{
	int i;
	int j;
	int retorno=-1;
	int* pAux=NULL;
	if(array!=NULL && cantidadDeArray>0)
	{
		for(i=0; i<*cantidadDeArray; i++)
		{
			if(num==*(array+i))
			{
				(*cantidadDeArray)--;
				for(j=i;j<*cantidadDeArray;j++)
				{
					*(array+j) = *(array+j+1);
				}
				break; // SI QUERES QUE ELIMINE TODAS LAS OCURRENCIAS BORRA ESTO
				printf("cantidad de array: %d\n", *cantidadDeArray);
			}
		}
		printf("borrrado el dos con array completo: %d, %d, %d, %d, %d\n",*(array+0), *(array+1), *(array+2), *(array+3), *(array+4));
		if((*cantidadDeArray)!=0)
		{
			pAux = (int*)realloc(array, (*cantidadDeArray)*sizeof(int));
			if(pAux!=NULL)
			{
				pAux=array;
				retorno=0;
			}
		}
	}
	return retorno;
}
/*
#include <stdio.h>
#include <stdlib.h>
void num_delete(int* numero);
int agregarNumArray(int* array, int* cantidadDeArray, int num, int posicion);
int main(void) {
	setbuf(stdout,NULL);
	int* numeros=NULL;
	int cantidadDeArray=9;
	int posicion;
	numeros=(int*)calloc(9,sizeof(int));
	if(numeros!=NULL)
	{
		printf("%p\n", numeros);
		printf("%d, %d, %d\n",*(numeros+0), *(numeros+1), *(numeros+2));
	}
	*(numeros+0)=2;
	*(numeros+1)=4;
	*(numeros+2)=2;
	*(numeros+3)=8;
	*(numeros+4)=2;
	*(numeros+5)=9;
	*(numeros+6)=3;
	*(numeros+7)=6;
	*(numeros+8)=7;

	printf("inicializados: ");
	for(int i=0; i<cantidadDeArray; i++)
	{
		printf("%d, ",*(numeros+i));
	}
	//printf("inicializados: %d, %d, %d, %d, %d\n",*(numeros+0), *(numeros+1), *(numeros+2), *(numeros+3), *(numeros+4));

	agregarNumArray(numeros, &cantidadDeArray, 5, 5);

	printf("array definitivo: ");
	for(int i=0; i<cantidadDeArray; i++)
	{
		printf("%d, ",*(numeros+i));
	}
	return EXIT_SUCCESS;
}
void num_delete(int* numero)
{
	free(numero);
}
int agregarNumArray(int* array, int* cantidadDeArray, int num, int posicion)
{
	int i;
	int j;
	int retorno=-1;
	int* pAux=NULL;
	if(array!=NULL && cantidadDeArray>0)
	{
		for(i=0; i<*cantidadDeArray; i++)
		{
			if(posicion==i)
			{
				(*cantidadDeArray)++;
				for(j=(*cantidadDeArray);j!=i;j--)
				{
					*(array+j)=*(array+(j-1));
				}
				*(array+i)=num;
				printf("cantidad de array: %d\n", *cantidadDeArray);
			}
		}
		printf("array completo: %d, %d, %d, %d, %d\n",*(array+0), *(array+1), *(array+2), *(array+3), *(array+4));
		if((*cantidadDeArray)!=0)
		{
			pAux = (int*)realloc(array, (*cantidadDeArray)*sizeof(int));
			if(pAux!=NULL)
			{
				pAux=array;
				retorno=0;
			}
		}
	}
	return retorno;
}
*/
