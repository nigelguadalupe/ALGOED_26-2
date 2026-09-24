#include <iostream>

using namespace std;

#define N 10

int verificarAncestral(int candidato,int i,int aporte[N][N]) {

    if (i == N) {
        return 1; // Se revisaron todos, cumple ambas condiciones
    }

    //Candidato no le aporta a i, falla la primera condicion

    if (aporte[i][candidato] == 0) {
        return 0;
    }

    //Candidato recibio de i (sin ser el mismo), falla la segunda condicion

    if (i != candidato and aporte[candidato][i] != 0) {
        return 0;
    }

    return verificarAncestral(candidato,i+1,aporte);
}

int buscarCandidato(int posicion,int receptor,int aporte[N][N]) {

    if (receptor == N) {
        return posicion;
    }

    if (aporte[receptor][posicion] > 0) {
        return buscarCandidato(posicion,receptor+1,aporte);
    }else {
        return buscarCandidato(receptor,receptor+1,aporte);
    }
}

int main() {

    //Si se encuentra el canario ancestral
    //se debe mostrar, sino mostrar -1.

    int aporte[N][N] {
        {100,0,50,40,30,20,30,0,80,0},
        {50,100,0,40,30,20,20,0,10,25},
        {80,30,100,40,30,0,30,20,10,60},
        {50,0,0,100,30,0,50,30,30,90},
        {50,10,10,10,100,0,10,50,10,50},
        {20,0,0,0,0,100,90,20,40,20},
        {0,0,0,0,0,0,100,0,0,0},
        {0,0,0,0,0,0,50,100,50,20},
        {20,0,0,40,0,0,90,0,100,10},
        {0,10,0,0,0,0,10,0,60,100}
    };

    int posicion = buscarCandidato(0,1,aporte);

    // int cantidad1=0;
    // int cantidad2=0;
    //
    // for (int i=0;i<N;i++) {
    //
    //     if (aporte[i][posicion]!=0) {
    //         cantidad1++;
    //     }
    //     if (aporte[posicion][i]!=0) {
    //         cantidad2++;
    //     }
    // }
    //int esAncestral = verificarAncestral(posicion,0,aporte);

    if (verificarAncestral(posicion,0,aporte)) {
        cout << "Para la matriz del ejemplo la solucion es el canario "<<posicion<<endl;
    }else {
        cout <<-1<<endl;
    }

    return 0;
}
