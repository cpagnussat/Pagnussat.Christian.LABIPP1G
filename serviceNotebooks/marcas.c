#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "notebooks.h"
#include "tipos.h"

int mostrarMarcas(eMarca movil[], int tam)
{
    int error = 1;
    int flag = 0;

    if(movil!= NULL && tam > 0)
    {
        printf("\n   ID     Marca     \n");
        printf("----------------------\n\n");
        for(int i=0; i<tam; i++)
        {
            if(movil[i].id != 0)
            {
                mostrarMarca(movil[i],tam);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("No hay marcas en la lista");
        }
        printf("\n\n");

        error = 0;
    }
    return error;
}

void mostrarMarca(eMarca unaMarca, int tam)
{
    printf(" %d   %s \n",unaMarca.id,unaMarca.descripcion);
}
