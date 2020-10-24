

#ifndef MARCAS_H_INCLUDED
#define MARCAS_H_INCLUDED

typedef struct //marca
{
    int id;
    char descripcion[20];
}eMarca;


#endif // MARCAS_H_INCLUDED


int mostrarMarcas(eMarca movil[], int tam);
void mostrarMarca(eMarca unaMarca, int tam);
int validarMarcaID(eMarca marca[], int tam, int id);
