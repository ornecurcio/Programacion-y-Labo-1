/*
 * numeros.c
 *
 *  Created on: 1 abr. 2021
 *      Author: orne_
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

static int getInt(int* pResultado);
int esNumerica(char* cadena, int longitud);
int getFloat(float* pResultado);
int esFlotante(char* cadena, int longitud);
int myGets(char* cadena, int longitud);

void getString(char mensaje[], char imput[])
{
	printf("%s", mensaje);
	gets(imput);
}
//------VALIDACIONES COSAS- dan 1 si TRUE
int esNumerica(char* cadena, int longitud)
{
	int retorno= 1;
	int i;
	if(cadena!=NULL)
	{

		for(i=0; i<longitud && cadena[i]!='\0'; i++)
		{
			if(i==0 && (cadena[i]=='+' || cadena[i]=='-'))
			{
				continue;
			}
			if(cadena[i]<'0'||cadena[i]>'9')
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
int esFlotante(char* cadena, int longitud)
{
	int retorno= 1;
	int i;
	int contadorPunto=0;
	if(cadena!=NULL && strlen(cadena)>0)
	{
		for(i=0; i<longitud && cadena[i]!='\0'; i++)
		{
			if(i==0 && (cadena[i]=='+' || cadena[i]=='-'))
			{
				continue;
			}
			if(cadena[i]<'0'||cadena[i]>'9')
			{
				if(cadena[i]=='.' && contadorPunto==0)
				{
					contadorPunto++;
				}
				else
				{
				retorno=0;
				break;
				}
			}
		}
	}
	return retorno;
}
int esNombre(char* cadena,int longitud)
{
	int retorno = 1;

	if(cadena!=NULL && longitud>0)
	{
		for(int i=0; i<=longitud && cadena[i] != '\0';i++)
		{
			if((cadena[i]<'A' || cadena[i]>'Z') && (cadena[i]<'a' || cadena[i]>'z') && cadena[i] != '.')
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
int esSoloLetra(char *pResultado)
{
	int retorno = 1;
	int i;

	if(pResultado!=NULL && strlen(pResultado)>0)
	{
		for (i = 0; i<strlen(pResultado); i++)
		{
			if (isalpha(pResultado[i]) == 0)
			{
				retorno = 0;
				break;
			}
		}
	} else {
		retorno = 0;
	}
	return retorno;
}
int esLetraConEspacio(char *pResultado)
{
	int retorno = 1;
	int i;

	if (pResultado!=NULL && strlen(pResultado)>0)
	{
		for(i = 0; i < strlen(pResultado); i++)
		{
			if (isalpha(pResultado[i])==0)
			{
				if (isspace(pResultado[i])==0)
				{
					retorno=0;
					break;
				}
			}
		}
	}
	else
	{
		retorno=0;
	}
	return retorno;
}
int esTelefonoValido(char* cadena)
{
    int retorno=1;
    int i;
    for(i=0;cadena[i]!='\0';i++)
    {
        if((cadena[i]<'0' || cadena[i]>'9') && (cadena[i]!='-' || cadena[i]!=' '))
        {
            retorno=0;
            break;
        }
    }
    return retorno;
}
//------GETS COSAS----------
int myGets(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[5000];
	if(cadena!=NULL && longitud>0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString),stdin)!=NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] =='\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString))<=longitud)
			{
				strncpy(cadena, bufferString, longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}
static int getInt(int* pResultado)
{
	int retorno = -1;
	char bufferString[50];
	if(pResultado!=NULL)
	{
		if(myGets(bufferString, sizeof(bufferString))==0 && esNumerica(bufferString, sizeof(bufferString))==1)
		{
			*pResultado=atoi(bufferString);
			retorno=0;
		}
	}

	return retorno;
}
int getFloat(float* pResultado)
{
	int retorno = -1;
	char buffer[64];
	if(pResultado!=NULL)
	{
		if(myGets(buffer, sizeof(buffer))==0 && esFlotante(buffer, sizeof(buffer))==1)
		{
			*pResultado=atof(buffer);
			retorno=0;
		}
	}
	return retorno;
}
int getNombre(char* pResultado, int longitud)
{
	int retorno=-1;
	char buffer[5000];
	if(pResultado!=NULL && longitud>0)
	{
		if(myGets(buffer, sizeof(buffer))==0 && esNombre(buffer, sizeof(buffer))!=0 && strnlen(buffer, sizeof(buffer))<=longitud)
		{
			strncpy(pResultado, buffer, longitud);
			retorno=0;
		}
	}
	return retorno;
}
//------------UTN cosas-----------
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInterno;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			if(getInt(&bufferInterno)==0 && bufferInterno>=minimo && bufferInterno<=maximo)
			{
				*pResultado=bufferInterno;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getNumeroFlotante(float* pResultado,char* mensaje,char* mensajeError,float minimo,float maximo,int reintentos)
{
	int retorno = -1;
	float bufferInterno;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			if(getFloat(&bufferInterno)==0 && bufferInterno>=minimo && bufferInterno<=maximo)
			{
				*pResultado=bufferInterno;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char string[][20], int cantidadArray, int reintentos)
{
	int retorno = -1;
	char bufferChar[40];

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%s", bufferChar);

			if(strlen(bufferChar)<20)
			{
				strcpy(pResultado,bufferChar);
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getCaracterSexo(char* pResultado,char* mensaje,char* mensajeError, char string[][20], int cantidadArray, int reintentos)
{
	int retorno = -1;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{

		do
		{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%s", &bufferChar);
			if(bufferChar=='f'|| bufferChar=='m' || bufferChar=='o')
			{
				*pResultado=bufferChar;
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getString(char aux[],char* mensaje,char* mensajeError, int reintentos)
{
	int retorno = -1;
	char bufferString[40];

	if(aux != NULL && mensaje != NULL && mensajeError != NULL && reintentos>0)
	{
		do
		{
			printf("%s", mensaje);
			if(myGets(bufferString,40)==0)
			{
				strcpy(aux, bufferString);
				retorno=0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getNombre(char* pResultado, char* mensaje, char* mensajeError,int reintentos, int longitud)
{
	char bufferString[1000];
	int retorno = -1;

	if(mensaje != NULL && mensajeError != NULL && pResultado != NULL && reintentos >= 0 && longitud > 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getNombre(bufferString, 1000)==0)
			{
				strncpy(pResultado,bufferString,longitud);
				retorno = 0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		}while(reintentos>=0);
	}
	return retorno;
}
int utn_getTelefono(char* pResultado, char* mensaje, char* mensajeError, int minSize, int maxSize, int min, int max, int reintentos)
{
    int retorno=-1;
    char bufferStr[50];

    if(mensaje!=NULL && mensajeError!=NULL && minSize<maxSize && min<max && reintentos>=0 && pResultado!=NULL)
    {
        do
        {
        	printf("%s",mensaje);
            if(myGets(bufferStr, 50)==0 && esTelefonoValido(bufferStr)==1)
            {
                    strcpy(pResultado,bufferStr);
                    retorno=0;
                    break;
            }
            else
			{
				printf("%s 2",mensajeError);
				reintentos--;
			}
        }
        while(reintentos>=0);
    }
    return retorno;
}
//-------ARRAY cosas----
void inicializarArrayChar(char pArray[], int cantidadDeArray)
{
	int i;

	for(i=0; i<cantidadDeArray; i++)
	{
		pArray[i]=' ';
	}
}
int inicializarArrayFlotante(float pArray[], int cantidadDeArray)
{
	int retorno=-1;
	int i;
	   if(pArray!=NULL && cantidadDeArray>0)
	   {
			for(i=0; i<cantidadDeArray; i++)
			{
				pArray[i]=0;
			}
			retorno=0;
	   }
	  return retorno;
}
int imprimirArrayFlotante(float pArray[], int cantidadDeArray)
{
	int retorno=-1;
	int i;
	   if(pArray!=NULL && cantidadDeArray>0)
	   {
			for(i=0; i<cantidadDeArray; i++)
			{
				printf("\nIndice [%d] - Valor %2.f", i, pArray[i]);
			}
			retorno=0;
	   }
	  return retorno;
}
int inicializarArrayCadena(char pArray[][20], int cantidadDeArray)
{
	int retorno=-1;
	int i;
	if(pArray!=NULL && cantidadDeArray>0)
	{
		for(i=0; i<cantidadDeArray; i++)
		{
			strcpy(pArray[i],"");
		}
		retorno=0;
	}
	return retorno;
}
int utn_SwapAscendiente(int listaDeArray[],int cantidadDeArray)
{
	int i;
	int j;
	int aux;
	int retorno = -1;
	if(listaDeArray!=NULL && cantidadDeArray>0)
	{
		for(i=0; i<cantidadDeArray-1; i++)
		{
			for(j=i+1; j<cantidadDeArray; j++)
			{
				if(listaDeArray[i]>listaDeArray[j])
				{
					aux=listaDeArray[i];
					listaDeArray[i]=listaDeArray[j];
					listaDeArray[j]=aux;
				}

			}
		}
		retorno=0;
	}
	return retorno;
}

void FormaApellidoNombre(char *pNombre, char *pApellido, char *pCompleto)
{
	strcpy(pCompleto, pApellido);
	strcat(pCompleto, ", ");
	strcat(pCompleto, pNombre);
	strlwr(pCompleto);
	if (strlen(pNombre) > 0 && strlen(pApellido) > 0)
	{
		for(int i = 0; i < strlen(pCompleto); i++)
		{
			if (i == 0 && isspace(pCompleto[i]) == 0)
			{
				pCompleto[0] = toupper(pCompleto[0]);

			}
			else
			{
				if (isspace(pCompleto[i]) && i < strlen(pCompleto) - 1)
				{
					pCompleto[i + 1] = toupper(pCompleto[i + 1]);
				}
			}
		}
	}
}
int utn_getCUIT(char* msg, char* msgError, int reintentos, char* input)
{
    int maxSize=14; //con guiones 13 elementos
    int minSize=11;  // sin puntos
    int retorno=-1;
    char bufferStr[maxSize];

    if(msg!=NULL && msgError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!getString(msg,msgError,minSize,maxSize,&reintentos,bufferStr)&&isValidCUIT(bufferStr)==1) //==0 sin errores !0
            {
                strncpy(input,bufferStr,maxSize);
                retorno=0;
                break;
            }
            else
            {
                printf("%s 2",msgError);
                reintentos--;
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int isValidCUIT(char* stringRecibido)
{
    int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
    int i;
    int j;
    char buffer[14];
    strncpy(buffer,stringRecibido,14);

    for(i=0;buffer[i]!='\0';i++)
    {
        if((buffer[i]<'0' || buffer[i]>'9') && (buffer[i]!='-')) // chequeo que solo sean numeros o -
        {
            retorno=0;
            break;
        }

        if(buffer[i]=='-')  //elimino los -
        {
            for(j=i;buffer[j]!='\0';j++)
            {
                strncpy(&buffer[j],&buffer[j+1],1);
            }
        }
    }

    int digitos[10]={2,3,4,5,6,7,2,3,4,5};
    int acumulado = 0;
    int verificador;

    for(i=0;i < strlen(buffer-1); i++)
    {
        acumulado+=buffer[i]*digitos[i];
    }

    verificador=11-(acumulado%11);
	if(verificador == 11)
	{
		verificador = 0;
	}

	if(buffer[11]!=verificador)
    {
        retorno=0;
    }

    //if(stringRecibido[2]!='-' || stringRecibido[11]!='-' || stringRecibido[0]!='2' || stringRecibido[1]!='0' || stringRecibido[1]!='3' || stringRecibido[1]!='4' || stringRecibido[1]!='7')
    return retorno;
}
int getString(char* msg, char* msgError, int min, int max, int* reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max+10];

    if(msg!=NULL && msgError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",msg);   //no poner salto de linea, se va a pasar en el mensaje por valor
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max)    // tama?o (max) =cantidad de elementos (strlen) + 1(\0)
            {
                strncpy(resultado,bufferStr,max);
                retorno=0;
                break;
            }
            printf("%s 1",msgError);
            (*reintentos)--;
        }
        while((*reintentos)>=0);
    }
    return retorno;
}
