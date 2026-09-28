//Fecha:  sábado 30 Agosto 2025 
//Autor: Ana Roncal

#include <iostream>
#include "BibliotecaLista/Lista.h"
#include "BibliotecaLista/funcionesLista.h"
using namespace std;

/*
*Para ello, implemente las funciones necesarias para:
i) Contar ocurrencias -> DONE
ii) Verificar si un usuario ya fue agregado a una lista -> DONE
iii) Genere una la lista de sospechosos, sin repetir códigos.
iv) Eliminar todas las ocurrencias de usuarios sospechosos de la lista original.
*/

int contarOcurrencias(Lista lista, int codigo) {
    int counter = 0;
    NodoLista * recorrido = lista.inicio;
    for (int i=0; i < lista.longitud; i++) {
        if (recorrido->elemento.codigo == codigo) {
            counter++;
        }
        recorrido = recorrido->siguiente;
    }
    return counter;
}

bool verificarYaFueAgregado(Lista lista, int codigo) {
    return contarOcurrencias(lista, codigo) > 0;
}

Lista generarListaSospechosos(Lista lista) {
    struct Lista listaSospechosos;
    construir(listaSospechosos);
    int counter = 0;
    struct ElementoLista elemento{};
    NodoLista * recorrido = lista.inicio;
    for (int i=0; i < lista.longitud; i++) {
        if (contarOcurrencias(lista, recorrido->elemento.codigo) >= 3 &&
            !verificarYaFueAgregado(listaSospechosos, recorrido->elemento.codigo)) {
            elemento.codigo = recorrido->elemento.codigo;
            insertarAlFinal(listaSospechosos, elemento);
        }
        recorrido = recorrido->siguiente;
    }
    return listaSospechosos;
}

void eliminarSospechosos(Lista &lista, Lista &listaSospechosos) {
    NodoLista * recorridoSospechoso = listaSospechosos.inicio;
    for (int i=0; i < listaSospechosos.longitud; i++) {
        int codigoSospechoso = recorridoSospechoso->elemento.codigo;
        NodoLista * recorrido = lista.inicio;
        while (recorrido != nullptr) {
            ElementoLista elemento = recorrido->elemento;
            int codigoActual = elemento.codigo;
            recorrido = recorrido->siguiente;
            if (codigoActual == codigoSospechoso) {
                eliminaNodo(lista, elemento);
            }

        }
        recorridoSospechoso = recorridoSospechoso->siguiente;
    }
}


int main(int argc, char **argv) {
    struct ElementoLista elemento{};
    struct Lista listaIntentos, listaResultado;
    construir(listaIntentos);
    int codigos[] = {410, 102, 205, 102, 205, 330, 102, 205, 410, 205, 777};
    int size  = sizeof(codigos)/sizeof(codigos[0]);

    /*Inserta datos desde el final de la lista*/
    for (int i = 0; i < size; i++) {
        elemento.codigo = codigos[i];
        insertarAlFinal(listaIntentos, elemento);
    }
    imprimir(listaIntentos);
    cout << "Numero de ocurrencias de 205: " << contarOcurrencias(listaIntentos, 205) << endl;
    listaResultado = generarListaSospechosos(listaIntentos);
    imprimir(listaResultado);
    eliminarSospechosos(listaIntentos, listaResultado);
    imprimir(listaIntentos);
    return 0;
}
