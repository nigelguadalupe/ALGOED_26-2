#include <iostream>
#include <fstream>

using namespace std;

#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"


// k = posicion del mayor
// n = posicion del menor

void intercambiarPorPosicion(Lista &lista, int n, int k) {

    if (n > k) {
        int temporal = n;
        n = k;
        k = temporal;
    }

    //Se hace para inicializar uno antes que el otro

    NodoLista *antN = nullptr;
    NodoLista *nodoN = lista.inicio;

    int pos = 1;

    while (pos < n) {
        antN = nodoN;
        nodoN = nodoN->siguiente;
        pos++;
    }

    NodoLista *antK = antN;
    NodoLista*nodoK = nodoN;

    while (pos < k) {
        antK = nodoK;
        nodoK = nodoK->siguiente;
        pos++;
    }

    NodoLista *sigK = nodoK->siguiente;
    NodoLista *sigN = nodoN->siguiente;

    if (nodoN->siguiente == nodoK) {
        nodoK->siguiente = nodoN;          // caso pegados: solo 1 línea distinta
    } else {

        antK->siguiente = nodoN;
        nodoK->siguiente = sigN;
    }

    nodoN->siguiente = sigK;               // esta línea es igual en ambos casos

    if (antN != nullptr) {
        antN->siguiente = nodoK;
    }else {
        lista.inicio = nodoK;
    }
}


// void intercambiarPorPosicion(Lista&lista, int n,int k) {
//
// }

void reorganizarLista(Lista&listaLibros) {

    NodoLista *recorrido = listaLibros.inicio;
    //CREAREMOS UN NUMERO PARA ENCONTRAR EL MAYOR
    // Y EL MENOR

    int mayorCantLikes = 0;
    int menorCantLikes = 999999999;

    int mayorCantUndVentas = 0;
    int menorCantUndVentas = 999999999;

    int posMayorLikes = 0;
    int posMenorLikes = 0;
    int posMayorVentas = 0;
    int posMenorVentas = 0;
    int posicionActual = 1;

    while (recorrido!=nullptr) {

        if (mayorCantLikes < recorrido->elemento.cantidadLikes) {
            mayorCantLikes = recorrido->elemento.cantidadLikes;
            posMayorLikes = posicionActual;
        }

        if (menorCantLikes > recorrido->elemento.cantidadLikes) {
            menorCantLikes = recorrido->elemento.cantidadLikes;
            posMenorLikes = posicionActual;
        }

        if (mayorCantUndVentas < recorrido->elemento.unidadesVendidas) {
            mayorCantUndVentas = recorrido->elemento.unidadesVendidas;
            posMayorVentas = posicionActual;
        }

        if (menorCantUndVentas > recorrido->elemento.unidadesVendidas) {
            menorCantUndVentas = recorrido->elemento.unidadesVendidas;
            posMenorVentas = posicionActual;
        }

        posicionActual++;
        recorrido = recorrido->siguiente;



    }

    cout << posMayorVentas <<" " <<mayorCantUndVentas << endl;
    intercambiarPorPosicion(listaLibros, posMayorLikes, posMenorLikes);
    intercambiarPorPosicion(listaLibros, posMayorVentas, posMenorVentas);

}

int main() {

    Lista listaLibros;

    construir(listaLibros);

    insertarAlFinal(listaLibros,{"L001","Cien Anos de Soledad",200,400});
    insertarAlFinal(listaLibros,{"L002","1984",600,5000});
    insertarAlFinal(listaLibros,{"L003","El Principito",120,7500});
    insertarAlFinal(listaLibros,{"L004","Harry Potter",1200,12000});
    insertarAlFinal(listaLibros,{"L005","Sapiens",350,1000});
    insertarAlFinal(listaLibros,{"L006","Don Quijote",400,780});
    insertarAlFinal(listaLibros,{"L007","Fahrenheit 451",250,4500});
    insertarAlFinal(listaLibros,{"L008","Orgullo y Prejuicio",678,23000});

    imprimir(listaLibros);

    cout << endl;

    reorganizarLista(listaLibros);

    imprimir(listaLibros);

    return 0;
}
