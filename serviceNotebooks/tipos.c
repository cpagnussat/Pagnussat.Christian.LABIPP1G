#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "notebooks.h"
#include "marcas.h"


int mostrarTipos(eTipo tipo[], int tam)
{
    int error = 1;
    int flag = 0;

    if(tipo!= NULL && tam > 0)
    {
        printf("\n ID      Tipo     \n");
        printf("-------------------\n\n");
        for(int i=0; i<tam; i++)
        {
            if(tipo[i].id != 0)
            {
                mostrarTipo(tipo[i],tam);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("No hay tipos en la lista");
        }
        printf("\n\n");

        error = 0;
    }
    return error;
}

void mostrarTipo(eTipo unTipo, int tam)
{
    printf(" %d   %s \n",unTipo.id,unTipo.descripcion);
}
