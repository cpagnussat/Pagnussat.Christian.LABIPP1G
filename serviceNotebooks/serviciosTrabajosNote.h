#include "notebooks.h"

#ifndef SERVICIOSTRABAJOSNOTE_H_INCLUDED
#define SERVICIOSTRABAJOSNOTE_H_INCLUDED


typedef struct //servicio
{
    int id;
    char descripcion[20];
    int precio;
}eServicio;

typedef struct //trabajo
{
    int id;
    int idNotebook;
    int idServicio;
    eFecha fecha;
    int isEmpty;// 1 esta vacia 0 esta llena
}eTrabajo;

#endif // SERVICIOSTRABAJOSNOTE_H_INCLUDED

void mostrarServicio(eServicio unServicio, int tam);
int mostrarServicios(eServicio servicios[], int tam);


int buscarLibreTrabajo(eTrabajo trabajo[], int tam);
void mostrarTrabajo(eTrabajo unTrabajo, eServicio unServicio[], int tam);
int mostrarTrabajos(eTrabajo trabajos[], eServicio servicios[], int tam);
int inicializarTrabajos(eTrabajo trabajo[], int tam);
int validarServicioID(eServicio servicio[], int tam, int id);


int altaTrabajo(eNotebook note[], int tam, int tamServicios, eTrabajo trabajo[], eServicio servicios[], eTipo tipos[], eMarca marcas[], int idTrabajo);


//informes

int trabajosPorNotebook(eTipo tipos[], eMarca marcas[], eNotebook note[] , eTrabajo trabajo[], eServicio servicios[] ,int tam);
int precioPorNotebook(eTipo tipos[], eMarca marcas[], eNotebook note[] , eTrabajo trabajo[], eServicio servicios[] ,int tam);
int mostrarNotebooksPorServicio(eTipo tipos[], eMarca marcas[], eNotebook note[] , eTrabajo trabajo[], eServicio servicios[] ,int tam);
int mostrarServiciosPorFecha(eTipo tipos[], eMarca marcas[], eNotebook note[] , eTrabajo trabajo[], eServicio servicios[] ,int tam);
