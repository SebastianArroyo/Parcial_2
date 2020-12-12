#include <iostream>
#include "canion_1.h"

using namespace std;

void generar_Disparo_Ofensivo(canion_1 Do,canion_1 Dd);

int main()
{
    float distancia,PXo0,PYo0,PYd0;
    cout<<"Ingrese la posicion en x del canion ofensivo: ";
    cin>>PXo0;
    cout<<"Ingrese la posicion en y del canion ofensivo: ";
    cin>>PYo0;
    cout<<"Ingrese la distancia del canion ofensivo con respecto al defensivo: ";
    cin>>distancia;
    cout<<"Ingrese la posicion en y del canion ofensivo: ";
    cin>>PYd0;

    canion_1 Do(PXo0,PYo0,distancia*0.05),Dd(distancia,PYd0,distancia*0.025);

    generar_Disparo_Ofensivo(Do,Dd);

    return 0;
}

void generar_Disparo_Ofensivo(canion_1 Do,canion_1 Dd)
{



}
