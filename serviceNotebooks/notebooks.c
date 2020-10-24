#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "notebooks.h"
#include "marcas.h"
#include "tipos.h"
#include "utn.h"


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
    printf("j- MOSTRAR NOTEBOOKS POR TIPO\n");
    printf("k- MOSTRAR NOTEBOOKS POR MARCA\n");
    printf("l- INFORMAR NOTEBOOKS MAS BARATAS\n");
    printf("m- MOSTRAR NOTEBOOKS SEPARADAS POR MARCA\n");
    printf("n- NOTEBOOKS DE TIPO Y DE MARCA\n");
    printf("o- MARCA MAS ELEGIDA\n");
    printf("p- TRABAJOS REALIZADOS A UNA SOLA NOTEBOOK\n");
    printf("q- SUMA DE LOS IMPORTES DE LOS SERVICES\n");
    printf("r- MOSTRAR NOTEBOOKS POR SERVICIO\n");
    printf("s- MOSTRAR SERVICIOS POR FECHA \n");

    printf("z- Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());
    return opcion;
}

/** \brief settea el valor isEmpty del array de notebooks en 1 para indicar que estan las posiciones vacias
 *
 * \param eNotebook note[] array a inicializar
 * \param int tam el tamaño del array
 * \return retorna 1 si hubo algun error o 0 si pudo completarse correctamente
 *
 */

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

/** \brief devuelve el valor correspondiente al indice del array ingresado que se encuentra libre para escribir evaluando el valor isEmpty para ello
 *
 * \param eNotebook note[] array a recorrer para obtener la posicion libre
 * \param int tam tamaño del array
 * \return devuelve el indice libre para escribir en el
 *
 */

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


/** \brief busca por ID una notebook dentro del array ingresado
 *
 * \param eNotebook note[] array en el cual se buscara la coincidencia de ID
 * \param int tam tamaño del array
 * \param int id ID con el cual se comparara el valor .id de cada elemento en el array
 * \return devuelve la posicion en el array donde esta la coincidencia, de haberla
 *
 */

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

/** \brief aca parace que flashee durante el parcial e hice dos funciones iguales con distinto nombre
 *  no la voy a comentar porque seguro la utilice en algun lado y no quiero romper el programa y tampoco tengo tiempo para arreglarlo ahora
 * \param
 * \param
 * \return
 *
 */

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



/** \brief muestra e imprime el contenido del arrray ingresado haciendo uso de la funcion mostrarNotebook
 *
 * \param notes tipos marcas son 3 estructuras las cuales se van a imprimir sus arrays correspondientes en pantalla
 * \param tam y tamTM son los tamaños de las estructuras ingresadas
 * \return retorna 1 si hubo algun error y 0 si pudo completar la funcion correctamente
 *
 */

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

/** \brief muestra en pantalla la informacion contenida en estas estructuras y sus arrays
 *
 * \param unaNote tipos y marcas son la informacion que le ingreso para poder mostrar en pantalla
 * \param tam es el tamaño de los array
 * \return retorna nada
 *
 */

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


/** \brief da de alta un elemento de la estructura eNotebook
 *
 * \param tipos marcas y note son los 3 tipos de elementos que se utilizan en el proceso de dar de alta una notebook
 * \param id es el id que se genera automaticamente y le corresponde a la notebook dada de alta
 * \return devuelve 1 si hubo error y 0 si se pudo dar de alta con exito
 *
 */


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
            while(validarMarcaID(marcas,tam,nuevaNotebook.idMarca) == 1 )
            {
                printf("\nError, ingrese el ID de marca nuevamente: ");
                scanf("%d",&nuevaNotebook.idMarca);
            }


            printf("\nIngrese modelo(###): ");
            scanf("%d", &nuevaNotebook.modelo);

            system("cls");
            printf("***  ALTA DE AUTO  ***\n");
            mostrarTipos(tipos,tam);
            printf("\nIngrese ID de tipo: ");
            scanf("%d", &nuevaNotebook.idTipo);
            while(validarTipoID(tipos,tam,nuevaNotebook.idTipo) == 1 )
            {
                printf("\nError, ingrese el ID del tipo nuevamente: ");
                scanf("%d",&nuevaNotebook.idTipo);
            }
            printf("\nIngrese precio(###): ");
            fflush(stdin);
            scanf("%d", &nuevaNotebook.precio);
            note[indice] = nuevaNotebook;

            error = 0;
        }
    }
    return error;
}


/** \brief baja logica de un elemtno en la estructura eNotebook setteando el valor de isEmpty en 1 nuevamente
 *
 * \param note[] elemento a dar de baja
 * \param tam tamaño del array
 * \return devuelve 1 si hubo algun error, 0 si se pudo completar y 2 si fue cancelada manualmente la accion de la baja
 *
 */


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

/** \brief permite modificar mediante el ingreso de ID algun valor de la estructura eNotebook ingresada
 *
 * \param note tipos y marca son las 3 estructuras que se le pasan a la funcion para poder visualizar lo que se quiere modificar
 * \param tam es el tamaño de los array
 * \return retorna 1 si hubo algun error, 0 si se pudo completar y 2 si se cancelo la accion
 *
 */


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

/** \brief ordena los elementos de la estructura eNotebook por orden descendente de precio mediante burbujeo
 *
 * \param note es el array a ordenar
 * \param tam tamaño del array
 * \return devuelve 1 si hubo algun error, 0 si pudo completar
 *
 */


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

/** \brief muestra el listado de los tipos, pide uno y luego imprime las notebooks en pantalla que tengan ese tipo
 *
 * \param note[] es el array de notebooks donde se van a buscar las que tengan el tipo ingresado
 * \param tipo[] es el array de tipos del cual se va a seleccionar el que se busca
 * \return  retorna 1 si hubo algun error o 0 si salio todo bien
 *
 */


int mostrarNotebookPorTipo(eTipo tipos[], eMarca marcas[], eNotebook note[],int tam)
{
    int error=1;
    int indiceTipo;

    if(note!=NULL && tam > 0)
    {
        system("cls");
        printf("***  MOSTRAR NOTEBOOKS POR TIPO  ***\n");

        mostrarTipos(tipos,tam);
        printf("\nIngrese ID de tipo: ");
        scanf("%d", &indiceTipo);
        while(validarTipoID(tipos,tam,indiceTipo) == 1 )
        {
            printf("\nError, ingrese el ID del tipo nuevamente: ");
            scanf("%d",&indiceTipo);
        }

        system("cls");
        printf("***  MOSTRAR NOTEBOOKS POR TIPO  ***\n");
        printf("\nA continuacion se muestran las notebooks del tipo: %d\n\n", indiceTipo);

        printf(" ID    Modelo   Precio    Tipo      Marca       \n");
        printf("------------------------------------------------\n\n");
        for( int i = 0 ; i < tam ; i++ )
		{
			if(note[i].idTipo == indiceTipo )
			{
			    mostrarNotebook(note[i],tipos,marcas,tam);
                error = 0;
			}
		}
    }

    return error;
}
/** \brief muestra las marcas y pide seleccionar una para luego imprimir en pantalla las notebooks en sistema que tengan esa marca
 *
 * \param note[] es el array de notebooks donde se van a buscar las que tengan el tipo ingresado
 * \param tipo[] es el array de tipos del cual se va a seleccionar el que se busca
 * \return  retorna 1 si hubo algun error o 0 si salio todo bien
 *
 */


int mostrarNotebookPorMarca(eTipo tipos[], eMarca marcas[], eNotebook note[],int tam)
{
    int error=1;
    int indiceMarca;

    if(note!=NULL && tam > 0)
    {
        system("cls");
        printf("***  MOSTRAR NOTEBOOKS POR MARCA  ***\n");

        mostrarMarcas(marcas,tam);
        printf("\nIngrese ID de la marca: ");
        scanf("%d", &indiceMarca);
        while(validarMarcaID(marcas,tam,indiceMarca) == 1 )
        {
            printf("\nError, ingrese el ID de la marca nuevamente: ");
            scanf("%d",&indiceMarca);
        }

        system("cls");
        printf("***  MOSTRAR NOTEBOOKS POR MARCA  ***\n");
        printf("\nA continuacion se muestran las notebooks de la marca con ID: %d\n\n", indiceMarca);

        printf(" ID    Modelo   Precio    Tipo      Marca       \n");
        printf("------------------------------------------------\n\n");
        for( int i = 0 ; i < tam ; i++ )
		{
			if(note[i].idMarca == indiceMarca )
			{
			    mostrarNotebook(note[i],tipos,marcas,tam);
                error = 0;
			}
		}
    }

    return error;
}

/** \brief muestra en pantalla la notebook cargada en sistema con el menor valor en su parametro .precio
 *
 * \param note[] es el array de notebooks donde se va a buscar la que tenga el parametro .precio mas bajo
 * \return  retorna 1 si hubo algun error o 0 si salio todo bien
 *
 */

int mostrarNotebookBarata(eNotebook note[], eTipo tipos[], eMarca marcas[], int tam)
{
    int error = 1;
    int indiceNoteBarata;
    int menorPrecio = 500;

    system("cls");
    printf("***     NOTEBOOK(s) MAS BARATAS     ***\n\n");
    if(note != NULL && tam > 0 )
    {
        for( int i = 0 ; i < tam ; i++ )
        {
            if(note[i].precio<menorPrecio)
            {
                indiceNoteBarata = i;
                menorPrecio = note[i].precio;

            }
        }
    error =0;

    printf("\nA continuacion se muestra la notebook mas barata, cuyo precio es: %d\n\n",note[indiceNoteBarata].precio);
    printf(" ID    Modelo   Precio    Tipo      Marca       \n");
    printf("------------------------------------------------\n\n");
    mostrarNotebook(note[indiceNoteBarata],tipos,marcas,tam);

    }
    return error;
}
/** \brief esta se hizo un poco extensa, seguro haya una forma mejor, pero ahora me sale asi nada mas
 *  imprime en pantalla 4 bloques, uno por cada marca y muestra las notebooks en sistema en su bloque correspondiente dependiendo de la marca
 * \param note[] es el array de notebooks donde se va a filtrar por marcas
 * \param
 * \return devuelve 1 si hubo algun error o 0 si salio todo bien
 *
 */

int mostrarNotebooksSeparadasPorMarca(eTipo tipos[], eMarca marcas[], eNotebook note[] ,int tam)
{
    int error = 1;
    int contador0 =0;
    int contador1 =0;
    int contador2 =0;
    int contador3 =0;

    system("cls");
    printf("***    NOTEBOOKS SEPARADAS POR MARCA    ***\n\n");

    if(note != NULL && tam > 0 )
    {
        for( int i = 0 ; i < tam ; i++ )
        {
            if( note[i].idMarca == 1000 )
            {
                contador0++;
            }
        }
        if(contador0 != 0)
        {
            printf("\n Notebooks Compaq: \n\n");

            printf(" ID    Modelo   Precio    Tipo      Marca       \n");
            printf("------------------------------------------------\n\n");
            for( int i = 0 ; i < tam ; i++ )
            {
                if( note[i].idMarca == 1000 )
                {
                    mostrarNotebook(note[i],tipos,marcas,tam);
                }
            }
        }
        else
        {
            printf("\nNo hay notebooks Compaq en sistema. \n\n");
        }

        for( int i = 0 ; i < tam ; i++ )
        {
            if( note[i].idMarca == 1001 )
            {
                contador1++;
            }
        }
        if(contador1!=0)
        {
            printf("\n Notebooks ASUS: \n\n");

            printf(" ID    Modelo   Precio    Tipo      Marca       \n");
            printf("------------------------------------------------\n\n");
            for( int i = 0 ; i < tam ; i++ )
            {
                if( note[i].idMarca == 1001 )
                {
                    mostrarNotebook(note[i],tipos,marcas,tam);
                }
            }
        }
        else
        {
            printf("\nNo hay notebooks ASUS en sistema. \n\n");
        }
        for( int i = 0 ; i < tam ; i++ )
        {
            if( note[i].idMarca == 1002 )
            {
                contador2++;
            }
        }
        if(contador2 != 0 )
        {
            for( int i = 0 ; i < tam ; i++ )
            {
                if( note[i].idMarca == 1002 )
                {
                    printf("\n Notebooks ACER: \n\n");

                    printf(" ID    Modelo   Precio    Tipo      Marca       \n");
                    printf("------------------------------------------------\n\n");
                    mostrarNotebook(note[i],tipos,marcas,tam);

                }
            }
        }
        else
        {
            printf("\nNo hay notebooks ACER en sistema. \n\n");
        }

        for( int i = 0 ; i < tam ; i++ )
        {
            if( note[i].idMarca == 1003 )
            {
                contador3++;
            }
        }
        if(contador3!=0)
        {
            for( int i = 0 ; i < tam ; i++ )
            {
                if( note[i].idMarca == 1003 )
                {
                    printf("\n Notebooks HP: \n\n");

                    printf(" ID    Modelo   Precio    Tipo      Marca       \n");
                    printf("------------------------------------------------\n\n");
                    mostrarNotebook(note[i],tipos,marcas,tam);

                }
            }
        }
        else
        {
            printf("\nNo hay notebooks HP en sistema. \n\n");
        }

    error = 0;

    }
    return error;
}


/** \brief muestra el menu de tipo y el de marca pidiendo los dos valores, luego muestra en pantalla la cantidad de coincidencias que haya con esos datos
 *
 * \param note[] es el array donde se van a buscar las coincidencias con los datos selecciondos
 * \param
 * \return devuelve 1 si hubo algun error o 0 si pudo completarse correctamente
 *
 */

int mostrarNotePorTipoyMarca(eTipo tipos[], eMarca marcas[], eNotebook note[] ,int tam)
{
    int indiceTipo;
    int indiceMarca;
    int error = 1;

    int contadorMarca = 0;
    int contadorTipo = 0;
    int contadorTipoyMarca = 0;

    system("cls");
    printf("****    NOTEBOOKS POR TIPO Y MARCA     **** \n\n");

    mostrarTipos(tipos,tam);
    printf("\nIngrese ID de tipo: ");
    scanf("%d", &indiceTipo);
    while(validarTipoID(tipos,tam,indiceTipo) == 1 )
    {
        printf("\nError, ingrese el ID del tipo nuevamente: ");
        scanf("%d",&indiceTipo);
    }

    for( int i = 0 ; i < tam ; i++ )
    {
        if(note[i].idTipo == indiceTipo )
        {
            contadorTipo++;
        }
    }


    system("cls");
    printf("****    NOTEBOOKS POR TIPO Y MARCA     **** \n\n");

    mostrarMarcas(marcas,tam);
    printf("\nIngrese ID de la marca: ");
    scanf("%d", &indiceMarca);
    while(validarMarcaID(marcas,tam,indiceMarca) == 1 )
    {
        printf("\nError, ingrese el ID de la marca nuevamente: ");
        scanf("%d",&indiceMarca);
    }

    for( int i = 0 ; i < tam ; i++ )
    {
        if(note[i].idMarca == indiceMarca )
        {
            contadorMarca++;
        }
    }
    for( int i = 0 ; i < tam ; i++ )
    {
        if(note[i].idMarca == indiceMarca && note[i].idTipo == indiceTipo)
        {
            contadorTipoyMarca++;
        }
    }

    if(contadorMarca != 0)
    {
        printf("\n\n Existen %d notebooks con la marca seleccionada. \n",contadorMarca);
    }
    else{
        printf("\n\n No existen notebooks con la marca seleccionada. \n");
    }
    if(contadorTipo != 0 )
    {
        printf("\n\n Existen %d notebooks con el tipo seleccionada. \n",contadorTipo);
    }
    else
    {
        printf("\n\n No existen notebooks con el tipo seleccionado. \n");
    }
    if(contadorTipoyMarca!=0)
    {
        printf("\n\n Existen %d notebooks con la marca y el tipo seleccionados. \n",contadorTipoyMarca);
    }
    else
    {
        printf("\n\n No existen notebooks con el tipo y la marca seleccionados. \n\n");
    }

    return error;
}


/** \brief muestra en una linea de texto la marca con la mayor cantidad de notebooks ingresadas en sistema
 *
 * \param note[] array que se va a recorrer buscando las coincidencias con las marcas
 * \param
 * \return devuelve 0 si se pudo ejecutar correctamente y 1 si hubo algun error
 *
 */

int mostrarMarcaMasElegida(eTipo tipos[], eMarca marcas[], eNotebook note[] ,int tam)
{
    int error = 1;
    int contador0 =0;
    int contador1 =0;
    int contador2 =0;
    int contador3 =0;


    printf("\n\n***    MARCAS MAS ELEGIDAS     ***\n\n");

    if(note != NULL && tam > 0 )
    {
        for( int i = 0 ; i < tam ; i++ )
        {
            if( note[i].idMarca == 1000 )
            {
                contador0++;
            }
            if( note[i].idMarca == 1001 )
            {
                contador1++;
            }
            if( note[i].idMarca == 1002 )
            {
                contador2++;
            }
            if( note[i].idMarca == 1003 )
            {
                contador3++;
            }
        }
        error = 0;
    }

    if(contador0>contador1 && contador0>contador2 && contador0>contador3)
    {
        printf("\nLa marca mas elegida por los clientes es Compaq, con %d notebooks en el service.\n\n",contador0);
    }
    else if(contador1>contador2 && contador1>contador3)
    {
        printf("\nLa marca mas elegida por los clientes es ASUS, con %d notebooks en el service.\n\n",contador1);
    }
    else if(contador2>contador3)
    {
        printf("\nLa marca mas elegida por los clientes es ACER, con %d notebooks en el service.\n\n",contador2);
    }
    else
    {
        printf("\nLa marca mas elegida por los clientes es HP, con %d notebooks en el service.\n\n",contador3);
    }

    return error;
}
