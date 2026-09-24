#include <iostream>
#include <cmath>
using namespace std;

#define CANT_DIENTES 8
#define CANT_TIPOS 4
#define CANT_CITAS 3
#define CANT_ESTADOS 4

#include "Diente.h"
#include "TipoDiente.h"

void imprimirCromosoma(int*cromosoma,int mejorGanancia,Diente*dientes) {

    for (int i=1;i<=CANT_CITAS;i++) {
        for (int k=0;k<CANT_DIENTES;k++) {
            if (cromosoma[k] == i) {
                cout << "Cita: "<< i<< " Diente:"<< dientes[k].ubicacion<<endl;
            }
        }
    }
    cout << "La ganancia maxima es: "<<mejorGanancia<<endl;
}
bool respetarLimites(int*duracionActual,int*arrCitaDuracion) {

    for (int i=0;i<CANT_CITAS;i++) {
        if (duracionActual[i] > arrCitaDuracion[i]) {
            return false;
        }
    }
    return true;
}
void llenarTotales(int*cromosoma,Diente*dientes,TipoDiente*tipoDientes
    ,int&gananciaTotal,int*duracionActual) {

    for (int i=0;i<CANT_DIENTES;i++) {

        if (cromosoma[i]!=0) {
            int cita = cromosoma[i] - 1;

            int tipoDiente = dientes[i].tipo;

            TipoDiente info = tipoDientes[tipoDiente - 1];

            int duracion = info.duracion * dientes[i].cantidadCaries;

            int ganancia = info.ganancia * dientes[i].cantidadCaries;

            duracionActual[cita] += duracion;

            gananciaTotal += ganancia;

        }
    }

}

void crearCromosoma(int valor,int*cromosoma) {

    for (int i=0;i<CANT_DIENTES;i++) {
        cromosoma[i] = valor%CANT_ESTADOS; // aqui ya no es 2 pues puede ser NroCita 1, 2, 3 o Ninguno
        valor/=CANT_ESTADOS;
    }
}
void resolver(Diente*dientes,TipoDiente*tipoDientes,
    int*arrCitaDuracion) {

    int mejorGanancia = 0;



    int mejorCromosoma[CANT_DIENTES]{};

    int numCombinaciones = pow(CANT_ESTADOS,CANT_DIENTES)-1;

    for (int valor=0;valor<=numCombinaciones;valor++) {

        int gananciaTotal = 0;
        int cromosoma[CANT_DIENTES]{};
        int duracionActual[CANT_CITAS]{};

        crearCromosoma(valor,cromosoma);

        llenarTotales(cromosoma,dientes,tipoDientes,
            gananciaTotal,duracionActual);

        if (respetarLimites(duracionActual,arrCitaDuracion)) {
            if (gananciaTotal > mejorGanancia) {
                mejorGanancia = gananciaTotal;

                for (int i=0;i<CANT_DIENTES;i++) {
                    mejorCromosoma[i] = cromosoma[i];
                }
            }
        }
    }

    imprimirCromosoma(mejorCromosoma,mejorGanancia,dientes);
}
int main() {

    Diente dientes[CANT_DIENTES] {
        {1,1,1,3},
        {2,1,1,1},
        {3,1,2,0},
        {4,1,3,1},
        {5,1,3,2},
        {6,1,4,1},
        {7,1,4,2},
        {8,1,4,3}
    };

    TipoDiente tipoDientes[CANT_TIPOS] {
        {1,5,20},
        {2,7,30},
        {3,10,35},
        {4,12,42}
    };

    int arrCitaDuracion[CANT_CITAS]{60,45,50};

    resolver(dientes,tipoDientes,arrCitaDuracion);

    return 0;
}