/*
 * validacion.c
 *
 *  Created on: 8 abr. 2021
 *      Author: orne_
 */
#include <stdio.h>
#include <stdlib.h>

int validar (int grados)
{
    while(grados<0 || grados>212)
    {
        printf("Error Reigrese");
        scanf("%d", &grados);
        return 1;
    }

    return grados;
}

