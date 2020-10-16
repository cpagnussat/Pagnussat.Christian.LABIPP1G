#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "notebooks.h"
#include "marcas.h"
#include "tipos.h"
#include "serviciosTrabajosNote.h"


#define TAM 4


int main()
{
    char seguir = 'n';
    int flagAlta = 0;
    int rtaModif;
    int rtaBaja;

    eTrabajo trabajo[TAM];
    eNotebook note[TAM];
    eMarca datosMarca [4]= {{1000,"Compaq"},{1001,"Asus"},{1002,"Acer"},{1003,"HP"}};
    eTipo datosTipo [4]= { {5000,"Gamer"}, {5001,"Disenio"}, {5002,"Ultrabook"}, {5003,"Normalita"}};
    eServicio datosServicio [4] = { {20000, "Bateria", 250},{20001, "Antivirus", 300},{20002, "Actualizacion", 400},{20003, "Fuente", 600}};

    int proximoIdNote=3000;
    int proximoIdTrabajo=9000;

    inicializarNotebooks(note, TAM);
    inicializarTrabajos(trabajo,TAM);
    do
    {
        system("cls");
        switch(menuOpciones())
        {
        case 'a': // alta notebook
            if(altaNotebook(datosTipo, datosMarca, note, TAM, proximoIdNote) == 0)
            {
                proximoIdNote++;
                flagAlta++;
                printf("\nNotebook dada de alta.\n\n");
            }
            else
            {
                printf("\nProblema para realizar el alta...\n\n");
            }
            break;
        case 'b': // modificar notebook
            if(flagAlta == 0 )
            {
                printf("\nPrimero debe realizar el alta de alguna notebook...\n\n");
            }
            else
            {
                rtaModif =  modificarNotebook(note,datosTipo,datosMarca,TAM);

                if(rtaModif == 0)
                {
                    printf("\nSe ha modificado correctamente la notebook... \n");
                }
                else if(rtaModif == 2)
                {
                    printf("\nModificacion cancelada por el usuario...\n");
                }
                else
                {
                    printf("\nHa ocurrido un error al modificar la notebook...\n");
                }
            }
            break;

        case 'c': // baja notebook
             if( flagAlta== 0 )
            {
                printf("\nPrimero debe realizar el alta de alguna notebook...\n\n");
            }
            else
            {
                rtaBaja = bajaNotebook(note, TAM,datosTipo,datosMarca,TAM);

                if (rtaBaja == 0)
                {
                    printf("\nBaja exitosa\n\n");
                    printf("\nLa siguiente es la lista actualizada de notebooks...\n\n");

                    mostrarNotebooks(note, TAM, datosTipo, datosMarca, TAM);
                    system("pause");

                }
                else if(rtaBaja == 2)
                {
                    printf("La baja se ha cancelado por el usuario\n\n");
                    mostrarNotebooks(note, TAM, datosTipo, datosMarca, TAM);
                    system("pause");

                }
                else
                {
                    printf(" Se ha producido un error en la baja...\n");
                }

                }
            break;

        case 'd': // listar notebooks
            if(flagAlta == 0 )
            {
                printf("\nPrimero debe realizar el alta de alguna Notebook...\n\n");
            }
            else
            {
                ordenarNotebooksPrecio(note,TAM);
                mostrarNotebooks(note,TAM, datosTipo,datosMarca, TAM);
            }
            break;

        case 'e': // listar marcas
            mostrarMarcas(datosMarca,TAM);
            break;
        case 'f': // listar tipos
            mostrarTipos(datosTipo,TAM);
            break;
        case 'g': // listar servicios
            mostrarServicios(datosServicio,TAM);
            break;
        case 'h': // alta trabajo
            if(flagAlta == 0 )
            {
                printf("\nPrimero debe realizar el alta de alguna notebook...\n\n");
            }
            else
            {
                if(altaTrabajo(note, TAM, TAM, trabajo, datosServicio, datosTipo, datosMarca, proximoIdTrabajo) == 0)
                {
                    proximoIdTrabajo++;
                    printf("\nTrabajo dado de alta.\n\n");
                }
                else
                {
                    printf("\nProblema para realizar el alta...\n\n");
                }
            }
            break;
        case 'i': // listar trabajos
            mostrarTrabajos(trabajo,datosServicio,TAM);
            break;
        case 'j':
            printf("Confirma salida? Ingrese s/n: ");
            fflush(stdin);
            scanf("%c", &seguir);
            seguir = tolower(seguir);
            break;
        default:
            printf("\nOpcion ingresada incorrecta, vuelva a intentar.\n");
            system("pause");
            break;
        }
        system("pause");
    }
    while( seguir == 'n');
    return 0;
}


