#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "notebooks.h"
#include "tipos.h"
#include "marcas.h"
#include "serviciosTrabajosNote.h"



int mostrarServicios(eServicio servicios[], int tam)
{
    int error = 1;
    int flag = 0;

    if(servicios!= NULL && tam > 0)
    {
        printf("\n   ID     Precio      Descripcion     \n");
        printf("--------------------------------------\n\n");
        for(int i=0; i<tam; i++)
        {
            if(servicios[i].id != 0)
            {
                mostrarServicio(servicios[i],tam);
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

void mostrarServicio(eServicio unServicio, int tam)
{
    printf(" %d    $%d        %s \n",unServicio.id,unServicio.precio ,unServicio.descripcion );
}

///////////

int buscarLibreTrabajo(eTrabajo trabajo[], int tam)
{
    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if(trabajo[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int altaTrabajo(eNotebook note[], int tam, int tamServicios, eTrabajo trabajo[], eServicio servicios[], eTipo tipos[], eMarca marcas[], int idTrabajo)
{
    int indiceId;
    int error=1;
    int indice;
    eTrabajo nuevoTrabajo;
    if(note!=NULL && servicios != NULL )
    {
        system("cls");
        printf("***  ALTA DE TRABAJO  ***\n");
        indice=buscarLibreTrabajo(trabajo,tam);

        nuevoTrabajo.id = idTrabajo;
        nuevoTrabajo.isEmpty = 0;
        printf("\n A continuacion se muestra una lista de las notebooks en sistema...\n\n");
        mostrarNotebooks(note, tam, tipos, marcas, tam );
        printf("\nIngrese el ID de la notebook que desea arreglar: ");
        scanf("%d",&nuevoTrabajo.idNotebook);
        indiceId = buscarNotebookID(note, tam, nuevoTrabajo.idNotebook);

		if(indiceId == -1)
		{
			printf("No existe una notebook con ese ID... \n");
			system("pause");
			return 1;
		}
		else
		{
		    printf("\nUsted ha seleccionado la siguiente notebook: \n\n");
			mostrarNotebook(note[indiceId],tipos,marcas,tam);
			system("pause");
		}
        system("cls");
        printf("***  ALTA DE TRABAJO  ***\n");
        mostrarServicios(servicios, tamServicios);
        printf("\nIngrese ID del servicio deseado: ");
        scanf("%d", &nuevoTrabajo.idServicio);

        trabajo[indice] = nuevoTrabajo;

        error = 0;

    }
    return error;
}


int mostrarTrabajos(eTrabajo trabajos[], eServicio servicios[], int tam)
{
    int error = 1;
    int flag = 0;

    if(trabajos!= NULL && tam > 0)
    {
        printf("\n  ID     IdNotebook     Descripcion     \n");
        printf("--------------------------------------\n\n");
        for(int i=0; i<tam; i++)
        {
            if(trabajos[i].isEmpty == 0)
            {
                mostrarTrabajo(trabajos[i],servicios,tam);
                flag = 1;
            }
        }

        if( flag == 0)
        {
            printf("No hay trabajos en la lista");
        }
        printf("\n\n");

        error = 0;
    }
    return error;
}


void mostrarTrabajo(eTrabajo unTrabajo, eServicio unServicio[], int tam)
{
    char descServicio[20];

    for (int i = 0; i < tam; i++)
    {
        if(unServicio[i].id == unTrabajo.idServicio)
        {
            strcpy(descServicio, unServicio[i].descripcion);
            break;
        }
    }
    printf("  %d    %d      %s \n",unTrabajo.id,  unTrabajo.idNotebook, descServicio);
}

int inicializarTrabajos(eTrabajo trabajo[], int tam)
{
    int error = 1;
    if (trabajo!=NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            trabajo[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}
