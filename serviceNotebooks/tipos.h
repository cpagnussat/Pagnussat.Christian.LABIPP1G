#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED


typedef struct //tipo
{
    int id;
    char descripcion[20];
}eTipo;

#endif // TIPOS_H_INCLUDED


int mostrarTipos(eTipo tipo[], int tam);
void mostrarTipo(eTipo unTipo, int tam);
int validarTipoID(eTipo tipo[], int tam, int id);
