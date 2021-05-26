#include "fecha.h"
#include "moto.h"
#include "servicio.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED


typedef struct
{
    int id;
    int idMoto;
    int idServicio;
    eFecha fecha;
    int isEmpty;


}eTrabajo;

#endif // TRABAJO_H_INCLUDED


void inicializarT(eTrabajo vec[], int tam);

int buscarLibreTrabajo(eTrabajo trabajo[], int tamT);

int altaTrabajo(int idx,eTrabajo vecT[],int tamTra,eMoto motos[],int tamM,eTipo tipos[],int tamT,eServicio vecS[],int tamS,eColor colores[],int tamC);

void mostrarTrabajos(eTrabajo trabajos[],int tamT,eMoto motos[],int tamM, eServicio servicios[],int tamS);

void mostrarTrabajo(eTrabajo trabajo, eMoto moto,eServicio servicios[],int tamS);
