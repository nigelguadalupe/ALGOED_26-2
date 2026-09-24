#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

#include <cmath>
int main() {

    int capacidad = 15;
    int mochila2 = 4;
    int mochila3 = 1;

    int productos[]{1,12,4,2,1};

    int size_of = sizeof(productos) / sizeof(productos[0]);

    int combinaciones3 = pow(3,size_of);

    //int combinaciones2 = pow(3,size_of);

    for (int combinacion3 = 0; combinacion3 < combinaciones3;combinacion3++) {

        int temporal = combinacion3;
        int capacidad_actual = 0;

        for (int idx_producto = 0;idx_producto < size_of;idx_producto++) {
            int incluir_producto = temporal%3;

            if (incluir_producto) {
                capacidad_actual +=productos[idx_producto];
            }
            temporal = temporal/2;
        }
    }


    for (int combinacion = 0; combinacion < combinaciones3; combinacion++) {
        int temporal = combinacion;
        int capacidad_actual = 0;
        for (int idx_producto = 0; idx_producto < size_of; idx_producto++) {
            int incluir_producto = temporal%2;

            if (incluir_producto) {
                capacidad_actual += productos[idx_producto];
            }
            temporal = temporal/2;
        }

        if (capacidad_actual == capacidad) {

            temporal = combinacion;
            for (int i= 0;i<size_of;i++) {
                int incluir_producto = temporal%2;
                if (incluir_producto) {
                    cout << ((char)('A' + i));
                }
                temporal = temporal/2;
            }
            cout<< endl;
        }
    }
    cout << combinaciones3 << endl;

    //PC1 - 25-1

    //Para 6 tablas
    //
    // int tablas[]{150,100,80,50,120,10};
    //
    // int sizeof_tablas = sizeof(tablas)/sizeof(tablas[0]);
    //
    // int discos[]{250,200,200};
    //
    // int sizeof_discos = sizeof(discos)/sizeof(discos[0]);
    //
    //
    //
    return 0;
}
