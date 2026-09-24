#include <iostream>
#include <cstring>
using namespace std;

#define N 6
#define M 6

void encontrarUnidades(int tablero[N][M],int posX,int posY,char*direccion,
    int&unidadesEncontradas) {

    if (posX < 0 or posX >= N or posY < 0 or posY >= M) {
        return;
    }

    if (strcmp(direccion,"izquierda")==0) {

    }

    if (strcmp(direccion,"arriba")==0) {

    }

    if (strcmp(direccion,"derecha")==0) {

    }

    if (strcmp(direccion,"abajo")==0) {
        
    }
}

int main() {
    int tablero[N][M] {
        {0,0,0,1,0,1},
        {0,0,1,0,0,0},
        {0,1,0,0,0,1},
        {1,0,0,0,0,0},
        {0,1,0,0,0,0},
        {0,0,0,0,1,0}
    };

    int posInicialX, posInicialY;
    char direccion[10];//sentido
    int unidadesEncontradas = 0;

    cin >> posInicialX >> posInicialY;

    cout << "La sonda se envia a la posicion:("<<posInicialX<<","<<posInicialY<<")." << endl;

    cin >> direccion;

    cout<< "Movimiento de la sonda: "<<direccion<<endl;

    encontrarUnidades(tablero,posInicialX,posInicialY,direccion,unidadesEncontradas);

    cout << "El resultado de la busqueda sera: "<<unidadesEncontradas<<" unidades."<<endl;
    return 0;
}
