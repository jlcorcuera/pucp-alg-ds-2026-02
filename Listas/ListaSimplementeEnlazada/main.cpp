//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
using namespace std;

/*
 * IMPLEMENTACION DE UNA LISTA SIMPLEMENTE ENLAZADA
 * ALGORITMIA Y ESTRUCTURA DE DATOS 2025-2
 */
int main(int argc, char **argv) {

    struct ElementoLista elemento{};
    struct Lista listaInicio, listaFinal, listaEnOrden;

    construir(listaInicio);
    construir(listaFinal);
    construir(listaEnOrden);
    cout << "La lista esta vacia: " << esListaVacia(listaInicio) << endl;

    for (int i = 1; i < 10; i+=2) {
        elemento.codigo = i;
        insertarAlInicio(listaInicio, elemento);
    }
    imprimir(listaInicio);

    /*Inserta datos desde el final de la lista*/
    for (int i = 4; i < 7; i++) {
        elemento.codigo = i;
        insertarAlFinal(listaFinal, elemento);
    }
    imprimir(listaFinal);

    elemento.codigo = 75;
    insertarEnOrden(listaEnOrden, elemento);
    elemento.codigo = 5;
    insertarEnOrden(listaEnOrden, elemento);
    elemento.codigo = 25;
    insertarEnOrden(listaEnOrden, elemento);
    elemento.codigo = 85;
    insertarEnOrden(listaEnOrden, elemento);


    imprimir(listaEnOrden);

    /*Elimina un nodo de la lista correspondiente al elemento ingresado*
    // [1, 10, 6]
    /*para que pueda eliminar busca el elemento dentro de la lista para eliminarlo*/
    elemento.codigo = 85;
    eliminaNodo(listaEnOrden, elemento);
    imprimir(listaEnOrden);

    destruir(listaEnOrden);
    imprimir(listaEnOrden);
    return 0;
}
