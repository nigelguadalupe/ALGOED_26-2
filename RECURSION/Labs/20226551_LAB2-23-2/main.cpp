#include <iostream>

using namespace std;

#define N 7

int buscarCandidato(int posicion,int receptor,int servidores[N][N]) {

    //Como buscamos el candidato ??? PUES VAMOS A IR VIENDO CADA EMISOR CON EL RECEPTOR

    //CASO BASE: ya se comparó contra todos los receptores posibles (0 a N-1).
    //Se devuelve el candidato que sobrevivió sin ser descartado hasta este punto.

    if (receptor == N) {
        return posicion;
    }

    if (servidores[posicion][receptor] > 0) {
        return buscarCandidato(posicion,receptor+1,servidores);
    }else { //servidores[posicion][receptor] == 0: el candidato actual (posicion) falló en
        //enviarle a receptor, así que queda descartado. El nuevo candidato pasa a ser receptor.
        return buscarCandidato(receptor,receptor+1,servidores);
    }
}

int main() {

    int servidores[N][N] {
        {0,0,0,0,0,0,0},
        {10,0,20,30,0,20,40},
        {0,0,0,0,0,100,0},
        {0,0,0,0,0,80,0},
        {50,10,5,10,0,100,4},
        {100,0,0,0,0,0,0},
        {0,0,0,0,0,0,0}
    };

    //Buscamos la posicion del candidato a skynerd

    int posicion = buscarCandidato(0,1,servidores);

    //Una ves tenemos la posicion del posible candidato evaluamos que en efecto sea Skynerd


    //Ya garantizamos que Skynerd es cuando envía paquetes a todos los servidores de la red

    //sin excluir ninguno

    //FALTA EL HECHO QUE SEA EXCEPTO A EL MISMO

    //Y QUE NINGUN SERVIDOR DE LA RED PUEDA ENVIAR PAQUETES A SKYNERD

    //Para desarrollarlo usaremos contadores

    int contador1=0;
    int contador2=0;

    for (int i=0;i<N;i++) {

        //EVALUAMOS QUE NO SEA EN A MISMA POSICIÓN

        if (i!=posicion) {

            if (servidores[posicion][i]!=0) { // CON ESTE IF GARANTIZAMOS QUE se CUPLA EL PRIMER INCISO
                contador1++;
            }

            if (servidores[i][posicion]!=0) { //CON ESTO GARANTIZAMOS EL 2DO INCISO
                contador2++;
            }
        }
    }

    if (contador2 == 0 and contador1 == N -1) {
        cout << "SkyNerd ha sido detectado en el servidor: "<< posicion + 1<<endl;
    }else {
        cout << "SkyNerd no está en la red"<<endl;
    }
    return 0;
}