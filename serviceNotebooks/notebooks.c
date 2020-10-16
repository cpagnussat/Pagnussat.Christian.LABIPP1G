#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "notebooks.h"
#include "marcas.h"
#include "tipos.h"


char menuOpciones()
{
    char opcion;
    printf("*** SERVICE DE NOTEBOOKS***\n\n");
    printf("a- ALTA NOTEBOOK\n");
    printf("b- MODIFICAR NOTEBOOK\n");
    printf("c- BAJA NOTEBOOK\n");
    printf("d- LISTAR NOTEBOOKS\n");
    printf("e- LISTAR MARCAS\n");
    printf("f- LISTAR TIPOS\n");
    printf("g- LISTAR SERVICIOS\n");
    printf("h- ALTA TRABAJO\n");
    printf("i- LISTAR TRABAJOS\n");
    printf("j- Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());
    return opcion;
}


int inicializarNotebooks(eNotebook note[], int tam)
{
    int error = 1;
    if (note!=NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            note[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}


int buscarLibre(eNotebook note[], int tam)
{
    int indice = -1;
    for(int i = 0; i < tam; i++)
    {
        if(note[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}



int buscarNotebooks(eNotebook note[], int tam, int id)
{
	int retorno = -1;

	if( note != NULL && tam > 0)
	{
		for( int i = 0 ; i < tam ; i++ )
		{
			if(note[i].id == id && note[i].isEmpty == 0 )
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}


int buscarNotebookID(eNotebook note[], int tam, int id)
{
	int retorno = -1;

	if( note != NULL && tam > 0)
	{
		for( int i = 0 ; i < tam ; i++ )
		{
			if(note[i].id == id && note[i].isEmpty == 0 )
			{
				retorno = i;
				break;
			}
		}
	}

	return retorno;
}


int mostrarNotebooks(eNotebook notes[], int tam, eTipo tipos[], eMarca marcas[], int tamTM)
{
    int error = 1;
    int flag = 0;
    if(notes!= NULL && tam > 0)
    {
        printf(" ID    Modelo   Precio    Tipo      Marca       \n");
        printf("------------------------------------------------\n\n");
        for(int i=0; i<tam; i++)
        {
            if(notes[i].isEmpty == 0)
            {

                mostrarNotebook(notes[i],tipos,marcas, tamTM);
                flag = 1;
            }
        }
        if( flag == 0)
        {
            printf("No hay notebooks en la lista");
        }
        printf("\n\n");

        error = 0;
    }
    return error;
}

void mostrarNotebook(eNotebook unaNote, eTipo tipos[], eMarca marcas[], int tam)
{
    char descTipo[20];
    char descMarca[20];

    for (int i = 0; i < tam; i++)
    {
        if(tipos[i].id == unaNote.idTipo)
        {
            strcpy(descTipo, tipos[i].descripcion);
            break;
        }
    }

    for (int i = 0; i < tam; i++)
    {
       if(marcas[i].id == unaNote.idMarca)
        {
            strcpy(descMarca, marcas[i].descripcion);
            break;
        }
    }
    printf(" %d   %d       %d       %s         %s     \n",unaNote.id,unaNote.modelo ,unaNote.precio, descTipo, descMarca);
}



int altaNotebook(eTipo tipos[], eMarca marcas[], eNotebook note[],int tam,int id)
{
    int error=1;
    int indice;
    eNotebook nuevaNotebook;
    if(note!=NULL && tam > 0 && id > 0)
    {
        system("cls");
        printf("***  ALTA DE NOTEBOOK  ***\n");
        indice = buscarLibre(note, tam);
        if(indice == -1)
        {
            printf("El sistema esta completo.\n\n");
        }
        else
        {
            nuevaNotebook.id = id;
            nuevaNotebook.isEmpty = 0;
            mostrarMarcas(marcas,tam);
            printf("\nIngrese ID de la marca: ");
            scanf("%d",&nuevaNotebook.idMarca);
            printf("\nIngrese modelo(###): ");
            scanf("%d", &nuevaNotebook.modelo);
            system("cls");
            printf("***  ALTA DE AUTO  ***\n");
            mostrarTipos(tipos,tam);
            printf("\nIngrese ID de tipo: ");
            scanf("%d", &nuevaNotebook.idTipo);
            printf("\nIngrese precio(###): ");
            fflush(stdin);
            scanf("%d", &nuevaNotebook.precio);
            note[indice] = nuevaNotebook;

            error = 0;
        }
    }
    return error;
}


int bajaNotebook(eNotebook note[], int tam, eTipo tipos[], eMarca marcas[], int tamTC)
{
	int error = 1;
	int id;
	int indice;
	char confirma;

	if( note != NULL && tam > 0)
	{
		system("cls");
		printf("	*** Baja de NOTEBOOK *** 	\n\n");

		mostrarNotebooks(note,tam,tipos,marcas,tamTC);

		printf("Ingrese el ID: ");
		scanf("%d", &id);

		indice = buscarNotebookID(note, tam, id);

		if(indice == -1)
		{
			printf("No existe una notebook con ese ID... \n");
		}
		else
		{
		    printf("\nUsted ha seleccionado la siguiente Notebook: \n\n");
			mostrarNotebook(note[indice],tipos,marcas,tamTC);
			printf("\nDesea dar de baja esta notebook? s/n ");
			fflush(stdin);
			scanf("%c", &confirma);

			if(confirma == 's')
			{
				note[indice].isEmpty = 1;

				error=0;
			}
			else
			{
				error = 2 ;
			}

		}
	}

	return error;
}


int modificarNotebook(eNotebook note[], eTipo tipos[], eMarca marca[], int tam)
{
	int error = 1;
	int id;
	int indice;
	char confirma;
	int opcionModif;

	eNotebook noteAux;

	if( note != NULL && tam > 0)
	{
		system("cls");
		printf("	*** Modificar Notebook *** 	\n\n");

		mostrarNotebooks(note, tam,tipos, marca, tam);

		printf("Ingrese la id: ");
		scanf("%d", &id);

		indice = buscarNotebookID(note, tam, id);

		if(indice == -1)
		{
			printf("No existe una notebook con ese id... \n");
			system("pause");
		}
		else
		{
			mostrarNotebook(note[indice],tipos,marca,tam);

			printf("\n\nSeleccione el dato a modificiar: \n\n");
			printf("1- Tipo\n");
			printf("2- Precio\n\n");
			printf("Indique la opcion: ");
			scanf("%d", &opcionModif);

			switch(opcionModif)
			{
            case 1:
                system("cls");
                printf("\n**** Modificar Tipo ****\n\n ");
                mostrarTipos(tipos,tam);

                printf("\nIngrese el id del tipo nuevo: ");
                scanf("%d", &noteAux.idTipo);

                printf("Confirma modificacion? s/n:  ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);
                printf("\n\n");

                if(confirma == 's')
                {
                    note[indice].idTipo=noteAux.idTipo;
                    mostrarNotebook(note[indice],tipos,marca,tam);
                    system("pause");

                    error=0;
                }
                else
                {
                    error = 2 ;
                }
                break;
            case 2:
                system("cls");
                printf("\n**** Modificar Precio ****\n\n ");

                printf("\nIngrese el precio nuevo: ");
                scanf("%d", &noteAux.precio);

                printf("Confirma modificacion? s/n:  ");
                fflush(stdin);
                scanf("%c", &confirma);
                confirma = tolower(confirma);
                printf("\n\n");

                if(confirma == 's')
                {
                    note[indice].precio=noteAux.precio;
                    mostrarNotebook(note[indice],tipos,marca,tam);
                    system("pause");

                    error=0;
                }
                else
                {
                    error = 2 ;
                }
                break;
            default:
                printf("\nError, ingrese una opcion valida... \n");
			}
        }
	}

	return error;
}


int ordenarNotebooksPrecio(eNotebook note[], int tam)
{
    int error = 1;
	eNotebook noteAux;

	if (note != NULL && tam > 0)
    {
        for( int i = 0 ; i < tam -1 ; i++)
        {
            for(int j = i+1 ; j < tam ; j++)
            {
                if( note[i].precio > note[j].precio )
                {
                    noteAux = note[i];
                    note[i] = note[j];
                    note[j] = noteAux;
                }
            }
        }

        error = 0 ;
    }

	return error;
}

