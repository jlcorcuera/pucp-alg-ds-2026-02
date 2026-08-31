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

