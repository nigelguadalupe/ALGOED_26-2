#include <iostream>

using namespace std;

#define N 6
#define M 11

void imprimir(int mina[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mina[i][j]==-1) {
                cout <<"* ";
            }else {
                cout << mina[i][j] << " ";
            }

        }
        cout << endl;
    }
}

bool perforarGalerias(int mina[N][M],int posX,int posY,int galeria) {
    if (posX < 0 or posX >=N or posY < 0 or posY >=M) {
        return false;
    }

    
    if (mina[posX][posY] !=0) {
        return false;
    }

    mina[posX][posY] = galeria;

    //Procedemos con los movimientos

    //1ero se mueve abajo
    if (perforarGalerias(mina,posX+1,posY,galeria)) {
        return true;
    }

    //2do se mueve a la derecha
    if (perforarGalerias(mina,posX,posY+1,galeria)) {
        return true;
    }

    //3ero se mueve arriba
    //Para el movimiento hacia arriba primero
    //tenemos que hacer que el movimiento se reinicie al inicio arriba

    if (posY == M - 1) {
        perforarGalerias(mina,N-galeria-1,0,galeria+1);
        return true;
    }

    if (perforarGalerias(mina,posX-1,posY,galeria)) {
        return true;
    }

    mina[posX][posY] = 0;

    return false;
}

int main() {
    int mina[N][M]{};

    //mina[5][5]=-1;
    mina[4][5]=-1;
    mina[3][5]=-1;

    int x = N-1;
    int y = 0;
    int galeria = 1;

    imprimir(mina);
    cout << endl;
    perforarGalerias(mina,x,y,galeria);

    imprimir(mina);
    return 0;
}
