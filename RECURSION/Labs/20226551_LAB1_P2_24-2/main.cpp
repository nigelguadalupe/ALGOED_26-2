#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

#define N 5
#define M 5

void actualizarMatriz(int matriz[N][M],int x,int y,int&cantidadMaxima) {

    int nuevoX=0, nuevoY=0;

    if (x < 0 or y < 0 or x > N-1 or y > M-1) {
        return;
    }

    if (y + 1 < N) {
        nuevoX = x;
        nuevoY = y + 1;
    }else {
        nuevoX = x+1;
        nuevoY = 0;
    }

    if (cantidadMaxima < matriz[x][y]) {
        cantidadMaxima = matriz[x][y];
    }

    actualizarMatriz(matriz,nuevoX,nuevoY,cantidadMaxima);

    matriz[x][y] = cantidadMaxima - matriz[x][y];

}
void imprimirMatriz(int matriz[N][N]) {

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cout << matriz[i][j] << "  ";
        }
        cout << endl;
    }
}
int main() {

    int matriz[N][N] {
        {4,3,6,8, 7},
        {6,3,8,4,10},
        {2,15,1,2,13},
        {5,1,10,11,2},
        {10,4,7,9,4}
    };

    int cantidadMaxima = 0;
    actualizarMatriz(matriz,0,0,cantidadMaxima);

    cout << "cantidad maxima: " << cantidadMaxima << endl;

    imprimirMatriz(matriz);

    return 0;
}
