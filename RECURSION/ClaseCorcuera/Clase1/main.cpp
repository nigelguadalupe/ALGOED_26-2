#include <iostream>
#include <iomanip>

using namespace std;

#define N 8
#define n 5
#define m 6

int encontrarMaximo(int arrEnteros[N],int indice) {
    if (indice == N - 1) {
        return arrEnteros[indice];
    }
    return max(arrEnteros[indice],encontrarMaximo(arrEnteros, indice + 1));
}

int encontrarNumero(int numeroAencontrar, int*arrEncontrado,int indice) {

    if (indice < 0 ) {
        return -1;
    }
        if (arrEncontrado[indice] == numeroAencontrar) return indice;
    return encontrarNumero(numeroAencontrar, arrEncontrado, indice -1);
}

int longitud(char*palabrita,int indice) {

    if (palabrita[indice] == '\0') {
        return 0;
    }
    return longitud(palabrita, indice+1) + 1;
}

//LongitudPalabra pasa a ser el final de la linea
//El inicio de la palabra es 0, indice = 0;
int verificarPalindromo(char*palabrita,int inicio,int fin) {

    //Caso base
    if (inicio >= fin) {
        return 1;
    }
    if (palabrita[inicio]!=palabrita[fin]) return 0;
    return verificarPalindromo(palabrita,inicio+1,fin-1);

}



int sumarMatriZzz(int matrizzz[n][m],int filaCentro,int columnaCentro) {
    // int sumarFilas = sumarFila(matrizzz,filaCentro,0);
    // int sumarColumnas = sumarColumna(matrizzz,0,columnaCentro);
}



int main() {

    int arrEnteros[N]{-4,-5,6,20,11,55,14,40};

    int maximoEntero = encontrarMaximo(arrEnteros,0);

    cout << "El maximo es "<< maximoEntero << endl;


    int numeroAencontrar = 3;
    int arrEncontrado[10]{-4,-5,6,20,11,12,14,40,9,10};
    int pos = encontrarNumero(numeroAencontrar, arrEncontrado,9);
    cout << pos<<endl;


    //Problema del PALINDROMO

    char palabrita[]="level";

    int longitudPalabra = longitud(palabrita,0);

    int esPalindromo = verificarPalindromo(palabrita,0,longitudPalabra-1);

    if (esPalindromo) {
        cout << "Es palindromo"<< endl;
    }else {
        cout << "NO es palindromo XDD"<<endl;
    }
    return 0;

    //Matriz -> Desarrollar una función recursiva que data una coordenada de la matriz, calcule la suma
    //de la cruz teniendo dicha coordenada como centro;


    int matrizzz[5][6] {
        {5,31,5,111,120,131},
        {20,8,8,51,41,151},
        {15,10,9,-1,-2,161},
        {10,9,20,18,0,21},
        {15,14,13,10,11,19}
    };

    int Xcentro = 2, Ycentro = 2;

    int resultado = sumarMatriZzz(matrizzz,Xcentro,Ycentro);
}