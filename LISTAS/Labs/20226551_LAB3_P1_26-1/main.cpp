#include <iostream>

using namespace std;

#include "BibliotecaLista/funcionesLista.h"
#include "BibliotecaLista/Lista.h"

void eliminarOcurrencias(Lista&listaUsuarios,int usuario) {

    NodoLista * actual = listaUsuarios.inicio;
    NodoLista *anterior = nullptr;
    while (actual != nullptr) {

        if (actual->elemento.usuario == usuario) {

            NodoLista *nodoABorrar = actual;
            if (anterior == nullptr) {
                listaUsuarios.inicio = actual->siguiente;
            }else {
                anterior->siguiente = actual->siguiente;
            }
            actual = actual->siguiente;
            delete nodoABorrar;
            listaUsuarios.longitud--;
        }else{
            anterior = actual;
            actual = actual->siguiente;
        }
    }
}

bool verificarAgregado(Lista&lista,int usuario) {

    NodoLista *actual = lista.inicio;

    while (actual!=nullptr) {

        if (actual->elemento.usuario == usuario) {
            return true;
        }

        actual = actual->siguiente;
    }

    return false;
}

int contarOcurrencia(Lista&listaUsuarios,int usuario) {

    NodoLista *actual = listaUsuarios.inicio;
    int contador = 0;
    while (actual!=nullptr) {
        if (actual->elemento.usuario == usuario) {
            //cout << usuario << endl;
            contador++;
        }
        actual = actual ->siguiente;
    }
    return contador;
}

void resolver(Lista&listaUsuarios,Lista&listaSospechosos) {
    NodoLista *recorrido = listaUsuarios.inicio;
    NodoLista *actual = nullptr;
    while (recorrido != nullptr) {

        int contador = contarOcurrencia(listaUsuarios,recorrido->elemento.usuario);
        if (contador >= 3) {
            //AHORA DEBE VERIFICAR SI EL USUARIO YA FUE AGREGADO ANTES
            bool agregado = verificarAgregado(listaSospechosos,recorrido->elemento.usuario);

            if (not agregado) {
                insertarAlFinal(listaSospechosos,{recorrido->elemento.usuario});
            }

        }

        recorrido = recorrido -> siguiente;
    }

    NodoLista *sospechoso = listaSospechosos.inicio;

    while(sospechoso!=nullptr) {

        eliminarOcurrencias(listaUsuarios,sospechoso->elemento.usuario);
        sospechoso = sospechoso->siguiente;
    }

}


int main() {

    Lista listaUsuarios;
    Lista listaSospechosos;
    construir(listaUsuarios);
    construir(listaSospechosos);

    insertarAlFinal(listaUsuarios,{410});
    insertarAlFinal(listaUsuarios,{102});
    insertarAlFinal(listaUsuarios,{205});
    insertarAlFinal(listaUsuarios,{102});
    insertarAlFinal(listaUsuarios,{205});
    insertarAlFinal(listaUsuarios,{330});
    insertarAlFinal(listaUsuarios,{102});
    insertarAlFinal(listaUsuarios,{205});
    insertarAlFinal(listaUsuarios,{410});
    insertarAlFinal(listaUsuarios,{205});
    insertarAlFinal(listaUsuarios,{777});

    imprimir(listaUsuarios);

    resolver(listaUsuarios,listaSospechosos);

    imprimir(listaSospechosos);

    imprimir(listaUsuarios);


    return 0;
}
