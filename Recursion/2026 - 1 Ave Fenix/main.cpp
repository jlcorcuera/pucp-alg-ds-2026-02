#include <iostream>
#define N 10
#define M 6

// Jack Mendoza 20225080
using namespace std;

// Busca candidato recursivamente
int buscacanarios(int aportes[][N], int posible, int ind, int n) {
    if (ind==n)
        return posible;

    if (posible!=ind and (aportes[posible][ind]>0 or aportes[ind][posible]==0))
        posible=ind;

    return buscacanarios(aportes,posible,ind+1,n);
}

// Valida recursivamente al candidato
int validarcandidato(int aportes[][N], int posible, int i, int n){
    if(i==n) return posible;
    if(i!=posible){
        if(aportes[posible][i]!=0) return -1;
        if(aportes[i][posible]==0) return -1;
    }
    return validarcandidato(aportes, posible, i+1, n);
}

// Función principal
int valida(int aportes[][N], int n) {
    int posible=buscacanarios(aportes,0,1,n);
    return validarcandidato(aportes,posible,0,n);
}

int main() {

    int aportes[][N] = {
        {100,0,50,40,30,20,30,0,80,0},
        {50,100,0,40,30,20,20,0,10,25},
        {80,30,100,40,30,0,30,20,10,60},
        {50,0,0,100,30,0,50,30,30,90},
        {50,10,10,10,100,0,10,50,10,50},
        {20,0,0,0,0,100,90,20,40,20},
        {0,0,0,0,0,0,100,0,0,0},
        {0,0,0,0,0,0,50,100,50,20},
        {0,0,0,0,0,0,90,0,100,10},
        {0,0,0,0,0,0,10,0,60,100}
    };

    cout << valida(aportes, N) << endl;

    return 0;
}