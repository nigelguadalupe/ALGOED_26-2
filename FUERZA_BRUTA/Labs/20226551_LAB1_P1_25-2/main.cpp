#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

#define CANT_CONTROLES 8
#include "Controles.h"

void crearCromosoma(int control,int*cromosoma,int cantControles) {

    for (int i= 0;i<cantControles;i++) {
        cromosoma[i] = control%2;
        control /= 2;
    }
}

void imprimirCromosoma(int*cromosoma,int cantControles,int costosTotales,int beneficiosTotales,int falsosTotales) {

    cout << "Recursos: {";
    for (int i=0;i<cantControles;i++) {
        if (cromosoma[i] == 1) {
            cout << i+1<<" ";
        }
    }
    cout<<"},Costo total:"<<costosTotales<<", Beneficio:"<<beneficiosTotales<<", Falsos Negativos: "<<falsosTotales<<endl;
}

void llenarCromosoma(int*cromosoma,int cantControles,int&costosTotales,int&beneficiosTotales,int&falsosTotales,Controles*controles) {

    for (int i=0;i<cantControles;i++) {
        if (cromosoma[i] == 1) {
            costosTotales += controles[i].costo;
            beneficiosTotales += controles[i].beneficio;
            falsosTotales += controles[i].falsosNegativos;
        }
    }
}
//P, B y F seran los maximos

void crearTodosLosCromosomas(int cantControles,Controles *controlesSeguridad,int P,int B,int F) {



    int numCombinaciones = pow(2,cantControles) - 1;
    for (int control = 0; control <= numCombinaciones; control++) {


        int costosTotales = 0, beneficiosTotales = 0, falsosTotales = 0;

        int cromosoma[CANT_CONTROLES]{};

        //Creamos el cromosoma para los totales
        crearCromosoma(control,cromosoma,cantControles);

        //Llenar totales
        llenarCromosoma(cromosoma,cantControles,costosTotales,beneficiosTotales,
            falsosTotales,controlesSeguridad);

        if (costosTotales <= P and beneficiosTotales >= B and falsosTotales <= F) {

            imprimirCromosoma(cromosoma,cantControles,costosTotales,beneficiosTotales,
                falsosTotales);

        }
    }
}

int main() {

    int P,B,F;

    struct Controles controlesSeguridad[CANT_CONTROLES] {
        {1,35000,80,1},
        {2,24000,60,3},
        {3,30000,70,2},
        {4,27000,48,1},
        {5,10000,20,1},
        {6,7000,35,2},
        {7,6000,10,1},
        {8,40000,40,3}
    };

    cin >> P >> B >> F;

    cout <<"P="<<P;
    cout <<" B="<<B;
    cout <<" F="<<F;
    cout<<endl;

    crearTodosLosCromosomas(CANT_CONTROLES,controlesSeguridad,P,B,F);

    return 0;
}
