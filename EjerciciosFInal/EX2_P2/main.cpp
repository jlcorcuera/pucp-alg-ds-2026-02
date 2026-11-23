#include <iostream>
using namespace std;
#define A 6
#define B 6
#define C 5

int Divide_Venceras(int arr_triaje[A],int arr_especialista[C],int inicio,int fin,int nfin) {
    if (inicio==fin) {
        return arr_triaje[inicio];
    }
    int medio=(inicio+fin)/2;
    // if(medio>nfin) {
    //     return Divide_Venceras(arr_triaje,arr_especialista,medio,fin,nfin);
    // }
    if (arr_triaje[medio]==arr_especialista[medio]) {
        return Divide_Venceras(arr_triaje,arr_especialista,medio+1,fin,nfin);
    }
    else {
        return Divide_Venceras(arr_triaje,arr_especialista,inicio,medio,nfin);
    }
}




int Funcion_Consulta(int arr_triaje[A],int arr_general[C],int inicio,int fin,int nfin) {
    //



    // if () {
      return  Divide_Venceras(arr_triaje,arr_general,inicio,fin,nfin);
    // }
    // else if () {
    //       return  Divide_Venceras(arr_triaje,arr_especialista,inicio,fin,nfin);
    // }



}

//ASTORAYME OLIVARES JEAN CARLOS 20235049
int main() {
    //Caso 1
    //int arr_triaje[A]={101,102,103,104,105,106};
    //int arr_general[B]={101,102,104,105,106};
    //int arr_especialista[C]={101,102,104,105,106};
     int arr_triaje[A]={101,102,103,104,105,106};
     int arr_general[B]={101,102,103,104,105,106};
    int arr_especialista[C]={101,102,103,105,106};
    int paciente;
    if (A!=B){
     paciente=Funcion_Consulta(arr_triaje,arr_general,0,A-1,B-1);
     cout<<"Paciente:"<<paciente<<endl;
     cout<<"Abandono despues de Triaje";
     cout<<endl;
    }
    else if (A!=C){
        paciente=Funcion_Consulta(arr_triaje,arr_especialista,0,A-1,C-1);
        cout<<"Paciente:"<<paciente<<endl;
        cout<<"Abandono despues de Consulta General";
        cout<<endl;
    }

    // //Caso 2
    // int arr_triaje_2[N]={101,102,103,104,105,106};
    // int arr_general_2[N]={101,102,103,104,105,106};
    // int arr_especialista_2[M]={101,102,103,105,106};
    // int paciente_2=Funcion_Consulta(arr_triaje_2,arr_especialista_2,0,N-1,M-1);
    // cout<<"Paciente:"<<paciente_2<<endl;
    // cout<<"Abandono despues de Consulta General";
    return 0;
}