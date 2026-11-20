#include <iostream>

#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
#include "BibliotecaCola/NodoCola.h"

using namespace std;

bool esPrioritario(ElementoCola *elementoA, ElementoCola *elementoB) {
    if (elementoA->gravedad != elementoB->gravedad) {
        return elementoA->gravedad < elementoB->gravedad;
    }
    if (elementoA->edad != elementoB->edad) {
        return elementoA->edad > elementoB->edad;
    }
    return elementoA->horaLlegada > elementoB->horaLlegada;
}

void encolarConPrioridad(struct Cola &cola, struct ElementoCola nuevo){
    Cola tmp;
    construir(tmp);

    if (esColaVacia(cola)) {
        encolar(tmp, nuevo);
    } else {
        bool already_inserted = false;
        while (!esColaVacia(cola)) {
            ElementoCola elemento = desencolar(cola);
            if (!already_inserted && esPrioritario(&elemento, &nuevo)) {
                encolar(tmp, nuevo);
                already_inserted = true;
            }
            encolar(tmp, elemento);
        }
    }

    while (!esColaVacia(tmp)) {
        encolar(cola, desencolar(tmp));
    }

}

void ordenDeAtencion(int n, Cola cola) {
    cout << "Orden de Atencion ==============================" << endl;
    imprimir(cola);
}

int main() {
    Cola cola;
    construir(cola);
    encolarConPrioridad(cola, {101,5,40,800});
    encolarConPrioridad(cola,{102,9,25,801});
    encolarConPrioridad(cola,{103,9, 60, 810});
    encolarConPrioridad(cola,{104,9, 8, 811});
    encolarConPrioridad(cola, {105,6,30,820});
    encolarConPrioridad(cola,{106,6,30,821});
    encolarConPrioridad(cola,{107,6,30,822});

    int n=7;
    ordenDeAtencion(n, cola);

    return 0;
}