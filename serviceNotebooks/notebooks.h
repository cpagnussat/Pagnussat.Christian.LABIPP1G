#include "marcas.h"
#include "tipos.h"

#ifndef NOTEBOOKS_H_INCLUDED
#define NOTEBOOKS_H_INCLUDED

typedef struct //fecha
{
    int dia;
    int mes;
    char anio;
}eFecha;


typedef struct //notebook
{
    int id;
    int modelo;
    int idMarca;
    int idTipo;
    int precio;
    int isEmpty;// 1 esta vacia 0 esta llena
}eNotebook;


#endif // NOTEBOOKS_H_INCLUDED

char menuOpciones();
int altaNotebook(eTipo tipos[], eMarca marcas[], eNotebook note[],int tam,int id);

int inicializarNotebooks(eNotebook note[], int tam);
int buscarLibre(eNotebook note[], int tam);
int buscarNotebooks(eNotebook note[], int tam, int id);
int mostrarNotebooks(eNotebook notes[], int tam, eTipo tipos[], eMarca marcas[], int tamTM);
void mostrarNotebook(eNotebook unaNote, eTipo tipos[], eMarca marcas[], int tam);
int bajaNotebook(eNotebook note[], int tam, eTipo tipos[], eMarca marcas[], int tamTC);
int buscarNotebookID(eNotebook note[], int tam, int id);
int modificarNotebook(eNotebook note[], eTipo tipos[], eMarca marca[], int tam);

int ordenarNotebooksPrecio(eNotebook note[], int tam);

