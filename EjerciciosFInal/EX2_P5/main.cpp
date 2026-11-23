#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Elemento {
    string español;
    string english;
    string french;
    string portugues;
};
struct NodoArbol {
    Elemento elemento;
    NodoArbol* der;
    NodoArbol* izq;
};

struct Arbol {
    NodoArbol* raiz;
};

void construirArbol(Arbol &arbol) {
    arbol.raiz = nullptr;
}

NodoArbol *construirNodo(Elemento elemento) {
    NodoArbol *nodo = new NodoArbol;
    nodo->elemento = elemento;
    nodo->der = nullptr;
    nodo->izq = nullptr;
    return nodo;
}

void insertar(NodoArbol *&raiz, Elemento elemento) {

    if (raiz == nullptr) {
        raiz = construirNodo(elemento);
    }

    if (raiz->elemento.español < elemento.español) {
        insertar(raiz->der, elemento);
    }

    if (raiz->elemento.español > elemento.español) {
        insertar(raiz->izq, elemento);
    }
}

void procesarPalabra (string &palabra, int n) {
    for (int i = 0; i < n; i++) {
        if (palabra[i] > 'A' && palabra[i] < 'Z') {
            palabra[i] = palabra[i]-'A'+'a';
        }
    }
}

bool verficar(string palabra, NodoArbol *&raiz, int tamaño) {
    if (tamaño <0) {
        return true;
    }
    if (palabra[tamaño] == raiz->elemento.español[tamaño] ) {
        return verficar(palabra, raiz, tamaño-1);
    }
    return false;
}

void buscar(NodoArbol *&raiz, string palabra) {
    if (raiz == nullptr) {
        return;
    }
    int tamaño = palabra.size();
    buscar(raiz->der, palabra);
    buscar(raiz->izq, palabra);
    if (verficar(palabra, raiz, tamaño-1)) {
        cout << raiz->elemento.español << " -> "
             << raiz->elemento.english << " | "
             << raiz->elemento.french << " | "
             << raiz->elemento.portugues <<endl;
    }
}
int main() {
    ifstream archESP ("spanish.txt");
    ifstream archING ("english.txt");
    ifstream archFCH ("french.txt");
    ifstream archPOR ("portuguese.txt");
    Arbol arbol;
    construirArbol(arbol);

    string palabraESP, palabraING, palabraFCH, palabraPOR;

    while (true) {
        archESP >> palabraESP;
        archING >> palabraING;
        archFCH >> palabraFCH;
        archPOR >> palabraPOR;
        if (archESP.eof()) break;
        Elemento elemento;
        elemento.español = palabraESP;
        elemento.english = palabraING;
        elemento.french = palabraFCH;
        elemento.portugues = palabraPOR;
        insertar(arbol.raiz, elemento);

    }

    string palabra = {'C','a','m'};
    int tamaño = palabra.size();
    procesarPalabra (palabra, tamaño);
    buscar(arbol.raiz, palabra);
    return 0;
}