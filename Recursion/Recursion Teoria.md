Recursión es útil cuando la solución a un problema puede definirse en términos de la solución del mismo problema pero una instancia mas pequeña.

Usando de ejemplo el calculo de un factorial

$$
fact(n)\begin{cases}
n*fact(n-1) & \text{si } n > 0 \\
1 & \text{si } n = 0
\end{cases}
$$

Por ejemplo:

```
fact(3) = 3 * fact(2)
				^
			2 * fact (1)
				^
				1 * fact (0)
					^
					1
```

Ejemplo Fibonacci

$$
fib(n)\begin{cases}
0 & \text{si } n = 1 \\
1 & \text{si } n = 2 \\
fib(n-1)+fib(n-2) & \text{si } n>2
\end{cases}
$$
```
						   fib(5)
				fib(4)                fib(3)
		fib(3)         fib(2)    fib(2)     fib(1)
```
Como en el ejemplo se ve, hay cálculos que se realiza previamente, como es el fib(3) que se repite 2 veces, por lo que hace que se demore mas el tiempo de ejecución.

Tarea: buscar Memorization para resolver esta cuestión como cultura general.

Solución con fuerza bruta.
```c++
long fib[101] = ...
fin[1] = 0, fib[2] = 1;
for(int i = 3, i<101, i++){
	fib[i] = fib[i-1]+fib[i-2];
}
```

El problema de recursividad: Si no controlan bien las llamadas recursivas podrán tener problemas de repetir cálculos. En el curso no se ven temas de performance, pero es bueno que lo sepan

### Ejercicio obtener el mayor

Versión del profesor:
```
int main() {  
    int mayor = -1;  
    mayor = maximo(num,0,mayor);  
    
}

int mayor(int[]num,int posicion,int mayor) {  
        if (posicion == N)  
            return mayor;  
        return mayor(num,posicion +1,max(mayor,num[posicion]));  
    }  
```

Versión del delegado
```
#include <iostream>  
#include <iomanip>  
  
using namespace std;  
  
void encontrarMayor(int numeros[],int & mayorTemp,int  i) {  
    if (i > 9) return;  
    if (mayorTemp < numeros[i]) {  
        mayorTemp = numeros[i];  
        i = i + 1;  
        encontrarMayor(numeros,mayorTemp,i);  
    }  
    i = i+1;  
    encontrarMayor(numeros,mayorTemp,i);  
}  
  
int main() {  
    int numeros[10] {4,5,1,2,10,9,11,0,3,8};  
    int mayorTemp = numeros[0], i = 1;  
    encontrarMayor(numeros,mayorTemp,1);  
    cout << mayorTemp << endl;  
    return 0;  
}
```

### Ejercicio encontrar numero

Ejercicio de Jack Mendoza
```
int num = 3;
int arrNum[10] = {...}
int indice = encontrarNum(arrNum,q,num);

int encontrarNum(int[] arrNum, int pos, int numBus){
	if(pos<0) return -1;
	if(arrNum[pos] == numPos) returnPos;
	return encontrarNUm(arrNum,pos--,numBus);	
}
```

### Ejercicio base 10 a base 2

Ejercicio de Gian Lucas Betetta
```
#include <iostream>  
using namespace std;  
  
    void conversionBinario(int n) {  
        if (n == 0) return;  
        conversionBinario(n / 2);  
        cout<<n%2<<" ";  
    }  
  
int main() {  
    int n = 10;  
    conversionBinario(n);  
}

// conversionBinario(5) 10/2
// conversionBinario(2) 2/2
// conversionBinario(1) 1/2
// conversionBinario(0) 0/2
```

