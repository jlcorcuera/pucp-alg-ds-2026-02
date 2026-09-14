
#include <iostream>
#include <iomanip>
#include <cmath>
#include <climits>
using namespace std;

//Jack Mendoza 20225080

const int cant_dientes = 8;
const int duracionCita1=60;
const int duracionCita2=45;
const int duracionCita3=50;

#include "Diente.h"

void cargaCromo(struct Diente cromo[],int num , int base) {// se está guardando al revés
    // los números variarían entre 0, 1, 2  y 3 ya que puede no estar en ningunas  (tomo el 3 como no estar en ninguna)
    int i=0;
    while (num > 0) {
        cromo[i].cita = num%base;
        num = num/base;
        i++;
    }
}

bool  validarDuraciones(struct Diente cromo[]) {
    int tiempoCita1=0;
    int tiempoCita2=0;
    int tiempoCita3=0;

    for (int i = 0; i < cant_dientes; i++) {
        if (cromo[i].cita == 0) {// vendría a ser la cita 1
            tiempoCita1+=cromo[i].duracionTotalReq;
        }else if (cromo[i].cita == 1) {// vendría a ser la cita 2
            tiempoCita2+=cromo[i].duracionTotalReq;
        }else if (cromo[i].cita == 2) {// vendría a ser la cita 3
            tiempoCita3+=cromo[i].duracionTotalReq;
        }
        // si es 3 no hago nada porque estoy considerando que ese significa que no está en ninguna cita
    }

    if (tiempoCita1 > duracionCita1||tiempoCita2 > duracionCita2 ||tiempoCita3 > duracionCita3) {
        return false;
    }
    return true;
}


int calcularGananciaTotal(struct Diente cromo []) {
    int gananciaTotal = 0;
    for (int i = 0; i < cant_dientes; i++) {
        gananciaTotal+=cromo[i].gananciaParcial;
    }
    return gananciaTotal;
}
void  copiarCromo(struct Diente (&mejorCromo)[cant_dientes], struct Diente cromo[cant_dientes]) {
    for (int i = 0; i < cant_dientes; i++) {
        mejorCromo[i] = cromo[i];
    }
}
void encontrarMejorCromo(struct Diente  cromo [],struct Diente (& mejorCromo )[cant_dientes], int &gananciaMax) {

    // verificamos diente por diente
    for (int i = 0; i < cant_dientes; i++) {
        int gananciaCromo=0;
        if (cromo[i].tipo == 1) {
            cromo[i].duracionTotalReq = 5* cromo[i].cantidadCaries;
            cromo[i].gananciaParcial = 20* cromo[i].cantidadCaries;
        }else if (cromo[i].tipo == 2) {
            cromo[i].duracionTotalReq = 7* cromo[i].cantidadCaries;
            cromo[i].gananciaParcial = 30* cromo[i].cantidadCaries;
        }else if (cromo[i].tipo == 3) {
            cromo[i].duracionTotalReq = 10* cromo[i].cantidadCaries;
            cromo[i].gananciaParcial = 35* cromo[i].cantidadCaries;
        }else if (cromo[i].tipo == 4) {
            cromo[i].duracionTotalReq = 12* cromo[i].cantidadCaries;
            cromo[i].gananciaParcial = 42* cromo[i].cantidadCaries;
        }
        gananciaCromo= calcularGananciaTotal(cromo);
        bool cromoValido = validarDuraciones(cromo);
        if (cromoValido) {
            //ahora debemos filtrar al mejor Cromo
            if (gananciaCromo>gananciaMax) {
                gananciaMax = gananciaCromo;
                copiarCromo(mejorCromo, cromo);
            }
        }//sino sigue buscando

    }

}

void imprimirCromo(struct Diente mejorCromo [cant_dientes]) {
    //recordar que las citas fueron asignadas en el codigo de 0 1 2 , el 3 representa que no hay citas
    for (int i = 0; i < 3; i++) { //por cada cita buscamos en todo el cromo los que pertenezcan a la cita
        for (int j = 0; j < cant_dientes; j++) {
           if (mejorCromo[j].cita ==i) {
               cout <<"Cita: "<<i+1<<" Diente: "<<j+1 <<endl;
           }
        }
    }
}
int main() {
    // 3 citas (mochilas)
    // 8  (objetos)
    int base = 4;

    int opciones = (int) pow(base, cant_dientes);

    struct Diente cromo[cant_dientes] = {
        {1, 1, 1, 3},
        {2, 1, 1, 1},
        {3, 1, 2, 0},
        {4, 1, 3, 1},
        {5, 1, 3, 2},
        {6, 1, 4, 1},
        {7, 1, 4, 2},
        {8, 1, 4, 3}
    };
    struct Diente mejorCromo[cant_dientes];
    int gananciaMax = INT_MIN;
    // barremos cada combinación
    for (int i = 0; i < opciones; i++) {
        //cargamos el cromo con una opcion de citas
        cargaCromo(cromo, i, cant_dientes);
        encontrarMejorCromo(cromo, mejorCromo, gananciaMax);
    }
    imprimirCromo(mejorCromo);
    cout<<"La ganancia máxima es: "<<gananciaMax;
    return 0;
}
