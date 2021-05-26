#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "moto.h"
#include "color.h"
#include "tipo.h"








int menuInformes()
{
    int opcion;

    system("cls");
    printf("1)Mostrar motos de color seleccionado\n");
    printf("2)Mostrar motos de tipo seleccionado\n");
    printf("3)Mostrar motos de mayor cilindrada\n");
    printf("4)Lista de motos separadas por tipo\n");
    printf("5)Elegir un color y un tipo y contar cuantas motos hay de ese color y ese tipo\n");
    printf("6)Mostrar colores mas elegidos\n");
    printf("7)Salir\n\n");

    printf("Ingrese opcion: ");
    scanf("%d",&opcion);




    return opcion;

}







void mostrarMotosPorColorSeleccionado(eMoto motos[],int tamM,eTipo tipos[],int tamT,eColor colores[],int tamC)
{

    int idColor;
    char nombreColor[20];

    system("cls");

    mostrarColores(colores,tamC);

    printf("Ingrese ID del color: ");
    scanf("%d",&idColor);

   while(idColor < 10000 || idColor > 10004)
   {
       printf("Error.Reingrese ID color: ");
       scanf("%d",&idColor);
   }


   cargarDescripcionColor(nombreColor,idColor,colores,tamC);

   printf("\n*******Motos de color %10s*****\n",nombreColor);

   for(int i=0; i < tamM ;i ++)
   {

       if(motos[i].isEmpty == 0 && motos[i].idColor == idColor)
       {
           mostrarMoto(motos[i],tipos,tamT,colores,tamC);
       }



   }




}



void mostrarMotosPorTipoSeleccionado(eMoto motos[],int tamM,eTipo tipos[],int tamT,eColor colores[],int tamC)
{


    int idTipo;
    char nombreTipo[20];


    system("cls");

    mostrarTipos(tipos,tamT);

    printf("Ingrese ID del tipo: ");
    scanf("%d",&idTipo);

   while(idTipo < 1000 || idTipo > 1003)
   {
       printf("Error.Reingrese ID del tipo: ");
       scanf("%d",&idTipo);

   }

   cargarDescripcionTipo(nombreTipo,idTipo,tipos,tamT);

   printf("\n*******Motos del tipo: %10s*******\n",nombreTipo);

for(int i=0; i < tamM ;i ++)
   {

       if(motos[i].isEmpty == 0 && motos[i].idTipo == idTipo)
       {
           mostrarMoto(motos[i],tipos,tamT,colores,tamC);
       }



   }







}








void informarMotoMayorCilindrada(eMoto motos[],int tamM,eTipo tipos[],int tamT,eColor colores[],int tamC)
{

system("cls");



int flag=0;
int mayorCilindrada;


for(int i = 0; i < tamM ; i++)
{

    if(flag== 0|| motos[i].isEmpty == 0)
    {

        if( motos[i].cilindrada > mayorCilindrada)
        {
            mayorCilindrada=motos[i].cilindrada;
            flag=1;

        }






    }




}

printf("La moto de mayor cilindrada es: \n\n");

printf(" ID  Tipo  Marca  Color  Cilindrada\n\n");
for(int i=0; i < tamM ; i++)
{

    if(motos[i].cilindrada == mayorCilindrada)
    {
        mostrarMoto(motos[i],tipos,tamT,colores,tamC);

    }




}

if(!flag)
{
    printf("No hay motos que lsitar\n\n");
}





}














int listarMotosPorTipos(eMoto motos[],int tamM,eTipo tipos[],int tamT,eColor colores[],int tamC)
{

    system("cls");


    int todoOk=0;
    int flag=0;

    for(int i = 0 ; i < tamT ; i++)
    {

        printf("\nMotos del tipo: %s \n",tipos[i].descripcion);
        printf("  ID   Tipo    Marca   Color   cilindrada\n\n");



        for(int j=0 ; j < tamM ; j++)
        {


            if(motos[j].isEmpty == 0 && motos[j].idTipo == tipos[i].id)
            {

                mostrarMoto(motos[j],tipos,tamT,colores,tamC);
                flag=1;


            }

        }


  if(!flag)
  {
      printf("No hay motos registradas de este tipo\n\n");
  }



        }






    return todoOk;
}







void InformarCantidadMotosColoryTipo(eMoto motos[],int tamM,eTipo tipos[],int tamT, eColor colores[],int tamC)
{

    int contador = 0;
    int idTipo;
    int idColor;


    system("cls");



    mostrarColores(colores,tamC);

    printf("Ingrese ID del color: ");
    scanf("%d",&idColor);

     while(idColor < 10000 || idColor > 10004)
   {
       printf("Error.Reingrese ID color: ");
       scanf("%d",&idColor);
   }


   mostrarTipos(tipos,tamT);

   printf("Ingrese ID del tipo: ");
   scanf("%d",&idTipo);

     while(idTipo < 1000 || idTipo > 1003)
   {
       printf("Error.Reingrese ID del tipo: ");
       scanf("%d",&idTipo);

   }


   for(int i=0; i < tamM ; i ++)
   {



       if(motos[i].isEmpty == 0   && motos[i].idColor == idColor && motos[i].idTipo == idTipo )
       {

           contador++;


       }




   }

printf("\n\n***Hay un total de %d motos de ese tipo y color***\n\n",contador);







}
















void informar(eMoto motos[],int tamM,eColor colores[],int tamC,eTipo tipos[],int tamT)
{

    char confirma= 'n';

    do
    {

        switch(menuInformes())
        {

        case 1:
            mostrarMotosPorColorSeleccionado(motos,tamM,tipos,tamT,colores,tamC);
            system("pause");
            break;

        case 2:
            mostrarMotosPorTipoSeleccionado(motos,tamM,tipos,tamT,colores,tamC);
            system("pause");
            break;

        case 3:
            informarMotoMayorCilindrada(motos,tamM,tipos,tamT,colores,tamC);
            system("pause");
            break;

        case 4:
            system("cls");
            listarMotosPorTipos(motos,tamM,tipos,tamT,colores,tamC);
            system("pause");
            break;


        case 5:
            InformarCantidadMotosColoryTipo(motos,tamM,tipos,tamT,colores,tamC);
            system("pause");
            break;



        case 6:
            //printf("Informar color mas elegido\n");
            system("pause");

            break;



        case 7:

            printf("Confirma salida? \n");
            fflush(stdin);
            scanf("%c",&confirma);
            break;










        }










    }while(confirma == 'n');

}








