#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "notebooks.h"
#include "tipos.h"
#include "marcas.h"
#include "serviciosTrabajosNote.h"
#include "utn.h"


/** \brief imprime usando la funcion mostrarServicio mediante iteraciones la totalidad del array
 *
 * \param servicios[] es el array a mostrar
 * \param tam el tamaño del mismo
 * \return retorna 1 si hubo algun error o 0 si pudo completar
 *
 */


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
/** \brief muestra un servicio individualmente
 *
 * \param unServicio es lo que se  va a mostrar
 * \return es void
 *
 */

void mostrarServicio(eServicio unServicio, int tam)
{
    printf(" %d    $%d        %s \n",unServicio.id,unServicio.precio ,unServicio.descripcion );
}

///////////


/** \brief busca la primer posicion en el array trabajo que contenga su parametro isEmpty en 1 para poder escribir en el
 *
 * \param trabajo[] el array a recorrer
 * \param tam el tamaño del array
 * \return  retorna el indice del array que se encuentra disponible para escribir
 *
 */

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

/** \brief da de alta un elemento de la estructura eTrabajo
 *
 * \param note trabajo servicios tipos y marcas son arrays de las estructuras que se utilizan dentro de esta funcion para dar de alta el trabajo de manera correcta
 * \param
 * \return retorna 1 si hubo algun error, 0 si pudo completar el alta
 *
 */


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
        while(validarServicioID(servicios,tam,nuevoTrabajo.idServicio) == 1 )
        {
            printf("\nError, ingrese el ID del servicio nuevamente: ");
            scanf("%d",&nuevoTrabajo.idServicio);
        }

        printf("\nIngrese la fecha de hoy dd/mm/aaaa: ");
        scanf("%d/%d/%d",&nuevoTrabajo.fecha.dia, &nuevoTrabajo.fecha.mes, &nuevoTrabajo.fecha.anio);

        trabajo[indice] = nuevoTrabajo;

        error = 0;

    }
    return error;
}

int validarServicioID(eServicio servicio[], int tam, int id)
{
	int retorno = 1;

	if( servicio != NULL && tam > 0)
	{
		for( int i = 0 ; i < tam ; i++ )
		{
			if(servicio[i].id == id )
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

/** \brief muestra iteraciones de la funcion mostrarTrabajo para mostrar la totalida de trabajos en sistema
 *
 * \param trabajos[] es el array a mostrar
 * \param servicios[] es el otro array que se le pasa a la funcuon mostrarTrabajo
 * \return retorna 1 si hubo algun error y 0 si pudo mostrar todo correctamente
 *
 */

int mostrarTrabajos(eTrabajo trabajos[], eServicio servicios[], int tam)
{
    int error = 1;
    int flag = 0;

    if(trabajos!= NULL && tam > 0)
    {
        printf("\n  ID     IdNotebook     Descripcion     Fecha  \n");
        printf("--------------------------------------------------\n\n");
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

/** \brief muestra el contenido del elemento de la estructura unTrabajo
 *
 * \param unTrabajo es el elemento a mostrar por la funcion
 * \param unServicio[] es el array de servicios que se va a recorrer para mostrar la descripcion junto con el trabajo
 * \return es void
 *
 */

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
    printf("  %d    %d      %s     %02d/%02d/%d\n",unTrabajo.id,  unTrabajo.idNotebook, descServicio, unTrabajo.fecha.dia, unTrabajo.fecha.mes, unTrabajo.fecha.anio);
}
/** \brief inicializa el valor de isEmpty del array trabajo de estructura eTrabajo para que esten en 1 y se pueda escribir sobre ellos
 *
 * \param trabajo[] el array a inicializar
 * \param tam tamaño del array
 * \return devuelve 1 si hubo algun error y 0 si pudo completarse
 *
 */

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

/** \brief muestra las notebooks en sistema y pide id, luego muestra los trabajos para esa determinada notebook
 *
 * \param note[] es el array de notebooks a mostrar
 * \param trabajo[] es el array de los trabajos en sistema a mostrar luego de seleccionada la notebook puntual
 * \return retorna 1 si hubo algun error o 0 si esta todo ok
 *
 */


int trabajosPorNotebook(eTipo tipos[], eMarca marcas[], eNotebook note[] , eTrabajo trabajo[], eServicio servicios[] ,int tam)
{
    int error = 1;
    int idNote;
    int indiceId;
    int contadorTrabajos = 0;


    system("cls");
    printf("***    TRABAJOS REALIZADOS POR NOTEBOOK    ***\n\n");
    printf("\n A continuacion se muestra una lista de las notebooks en sistema...\n\n");
    mostrarNotebooks(note, tam, tipos, marcas, tam );
    printf("\nIngrese el ID de la notebook que desea verificar: ");
    scanf("%d",&idNote);
    indiceId = buscarNotebookID(note, tam, idNote);

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
    printf("***    TRABAJOS REALIZADOS POR NOTEBOOK    ***\n\n");
    printf("A continuacion se muestran los trabajos realizados para la notebook seleccionada: \n");


    printf("\n  ID     IdNotebook     Descripcion     Fecha  \n");
    printf("--------------------------------------------------\n\n");
    for( int i = 0 ; i < tam ; i++ )
    {
        if( trabajo[i].idNotebook == idNote )
        {
            mostrarTrabajo(trabajo[i],servicios,tam);
            contadorTrabajos++;
        }
    error = 0;
    }
    if(contadorTrabajos==0)
    {
        printf("\n No hay trabajos para la notebook seleccionada\n\n");
        system("pause");
    }

    return error;

}

/** \brief pide una notebook por id y luego suma los importes de los services dados de alta para esta notebook
 *
 * \param note[] array de notebooks en sistema para seleccionar la que se quiere sumar sus trabajos
 * \param trabajo[] array donde se va a obtener el id del servicio dado de alta para sumar su valor
 * \return retorna 1 si hubo algun error o 0 si esta todo ok
 *
 */

int precioPorNotebook(eTipo tipos[], eMarca marcas[], eNotebook note[] , eTrabajo trabajo[], eServicio servicios[] ,int tam)
{
    int error = 1;
    int idNote;
    int idServicio;
    int indiceId;
    int contadorTrabajos = 0;
    int acumuladorPrecio = 0;


    system("cls");
    printf("***    SUMA DE LOS IMPORTES POR SERVICE    ***\n\n");
    printf("\n A continuacion se muestra una lista de las notebooks en sistema...\n\n");
    mostrarNotebooks(note, tam, tipos, marcas, tam );
    printf("\nIngrese el ID de la notebook que desea verificar: ");
    scanf("%d",&idNote);
    indiceId = buscarNotebookID(note, tam, idNote);

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
    printf("***    SUMA DE LOS IMPORTES POR SERVICE    ***\n\n");


    for( int i = 0 ; i < tam ; i++ )
    {
        if( trabajo[i].idNotebook == idNote )
        {
            idServicio = trabajo[i].idServicio;

            for( int j = 0 ; j < tam ; j++)
            {
                if(servicios[j].id == idServicio)
                {
                    acumuladorPrecio = acumuladorPrecio + servicios[j].precio;
                }
            }

            contadorTrabajos++;
        }
    error = 0;
    }
    if(contadorTrabajos==0)
    {
        printf("\n No hay trabajos para la notebook seleccionada\n\n");
        system("pause");
    }
    else
    {
        printf("\n La suma de los importes de los services realizados a esta notebook es de %d. \n",acumuladorPrecio);
        system("pause");
    }

    return error;

}

/** \brief se le muestra al usuario la lista de servicios y se le pide uno, luego se muestran los trabajos dados de alta para esos servicios solamente
 *
 * \param servicios[] se usa para mostrarle al cliente la lista de servicios
 * \param trabajos [] de aca se obtienen las coincidencias con el servicio seleccionado con el cliente y los trabajos dados de alta
 * \return  retorna 1 si hubo algun error y 0 si salio todo ok
 *
 */


int mostrarNotebooksPorServicio(eTipo tipos[], eMarca marcas[], eNotebook note[] , eTrabajo trabajo[], eServicio servicios[] ,int tam)
{
    int error = 1;
    int idServicio;
    int contadorMatch = 0;

    system("cls");
    printf("***    MOSTRAR NOTEBOOKS POR SERVICIO   ***\n\n ");
    printf("\n A continuacion se muestra una lista de los servicios...\n\n");
    mostrarServicios(servicios, tam);
    printf("\nIngrese el ID del servicio que desea verificar: ");
    scanf("%d",&idServicio);

    printf("\n   Notebook       Fecha  \n");
    printf("---------------------------------\n\n");
    for( int i = 0 ; i < tam ; i++ )
    {
        if(trabajo[i].idServicio == idServicio)
        {
            printf("     %d      %02d/%02d/%d \n", trabajo[i].idNotebook , trabajo[i].fecha.dia , trabajo[i].fecha.mes , trabajo[i].fecha.anio);
            contadorMatch++;
            error = 0;
        }
    }
    if(contadorMatch == 0)
    {
        printf("\n No hay notebooks en sistema a las que se le haya realizado este servicio. \n\n");
    }

    return error;
}

/** \brief se le pide una fecha al usuario y luego se muestra en pantalla los servicios realizados esa fecha
 *
 * \param trabajo[] aca se verifican los trabajos realizados en la fecha ingresada
 * \param
 * \return retorna 1 si todo mal y 0 si todo bien
 *
 */


int mostrarServiciosPorFecha(eTipo tipos[], eMarca marcas[], eNotebook note[] , eTrabajo trabajo[], eServicio servicios[] ,int tam)
{
    int error = 1;
    eFecha fechaAux;
    //int contadorMatch = 0;

    system("cls");
    printf("***    MOSTRAR SERVICIOS POR FECHA   ***\n\n ");

    printf("\nIngrese el la fecha que desea verificar dd/mm/aaaa: ");
    scanf("%d/%d/%d",&fechaAux.dia, &fechaAux.mes , &fechaAux.anio);

    printf("\n A continuacion se muestran los servicios realizados en la fecha %02d/%02d/%d \n\n",fechaAux.dia, fechaAux.mes , fechaAux.anio);
    for( int i = 0 ; i < tam ; i++ )
    {
        if(trabajo[i].fecha.anio == fechaAux.anio && trabajo[i].fecha.dia == fechaAux.dia && trabajo[i].fecha.mes == fechaAux.mes)
        {
            mostrarTrabajo(trabajo[i],servicios,tam);
            error=0;
        }
    }

    return error;
}
