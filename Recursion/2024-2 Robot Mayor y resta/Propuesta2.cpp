#include <iostream>
#define N 5
#define M 5
using namespace std;

/*
 * Solución de:
*   Donna Ventura 20230683
    Karina Pérez 20234939
 */
void robotStock(int matriz[N][M], int x, int y, int& max);
int main() {
    int matriz[N][M]={
        {4, 3, 6, 8, 7},
        {6, 3, 8, 4, 10},
        {2, 15, 1, 2, 13},
        {5, 1, 10, 11, 2},
        {10, 4, 7, 9, 4}
    };
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    int x=0;
    int y=0;
    int max=0;
    robotStock(matriz, x, y, max);
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
void robotStock(int matriz[N][M], int x, int y, int& max) {
    if (x>N-1 || y>M-1) return;
    if (matriz[x][y]>max) {
        max=matriz[x][y];
    }
    if (y==M-1) {
        robotStock(matriz, x+1, 0, max);
    }else {

        robotStock(matriz, x, y+1, max);
    }

    matriz[x][y]=max-matriz[x][y];
}