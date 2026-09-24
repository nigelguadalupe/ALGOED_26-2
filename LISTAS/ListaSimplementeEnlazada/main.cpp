//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
using namespace std;

/*
 * IMPLEMENTACION DE UNA LISTA SIMPLEMENTE ENLAZADA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2026-2
 */


void invertirLista(Lista&lista) {

    NodoLista *anterior = nullptr;
    NodoLista*actual = lista.inicio;
    NodoLista*siguiente = nullptr;

    while(actual) {

        siguiente = actual->siguiente;
        actual->siguiente = anterior;

        anterior = actual;
        actual = siguiente;
    }
    lista.inicio = anterior;
}

int main(int argc, char **argv) {

    //1ero Implementar una función que invierta los elementos de una lista enlazada

    Lista listaSimplementeEnsalada;

    construir(listaSimplementeEnsalada);

    insertarAlFinal(listaSimplementeEnsalada,{20});
    insertarAlFinal(listaSimplementeEnsalada,{40});
    insertarAlFinal(listaSimplementeEnsalada,{50});
    // insertarAlFinal(listaSimplementeEnsalada,{10});
    // insertarAlFinal(listaSimplementeEnsalada,{30});
    // insertarAlFinal(listaSimplementeEnsalada,{45});
    // insertarAlFinal(listaSimplementeEnsalada,{700});
    imprimir(listaSimplementeEnsalada);

    cout << endl;

    invertirLista(listaSimplementeEnsalada);

    imprimir(listaSimplementeEnsalada);

    return 0;
}
