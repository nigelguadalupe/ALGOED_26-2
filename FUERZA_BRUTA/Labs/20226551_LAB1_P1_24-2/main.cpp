#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

void contarLetrasCromosoma(int*cromosoma,int letrasFabricadas,
    int numeroLetras) {

    for (int i=0;i<numeroLetras-1;i++) {
        if (cromosoma[i] == 1) {

        }
    }
}
void llenarCromosoma(int*cromosoma,int valor,int numeroLetras) {

    for (int i=0;i<numeroLetras;i++) {
        cromosoma[i] = valor%2;
        valor /= 2;
        //cout << cromosoma[i];
    }
    //cout << endl;
}

void formarPalabras(char*letrasFabricadas,int numeroLetras) {

    int numeroCombinaciones = pow(2,numeroLetras) -1;

    int cromosoma[numeroLetras]{};

    for (int valor = 0;valor <= numeroCombinaciones;valor++) {

        
        llenarCromosoma(cromosoma,valor,numeroLetras);
        contarLetrasCromosoma(cromosoma,letrasFabricadas,numeroLetras);

    }

}

int main() {

    char letrasFabricadas[8]{'G','A','L','A','O','G','L','M'};

    const int numeroLetras = 8;
    //Debemos formar

    formarPalabras(letrasFabricadas,numeroLetras);

    return 0;
}
