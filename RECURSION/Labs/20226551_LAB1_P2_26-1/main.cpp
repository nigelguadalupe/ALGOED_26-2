#include <iostream>

using namespace std;

#define N 10
#define M 10

int buscarArtefacto(char matriz[N][M],int x,int y,int alcance,int direccion) {
    if (x < 0 or y < 0 or x >= N or y >= M or alcance < 0) {
        return 0;
    }

    //POSICION INICIAL
    if (direccion == 0) {
        return buscarArtefacto(matriz,x,y,alcance,1) + buscarArtefacto(matriz,x,y,alcance,2);
    }

    int encontrado = 0;

    if (matriz[x][y] == 'A') {
        encontrado = 1;
    }

    matriz[x][y] = '*';

    if (direccion == 1) {
        return encontrado + buscarArtefacto(matriz,x-1,y,alcance-1,1)
        + buscarArtefacto(matriz,x-1,y-1,alcance-1,1)
        + buscarArtefacto(matriz,x-1,y+1,alcance-1,1);
    }else { // Si direccion == 2
        return encontrado + buscarArtefacto(matriz,x+1,y,alcance-1,2)
        + buscarArtefacto(matriz,x+1,y-1,alcance-1,2)
        + buscarArtefacto(matriz,x+1,y+1,alcance-1,2);
    }

}

void imprimir(char matriz[N][M]) {
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {

    char matriz[N][M]{};

    //Ubicamos los artefactos "A"

    matriz[3][3] = 'A';
    matriz[3][4] = 'A';
    matriz[4][5] = 'A';
    matriz[5][4] = 'A';
    matriz[5][7] = 'A';
    matriz[7][5] = 'A';

    //Procedemos a buscar dichos artefactos
    int alcance = 3, posX = 5, posY = 5;
    int cantidadArtefactos = buscarArtefacto(matriz,posX,posY,alcance,0);

    cout << "El robot encontro "<< cantidadArtefactos << " artefactos, realizando la siguiente busqueda."<<endl;
    imprimir(matriz);
    return 0;
}
