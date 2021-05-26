#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED



#endif // INFORMES_H_INCLUDED



int menuInformes();

void informar(eMoto motos[],int tamM,eColor colores[],int tamC,eTipo tipos[],int tamT);

void mostrarMotosPorColorSeleccionado(eMoto motos[],int tamM,eTipo tipos[],int tamT,eColor colores[],int tamC);

void mostrarMotosPorTipoSeleccionado(eMoto motos[],int tamM,eTipo tipos[],int tamT,eColor colores[],int tamC);

void informarMotoMayorCilindrada(eMoto motos[],int tamM,eTipo tipos[],int tamT,eColor colores[],int tamC);


int listarMotosPorTipos(eMoto motos[],int tamM,eTipo tipos[],int tamT,eColor colores[],int tamC);


void InformarCantidadMotosColoryTipo(eMoto motos[],int tamM,eTipo tipos[],int tamT, eColor colores[],int tamC);


