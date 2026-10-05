//Fecha:  sábado 06 Setiembre 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
using namespace std;
/*
 * IMPLEMENTACION DEL TAD COLA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2025-2
 */

void encolarPrioritario(struct Cola &colaTAD, const struct ElementoCola & elemento){
    struct NodoCola *nuevo;
    nuevo = new NodoCola{};
    nuevo->elemento = elemento;
    bool esPreferente = elemento.preferente;
    if(esColaVacia(colaTAD)){
        colaTAD.inicio = nuevo;
        colaTAD.fin = nuevo;
        if (esPreferente) {
            colaTAD.last1 = nuevo;
        }
        cout << "Es cola vacia 1" << endl;
    } else if (esPreferente) {
        if (colaTAD.last1 == nullptr) {
            /*
             * Caso en el que no se tienen nodos preferentes
             */
            NodoCola * tmpInicio = colaTAD.inicio;
            nuevo->siguiente = tmpInicio;
            colaTAD.inicio = nuevo;
            colaTAD.last1 = nuevo;
            cout << "here " << endl;
        } else {
            NodoCola * tmpNext = colaTAD.last1->siguiente;
            colaTAD.last1->siguiente = nuevo;
            nuevo->siguiente = tmpNext;
        }
    } else {
        if (colaTAD.fin == nullptr) {
            colaTAD.last1->siguiente = nuevo;
            colaTAD.fin = nuevo;
        } else {
            colaTAD.fin->siguiente = nuevo;
            colaTAD.fin = nuevo;
        }
    }
}

int desencolarPrioritario(struct Cola &colaTAD) {
    struct NodoCola *inicio, *siguienteInicio;
    inicio = colaTAD.inicio;
    int codigo = -1;
    if (inicio != nullptr) {
        if (colaTAD.inicio == colaTAD.last1) {
            colaTAD.last1 = nullptr;
        }
        siguienteInicio = inicio->siguiente;
        colaTAD.inicio = siguienteInicio;
        codigo = inicio->elemento.codigo;
        delete inicio;
    }
    return codigo;
}


int main(int argc, char **argv) {
    struct Cola cola;
    struct ElementoCola elemento;
    construir(cola);

    cout << "La cola esta vacia: " << esColaVacia(cola) << endl;
    /*Encolamos elementos en la Cola*/
    elemento.codigo = 1001;
    elemento.preferente = false;
    encolarPrioritario(cola, elemento);

    elemento.codigo = 1002;
    elemento.preferente = true;
    encolarPrioritario(cola, elemento);

    imprimir(cola);

    int atendido = desencolarPrioritario(cola);
    cout << "Paciente atendido " << atendido << endl;

    elemento.codigo = 1004;
    elemento.preferente = false;
    encolarPrioritario(cola, elemento);

    elemento.codigo = 1005;
    elemento.preferente = true;
    encolarPrioritario(cola, elemento);

    atendido = desencolarPrioritario(cola);
    cout << "Paciente atendido " << atendido << endl;

    atendido = desencolarPrioritario(cola);
    cout << "Paciente atendido " << atendido << endl;

    atendido = desencolarPrioritario(cola);
    cout << "Paciente atendido " << atendido << endl;

    imprimir(cola);

    return 0;
}
