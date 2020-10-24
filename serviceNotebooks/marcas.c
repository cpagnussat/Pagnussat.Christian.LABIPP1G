#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "notebooks.h"
#include "tipos.h"


/** \brief valida que el id ingresado corresponda a uno de los que estan dentro del array
 *
 * \param marca[] array donde se busca la coincidencia con el id
 * \param id es el id que se va a buscar para comparar dentro del array
 * \return retorna 1 si el id no coincide, y 0 si hay coincidencia dentro del array
 *
 */

int validarMarcaID(eMarca marca[], int tam, int id)
{
	int retorno = 1;

	if( marca != NULL && tam > 0)
	{
		for( int i = 0 ; i < tam ; i++ )
		{
			if(marca[i].id == id )
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

/** \brief muestra en pantalla interaciones de la funcion mostrarMarca para visualizar el array completo
 *
 * \param movil es el array a visualizar
 * \param tam es el tamaño del array
 * \return retorna 1 si hubo algun error y 0 si pudo completar
 *
 */

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


/** \brief muestra un elemento individual de la estructura eMarca
 *
 * \param unaMarca es lo que se va a mostrar
 * \param tam no hacia falta pasarla pero lo pase igual aparentemente
 * \return es void no retorna nada
 *
 */

void mostrarMarca(eMarca unaMarca, int tam)
{
    printf(" %d   %s \n",unaMarca.id,unaMarca.descripcion);
}
