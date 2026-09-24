#include <iostream>



using namespace std;

#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"

void reordenarLista(Lista&listaCuadrigas) {
    //1ero hacemos uso de punteros

    NodoLista *ptrInicioPar = nullptr;
    NodoLista *ptrFinPar = nullptr;

    NodoLista *ptrInicioImpar = nullptr;
    NodoLista *ptrFinImpar = nullptr;

    NodoLista *recorrido = listaCuadrigas.inicio;

    while (recorrido!=nullptr) {

        //Si el elemento es par entonces va al inicio de la lista
        if (recorrido->elemento.id%2==0) {
            //Validamos primero si hay o no un par
            if (ptrInicioPar == nullptr) {

                //Ese nuevo nodo va ser nuestro inicio del par
                //como el fin del par

                ptrInicioPar = recorrido;
                ptrFinPar = recorrido;
            }else {
                //Si no es el primero pues entones se va actualizando
                ptrFinPar->siguiente = recorrido;
                ptrFinPar = recorrido;
            }
        }else {
            //Si el nodo es impar entonces se debe verificar de la misma forma
            //como con el par
            if (ptrInicioImpar == nullptr) {

                ptrInicioImpar = recorrido;
                ptrFinImpar = recorrido;
            }else {
                ptrFinImpar->siguiente = recorrido;
                ptrFinImpar = recorrido;
            }
        }
        recorrido = recorrido->siguiente;
    }

    //CUANDO SOLO HAY PARES
    if (ptrInicioImpar == nullptr and ptrFinImpar == nullptr) {
        listaCuadrigas.inicio = ptrInicioPar;
        ptrFinPar->siguiente = nullptr;
    }else if (ptrInicioPar == nullptr and ptrFinPar == nullptr) {
        listaCuadrigas.inicio = ptrInicioImpar;
        ptrFinImpar->siguiente = nullptr;
    }else { // Si existe al menos un par o un impar
        //Actualizamos el inicio de la lista
        listaCuadrigas.inicio = ptrInicioPar;
        ptrFinPar->siguiente = ptrInicioImpar;
        ptrFinImpar->siguiente = nullptr;
    }

}

int main() {

    //RE-ORDENAR LISTA, ID par, ID Impar

    Lista listaCuadrigas;
    construir(listaCuadrigas);

    insertarAlFinal(listaCuadrigas,{17,"Messala","Rojo"});
    insertarAlFinal(listaCuadrigas,{4,"Ben-Hur","Azul"});
    insertarAlFinal(listaCuadrigas,{12,"Artax","Verde"});
    insertarAlFinal(listaCuadrigas,{7,"Drusus","Negro"});

    cout << "Lista inicial:"<<endl;
    imprimir(listaCuadrigas);

    reordenarLista(listaCuadrigas);

    cout << endl;
    cout << "Lista Final:"<<endl;

    imprimir(listaCuadrigas);

    return 0;
}
