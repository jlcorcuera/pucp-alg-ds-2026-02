#include <iostream>
using namespace std;

void imprimirMatriz(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }
}

void recursivaDoble(int matriz[5][5],int iteración,int x, int y,int & mayor,int matrizAux[5][5]) {
    if (iteración == 0) {
        if (y>4) recursivaDoble(matriz,0,x+1,0,mayor,matrizAux);
        else if (x>4) recursivaDoble(matriz,1,0,0,mayor,matrizAux);
        else if (matriz[x][y]>mayor) {
            mayor = matriz[x][y];
            recursivaDoble(matriz,0,x,y+1,mayor,matrizAux);
        } else {
            recursivaDoble(matriz,0,x,y+1,mayor,matrizAux);
        }
    } else {
        if (y>4) recursivaDoble(matriz,1,x+1,0,mayor,matrizAux);
        else if (x>4) return;
        else {
            matrizAux[x][y] = mayor - matriz[x][y];
            recursivaDoble(matriz,1,x,y+1,mayor,matrizAux);
        }
    }
}

int main() {
    int matriz[5][5] {
        {4,3,6,8,7},
        {5,3,8,4,10},
        {2,15,1,2,13},
        {5,1,10,11,2},
        {10,4,7,9,4}
    };
    int matrizAux[5][5] {

    };
    imprimirMatriz(matriz);
    int mayor = 0;
    recursivaDoble(matriz,0,0,0,mayor,matrizAux);
    cout << mayor << endl;
    imprimirMatriz(matrizAux);
    return 0;
}