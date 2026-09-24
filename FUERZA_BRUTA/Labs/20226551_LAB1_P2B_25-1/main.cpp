#include <iostream>
#include <cmath>

using namespace std;

#include "Recurso.h"

#define CANT_MAX 10

void imprimirCromosoma(int*cromosoma,int cantRecursos,int costosTotales,int nivelesTotales) {

    cout << " Recursos: ";
    for (int i=0;i<cantRecursos;i++) {

        if (cromosoma[i] == 1) {
            cout <<"R"<< i + 1<<" ";
        }

    }
    cout <<"| Costo: "<< costosTotales<<" miles";
    cout <<"| Nivel de Seguridad: "<< nivelesTotales<<endl;
}

void llenarTotales(int*cromosoma,int cantRecursos,Recurso*recursosSeguridad,
    int&costosTotales,int&nivelesTotales) {

    //Analizamos primero si un recurso depende de otro o no
    for (int i=0;i<cantRecursos;i++) {
        if (cromosoma[i] == 1) {

            costosTotales+=recursosSeguridad[i].costo;
            nivelesTotales+=recursosSeguridad[i].nivelSeguridad;

        }
    }
}

void crearCromosoma(int*cromosoma,int valor,int cantRecursos) {

    for (int i=0;i<cantRecursos;i++) {
        cromosoma[i] = valor%2;
        valor /= 2;
        // cout << cromosoma[i]<< " ";
    }
    // cout << endl;
}

bool dependenciasCumplidas(int*cromosoma,int i,Recurso *recursosSeguridad,int cantRecursos) {

    for (int k=0;k<3;k++) {
        int dependencia = recursosSeguridad[i].recursoImplementado[k];
        if (dependencia!=-1) {
            int indiceDependencia = dependencia - 1;
            if (cromosoma[indiceDependencia] != 1) {
                return false;
            }
        }
    }
    return true;
}

bool combinacionValida(int*cromosoma, int cantRecursos, Recurso *recursosSeguridad) {
    for (int i=0;i<cantRecursos;i++) {
        if (cromosoma[i] == 1) {
            if (not dependenciasCumplidas(cromosoma,i,recursosSeguridad,cantRecursos)) {
                return false;
            }
        }
    }
    return true;
}

void explorarCombinaciones(Recurso*recursosSeguridad,int numCombinaciones,
    int cantRecursos,int presupuesto,int nivelSeguridad) {

    bool seEncontro = false;

    cout << "Combinaciones validas (Costo entre "<<presupuesto*0.80<<" y "<<presupuesto;
    cout<< "miles y Nivel de seguridad >= "<< nivelSeguridad<<"):"<<endl;

    for (int valor = 0;valor<=numCombinaciones;valor++) {
        int costosTotales = 0;
        int nivelesTotales = 0;
        int cromosoma[CANT_MAX]{};
        crearCromosoma(cromosoma,valor,cantRecursos);

        if (combinacionValida(cromosoma, cantRecursos, recursosSeguridad)) {
            llenarTotales(cromosoma,cantRecursos,recursosSeguridad,costosTotales,nivelesTotales);
            if (costosTotales <= presupuesto and costosTotales >= presupuesto*0.8 and nivelesTotales >= nivelSeguridad) {
                cout << "Combinacion "<<valor<<":";
                imprimirCromosoma(cromosoma,cantRecursos,costosTotales,nivelesTotales);

                seEncontro = true;
            }
        }
    }

    if (not seEncontro) {
        cout << "No se encontraron combinaciones que cumplan con lo solicitado."<<endl;
    }
}
int main() {

    Recurso recursosSeguridad[CANT_MAX] {
        {50,{-1,-1,-1},120},
        {40,{-1,-1,-1},110},
        {80,{-1,-1,-1},140},
        {70,{1,-1,-1},130},
        {85,{1,-1,-1},160},
        {140,{1,2,-1},250},
        {55,{2,-1,-1},100},
        {130,{2,3,-1},240},
        {30,{-1,-1,-1},90},
        {150,{1,2,5},300}
    };

    int numCombinaciones = pow(2,CANT_MAX)-1;
    int presupuesto, nivelSeguridad;
    cout << "Ingrese el presupuesto (en miles de soles): ";
    cin >> presupuesto;

    cout << "Ingrese el nivel de seguridad minimo requerido: ";
    cin >> nivelSeguridad;

    explorarCombinaciones(recursosSeguridad,numCombinaciones,CANT_MAX,presupuesto,nivelSeguridad);

    return 0;
}
