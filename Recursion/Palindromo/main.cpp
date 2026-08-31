#include <cstring>
#include <iostream>
using namespace std;

//Jherove Lopez

// int esPalindromo(const char * palabra, int inicio,int fin) {
//     if (inicio >= fin) return 1;
//     if (palabra[inicio] != palabra[fin]) return 0;
//     return esPalindromo(palabra, inicio+1, fin-1);
// }
//
// int main() {
//     char palabra[] = "MURCIELAGO";
//     int longitud = strlen(palabra);
//     int num = esPalindromo(palabra,0,longitud-1);
//     cout << num << endl;
// }

//Daniel Amao

//
// bool esPalindromos(int izq,int der, char * palabra) {
//     if (izq >= der) return true;
//     if (palabra[izq] != palabra[der]) return false;
//     return esPalindromos(izq+1, der-1, palabra);
// }
//
// int main() {
//     bool esPalindromo;
//     char palabra[] = "LEVEL";
//     esPalindromo = esPalindromos(0,strlen(palabra) - 1,palabra);
//     cout << esPalindromo;
// }
