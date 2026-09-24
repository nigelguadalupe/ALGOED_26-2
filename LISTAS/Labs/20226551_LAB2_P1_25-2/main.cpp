#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

#include "BibliotecaLista/funcionesLista.h"
#include "BibliotecaLista/Lista.h"

void reordenaFormacion(Lista&listaJugadores) {

    //1ero como trabajamos con un archivo debemos iniciar la lectura de dicho archivo
    ifstream arch("formacion.txt", ios::in);
    if (not arch.is_open()) {
        cout << "El aarchivo formacion.txt no se pudo abrir "<<endl;
        exit(1);
    }

    //2do alistamos los punteros
    NodoLista *ptrInicio = nullptr;
    NodoLista *ptrFin = nullptr;

    char posicion[20]{};

    while (true) {
        arch.getline(posicion,20);
        if (arch.eof())break;

        NodoLista *recorrido = listaJugadores.inicio;
        NodoLista *anterior = nullptr;

        while (recorrido!=nullptr) {

            if (strcmp(recorrido->elemento.posicion,posicion)==0) {

                NodoLista * encontrado = recorrido;

                if (anterior!=nullptr) {
                    anterior->siguiente = recorrido->siguiente;
                }else { // SI NO EXISTE UN ANTERIOR
                    listaJugadores.inicio = recorrido->siguiente;
                }

                recorrido = recorrido->siguiente;
                encontrado->siguiente = nullptr;

                if (ptrFin == nullptr) {
                    ptrInicio = encontrado;
                    ptrFin = encontrado;

                }else {
                    ptrFin->siguiente = encontrado;
                    ptrFin = encontrado;
                }

            }else {
                anterior = recorrido;
                recorrido = recorrido->siguiente;
            }
        }
    }
    listaJugadores.inicio = ptrInicio;
}

int main() {

    Lista listaJugadores;

    construir(listaJugadores);

    insertarAlFinal(listaJugadores,{7,"Martinez","Delantero"});
    insertarAlFinal(listaJugadores,{1,"Ramirez","Portero"});
    insertarAlFinal(listaJugadores,{5,"Perez","Defensa"});
    insertarAlFinal(listaJugadores,{8,"Torres","Mediocampo"});
    insertarAlFinal(listaJugadores,{9,"Lopez","Delantero"});
    insertarAlFinal(listaJugadores,{3,"Gomez","Defensa"});

    imprimir(listaJugadores);

    //Formacion : Portero, Defensa, Mediocampo y Delantero

    reordenaFormacion(listaJugadores);
    cout <<endl;
    cout <<endl;
    imprimir(listaJugadores);

    return 0;
}
