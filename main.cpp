#include <iostream>
#include "canion_1.h"
#define G 9.81
#define pi 3.141617

using namespace std;

void generar_Disparo_Ofensivo(canion_1 Do,canion_1 Dd,float d);
void generar_Disparo_Defensivo(canion_1 Do,canion_1 Dd);
void generar_Disparo_Defensivo3(canion_1 Do,canion_1 Dd,int angleo,int Vo0);

void ImprimirResultados(int angle,int V0o,float x,float y,float t);

void imprimir(canion_1 Do,canion_1 Dd);

int main()
{
    float distancia,PXo0,PYo0,PYd0;
    int sel;
    cout << "      MENU" << endl;
    cout << "1. Generar 3 disparos ofensivos" << endl;
    cout << "2. Generar 3 disparos defensivos" << endl;
//    cout << "3. Impedir que el canion defensivo sea destruido" << endl;
//    cout << "4. Impedir que los caniones ofensivo y defensivo sean destruidos" << endl;
//    cout << "5. Generar 3 disparos que neutralicen el ataque defensivo y generar un ataque ofensivo" << endl << endl;
    cout << "Ingrese una opcion (1-5): ";
    cin >> sel; cout << endl;
    while (true) {
        switch (sel) {
        case 1:
        {
            cout<<"Ingrese la posicion en x del canion ofensivo: ";
            cin>>PXo0;
            cout<<"Ingrese la posicion en y del canion ofensivo: ";
            cin>>PYo0;
            cout<<"Ingrese la distancia del canion ofensivo con respecto al defensivo: ";
            cin>>distancia;
            cout<<"Ingrese la posicion en y del canion defensivo: ";
            cin>>PYd0;

            canion_1 Do(PXo0,PYo0,distancia*0.05),Dd(distancia+Do.getXo(),PYd0,distancia*0.025);
            generar_Disparo_Ofensivo(Do,Dd,distancia);
        }
        break;
        case 2:
        {
            cout<<"Ingrese la posicion en x del canion ofensivo: ";
            cin>>PXo0;
            cout<<"Ingrese la posicion en y del canion ofensivo: ";
            cin>>PYo0;
            cout<<"Ingrese la distancia del canion ofensivo con respecto al defensivo: ";
            cin>>distancia;
            cout<<"Ingrese la posicion en y del canion defensivo: ";
            cin>>PYd0;

            canion_1 Do(PXo0,PYo0,distancia*0.05),Dd(distancia+Do.getXo(),PYd0,distancia*0.025);
            generar_Disparo_Defensivo(Do,Dd);
        }
        break;
        case 3:
        {

        }
        case 4:
        {
            canion_1 Do(PXo0,PYo0,distancia*0.05),Dd(distancia+Do.getXo(),PYd0,distancia*0.025);
            generar_Disparo_Defensivo3(Do,Dd,31,85);
        }
        default:
            cout << "Debe ingresar un valor correcto." << endl;
        }
    }
    return 0;
}

void generar_Disparo_Ofensivo(canion_1 Do,canion_1 Dd,float d)
{
    cout << "Calculando...";
    float x,y;
    float V0x,V0y;
    int ban=0;
    for(float Vo=d/2;;Vo+=0.5)
    {
        for(float angle=0;angle<90;angle+=0.5)
        {
            V0x = Vo*cos(angle*pi/180);
            V0y = Vo*sin(angle*pi/180);
            y=0;
            x=0;
            for(float t=0;t<2;t=t+0.5)
            {
                y=Do.getYo()+V0y*t-(0.5*G*t*t);
                x=Do.getXo()+V0x*t;
                ImprimirResultados(angle,Vo,x,y,t);
                if(sqrt(pow((Dd.getXo() - x),2)+pow((Dd.getYo() - y),2)) <= Do.getRad())
                {
                    cout << "Este si es ohhhhhhhhhh" << endl;
                    ImprimirResultados(angle,Vo,x,y,t);
                    ban += 1;
                    Vo += 1;
                    break;
                }
                if(y<0)
                {
                    break;
                }
            }
            if(ban==3)
            {
                break;
            }
        }
        if(ban==3)
        {
            break;
        }
    }
    if(ban != 3){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}

void generar_Disparo_Defensivo(canion_1 Do,canion_1 Dd)
{
    int ban=0;
    float x,y;
    float Vxd,Vyd;
    for(float Vdo=0;;Vdo=Vdo+0.5)
    {
        for(float angle=0;angle<90;angle=angle+0.5)
        {
            Vxd = Vdo*cos((angle+90)*pi/180);
            Vyd = Vdo*sin((angle+90)*pi/180);
            x = 0.0;
            y = 0.0;
            for(float t=0; ;t=t+0.5)
            {
                x = Dd.getXo()+Vxd*t;
                y = Dd.getYo()+Vyd*t-(0.5*G*t*t);
                if(sqrt(pow((Do.getXo()-x),2)+pow((Do.getYo()-y),2))<Dd.getRad())
                {
                    //if(y<0)y=0;
                    ImprimirResultados(angle,Vdo,x,y,t);
                    ban += 1;
                    Vdo += 50;
                    break;
                }
                if(y<0)
                {
                    break;
                }
            }
            if(ban==3) break;

        }
        if(ban==3) break;
    }
    if(ban!=3){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}

void generar_Disparo_Defensivo3(canion_1 Do,canion_1 Dd,int angleo,int Vo0)
{
    int flag = 0;
    bool flag2 = 0;
    float x,y,x2,y2;
    float aux,auy;
    float Vxod,Vyod, Vxoo,Vyoo;
    Vxoo = Vo0*cos((angleo)*pi/180);
    Vyoo = Vo0*sin((angleo)*pi/180);
    for(float Vod = 0 ; ; Vod += 5)
    {
        for(float angled = 0; angled < 90; angled++)
        {
            Vxod = Vod*cos((angled+90)*pi/180);
            Vyod = Vod*sin((angled+90)*pi/180);
            x = 0.0;
            y = 0.0;
            x2 = 0.0;
            y2 = 0.0;
            for(float t = 0; ; t++)
            {
                x2 = Do.getXo()+Vxoo*(t+2);
                y2 = Do.getYo() + Vyoo*(t+2) -(0.5*G*(t+2)*(t+2));
                x = Dd.getXo()+Vxod*t;
                y = Dd.getYo() + Vyod*t -(0.5*G*t*t);
                for(int t2 = t; ;t2++)
                {
                    aux = Dd.getXo()+Vxod*t2;
                    auy = Dd.getYo() +Vyod*t2 -(0.5*G*t2*t2);
                    if(sqrt(pow((Do.getXo() - aux),2)+pow((Do.getYo() - auy),2)) < Dd.getRad())
                    {
                        flag2 = 1;
                        break;
                    }
                    if(auy < 0){
                        break;
                    }
                }
                if(flag2)
                {
                    flag2 = 0;
                    break;
                }
                if(sqrt(pow((Dd.getXo() - x2),2)+pow((Dd.getYo() - y2),2)) < Do.getRad())
                {
                    break;
                }
                if(sqrt(pow((x2 - x),2)+pow((y2 - y),2)) < Dd.getRad())
                {
                    if(y<0) y = 0;
                    ImprimirResultados(angleo,Vo0,x2,y2,t+2);
                    cout << "_________________________________"<<endl;
                    ImprimirResultados(angled, Vod, x, y, t);
                    flag += 1;
                    Vod += 50;
                    break;
                }
                if(y < 0)
                {
                    break;
                }
            }
            if(flag == 3) break;

        }
        if(flag == 3) break;
    }
    if(flag != 3){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}

void ImprimirResultados(int angle,int V0o,float x,float y,float t)
{
    cout << "Impacto con un angulo de " << angle << " grados" << endl;
    cout << "Impacto con velocidad incial " << V0o << endl;
    cout << "Impacto con posicion x: " << x << endl;
    cout << "Impacto con posicion y: " << y << endl;
    cout << "Con tiempo: " << t << endl;
    cout << endl;
}
