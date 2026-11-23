#include <iostream>

#include "BibliotecaArbolBinarioBusqueda/ArbolBinarioBusqueda.h"
#include "BibliotecaArbolBinarioBusqueda/funcionesArbolBinarioBusqueda.h"
#include "BibliotecaCola/Cola.h"
#include "BibliotecaCola/funcionesCola.h"
#define N 11
using namespace std;

/*
 * 20230293 CARLOS ALBERTO CHIA RAMOS
 *
 * para cada uno de las partes hice una funcion iterativa de complejidad o nlogn
 * o=nlogn +nlogn
 *
 * la reconstruccion usa una cola para ir recogiendo los datos segun los niveles, de esta manera los inserto usando la misma logica de insertar,
 * pero ahora de forma de iterativa, como sigue una logica en el peor de los casos NO recorre todo el archivo asi que la complejidad es logn
 *
 *
 */
void reconstruirArbol(ArbolBinarioBusqueda &arbol, int datos[N]) {
    Cola cola;
    construir(cola);
    int i=0;
    encolar(cola,{datos[0]});

    while (!esColaVacia(cola)) {
        ElementoCola dato = desencolar(cola);
        if (esArbolVacio(arbol)) {
            plantarNodoArbolBinario(arbol.raiz, nullptr,{dato.num}, nullptr);
        }else {
            NodoArbolBinarioBusqueda *nodo=arbol.raiz;
            while (nodo!=nullptr) {
                if (nodo->elemento.numero < dato.num) {
                    if (nodo->derecha==nullptr) {
                        plantarNodoArbolBinario(nodo->derecha, nullptr,{dato.num}, nullptr);
                        break;
                    }
                    nodo=nodo->derecha;
                }
                if (nodo->elemento.numero > dato.num){
                    if (nodo->izquierda==nullptr) {
                        plantarNodoArbolBinario(nodo->izquierda, nullptr,{dato.num}, nullptr);
                        break;
                    }
                    nodo=nodo->izquierda;
                }
            }
        }
            i++;
            if (i<N) {
                encolar(cola,{datos[i]});
            }
            i++;
            if (i<N) {
                encolar(cola,{datos[i]});
            }
        }
    }


/*
 * esta funcion tambine tendra complejidad nlogn, con la cola agrro los datos, luego los busco en el arbol(al ser busqueda logica por un camino comlejidad logn)
 * y encolo los dos datos siguientes
 */
void nuevoRecorrer(ArbolBinarioBusqueda arbol) {
    Cola cola;
    construir(cola);
    encolar(cola,{arbol.raiz->elemento.numero});
    int i=0;
    cout<<"IMPRESION POR AMPLITUD : ";
    while (i<N) {
        ElementoCola dato = desencolar(cola);
        cout<<dato.num<<"  ";
        if (dato.num!=arbol.raiz->elemento.numero) {
            //aca busca el dato
            NodoArbolBinarioBusqueda* nodo=arbol.raiz;
            while (nodo!=nullptr) {
                if (nodo->elemento.numero == dato.num) {
                    if (nodo->izquierda!=nullptr) encolar(cola,{nodo->izquierda->elemento.numero});
                   if (nodo->derecha!=nullptr) encolar(cola,{nodo->derecha->elemento.numero});
                    break;
                    cout<<1;
                }
                if (nodo->elemento.numero > dato.num) {
                    nodo=nodo->izquierda;
                }
                if (nodo->elemento.numero < dato.num){
                    nodo=nodo->derecha;
                }
            }
        }else {
            encolar(cola,{arbol.raiz->izquierda->elemento.numero});
            encolar(cola,{arbol.raiz->derecha->elemento.numero});
        }
        i++;
    }


}



int main(){
    ArbolBinarioBusqueda arbol;
    construir(arbol);
    int datos[N]{50,30,70,20,40,60,80,10,25,35,45};
    reconstruirArbol(arbol,datos);
    cout<<endl;
    nuevoRecorrer(arbol);
    return 0;


}
