#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;

// 26 -> [a,b,c,d,e]

void imprimirCromosoma(int*cromosoma, int cantObjetos,int pesoTotal,int valorTotal) {

    cout<<"[";
    for (int i = 0; i < cantObjetos; i++) {
        cout << cromosoma[i] << " ";
    }
    cout << "] : "<<pesoTotal<<"kg : "<<valorTotal<<"soles"<<endl;
}

void crearCromosoma(int valor,int*cromosoma,int cantidadObjetos,int*pesos,int&pesoTotal,
    int*valores,int&valorTotal) {
    int cociente, residuo;
    int i = cantidadObjetos - 1; // indice 4

    int k = 0;
    while (valor!=0) {

        residuo = valor%2;
        cociente = valor/2;

        //PROCESAMOS EL RESIDUO
        cromosoma[i] = residuo;
        i--; // indice : 3 , indice : 2

        if (residuo == 1) {
            pesoTotal += pesos[k];
            valorTotal += valores[k];
        }

        k++;
        valor = cociente;
    }
}

void crearTodosLosCromosomas(int cantObjetos,int*pesos,int pesoMaximoMochila,
    int *valores) {

    int pesoMaximo = 0,valorMaximo = 0;
    int cromosomaElegido[cantObjetos];
    int numCombinaciones = pow(2,cantObjetos)-1;
    for (int valor = 0;valor <= numCombinaciones;valor++) {

        int pesoTotal = 0;
        int valorTotal = 0;

        int cromosoma[cantObjetos]{};

        //CUANDO CREAMOS EL CROMOSOMA CALCULAREMOS EL PESO TOTAL
        crearCromosoma(valor,cromosoma,cantObjetos,pesos,pesoTotal,valores,valorTotal);

        if (pesoTotal <= pesoMaximoMochila) {
            cout<<"valor:"<<valor<<" ";
            imprimirCromosoma(cromosoma, cantObjetos,pesoTotal,valorTotal);

            if (valorTotal >=valorMaximo) { // AQUI DEPENDE DE LO QUE TE PIDAN
                pesoMaximo = pesoTotal;
                valorMaximo = valorTotal;

                for (int i=0;i<cantObjetos;i++) {
                    cromosomaElegido[i] = cromosoma[i];
                }
            }
        }
    }

    cout << "Cromosoma ganador:"<<endl;
    imprimirCromosoma(cromosomaElegido,cantObjetos,pesoMaximo,valorMaximo);
}

//Tema 1 de Alien Coders
//FUERZA BRUTA
int main() {

    int cantObjetos = 5;

    //1ero creo un arreglo donde guardare mis pesos
    int pesos[cantObjetos]={1,2,4,12,1};
    int valores[cantObjetos]={5,3,2,5,10};

    int pesoMaximoMochila = 15;

    crearTodosLosCromosomas(cantObjetos,pesos,pesoMaximoMochila,valores);


    return 0;
}

