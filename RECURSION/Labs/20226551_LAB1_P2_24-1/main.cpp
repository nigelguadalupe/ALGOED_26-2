#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

#define N 6
#define M 6

int encontrarUnidades(int matriz[N][M],int x,int y,int radio) {
    if (x - radio < 0 or x + radio > N -1 or y - radio < 0 or y + radio > M -1) {
        return 0;
    }
    int suma = 0;
    if (radio == 0) {
        suma = matriz[x][y]; //va sumar el punto en donde el radio sea 0;
    }else {
        //HORIZONTALES
        //Lado superior
        for (int columna = y - radio;columna <= y + radio;columna++) {
            suma += matriz[x - radio][columna];
        }
        //Lado inferior
        for (int columna = y - radio;columna <= y + radio;columna++ ) {
            suma += matriz[x + radio][columna];
        }

        //VERTICALES
        //Lado izquierdo ( sin repetir las esquinas )
        for (int fila  = x - radio +1;fila<=x + radio -1;fila++) {
            suma += matriz[fila][y-radio];
        }

        //Lado derecho ( sin repetir las esquinas )
        for (int fila = x - radio + 1;fila <= x + radio -1;fila++) {
            suma += matriz[fila][y+radio];
        }
    }

    return suma + encontrarUnidades(matriz,x,y,radio+1);
}

void imprimir(int matriz[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {

    int x = 3 ,y = 2;

    int matriz[N][M] {};

    matriz[0][3] = 1;
    matriz[0][5] = 1;
    matriz[1][2] = 1;
    matriz[2][1] = 1;
    matriz[2][5] = 1;
    matriz[3][0] = 1;
    matriz[4][1] = 1;
    matriz[5][4] = 1;
    //matriz[4][4] = 1;

    int unidadesEncontrada = encontrarUnidades(matriz,x,y,0);

    imprimir(matriz);

    cout << "El resultado de la búsqueda será: "<< unidadesEncontrada <<" unidades."<<endl;

    return 0;
}
