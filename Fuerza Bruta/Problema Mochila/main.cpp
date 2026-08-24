#include <cmath>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int products[] = {1,12,4,2,1};
    int mochila = 15;
    int combinaciones = pow(2,5) - 1;
    for(int combinacion = 0; combinacion < combinaciones; combinacion ++){
        int tmp = combinacion;
        int capacidad_actual = 0;
        for(int idx_producto =0; idx_producto<5;idx_producto++){
            int incluir_producto = tmp % 2;
            if (incluir_producto) {
                capacidad_actual += products[idx_producto];
            }
            tmp = tmp / 2;
        }
        if (capacidad_actual == mochila) {
            tmp = combinacion;
            cout << "ENCONTRE SOLUCION: "<< endl;
            for(int idx_producto =0; idx_producto<5;idx_producto++){
                int incluir_producto = tmp % 2;
                if (incluir_producto) {
                    cout<<(char)('A'+idx_producto);
                }
                tmp = tmp / 2;
            }
            cout<<endl;
        }
    }
    return 0;
}