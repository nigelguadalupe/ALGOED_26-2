#include <iostream>
#include <cmath>

using namespace std;

#define CANT_TABLAS 6
#define CANT_DISCOS 3

void imprimirCromosoma(int*cromosoma,int velocidadOptima) {

    cout << "Velocidad minima de grupo: "<<velocidadOptima<< "IOPs"<<endl;

    for (int i = 0;i<CANT_DISCOS;i++) {
        cout << "Disco "<<i+1<<": ";

        for (int k = 0; k < CANT_TABLAS; k++) {
            if (cromosoma[k] == i) {
                cout << k + 1<< " ";
            }
        }
        cout << endl;
    }
}

int velocidadMinima(int*velocidadesResultantes) {
    //OJO AQUI
    int minimo = velocidadesResultantes[0];

    for (int k=0;k<CANT_DISCOS;k++) {
        if (velocidadesResultantes[k] < minimo) {
            minimo = velocidadesResultantes[k];
        }
    }
    return minimo;
}

void copiarArreglo(int cantidad, int*origen, int*destino) {

    for (int i=0;i<cantidad;i++) {
        destino[i] = origen[i];
    }
}
void crearCromosoma(int valor,int*cromosoma) {

    for (int i=0;i<CANT_TABLAS;i++) {
        cromosoma[i] = valor%CANT_DISCOS;
        valor = valor/CANT_DISCOS;
    }
}

bool calcularVelocidadesResultantes(int*cromosoma,int*tablas,int*discosOriginales,int*velocidadesResultantes) {

    copiarArreglo(CANT_DISCOS, discosOriginales, velocidadesResultantes);
    for (int i = 0;i < CANT_TABLAS;i++) {

        int disco = cromosoma[i];

        velocidadesResultantes[disco] -= tablas[i];

        if (velocidadesResultantes[disco] < 0) {
            return false;
        }
    }
    return true;
}

void buscarSolucionOptima(int*tablas,int*discos,int cantTablas,
    int cantDiscos) {

    int numCombinaciones = pow(cantDiscos,cantTablas) - 1;

    int mejorVelocidad = -1;
    int mejorCromosoma[CANT_TABLAS]{};

    for (int valor = 0;valor <= numCombinaciones;valor++) {

        int cromosoma[CANT_TABLAS]{};

        crearCromosoma(valor,cromosoma);

        int velocidadesResultantes[CANT_DISCOS]{};

        bool valida = calcularVelocidadesResultantes(cromosoma,tablas,discos,
            velocidadesResultantes);

        if (valida) {
            int velocidad = velocidadMinima(velocidadesResultantes);

            if (velocidad > mejorVelocidad) {
                mejorVelocidad = velocidad;
                copiarArreglo(CANT_TABLAS,cromosoma, mejorCromosoma);
            }
        }
    }

    imprimirCromosoma(mejorCromosoma,mejorVelocidad);
}
int main() {

    int tablas[CANT_TABLAS]{150,100,80,50,120,10};
    int discos[CANT_DISCOS]{250,200,200};

    buscarSolucionOptima(tablas,discos,CANT_TABLAS,CANT_DISCOS);


    return 0;
}
