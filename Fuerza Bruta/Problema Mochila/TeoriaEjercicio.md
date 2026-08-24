Fuerza bruta: Usar todas las posibles combinaciones
Lab de sabado dirigido: se veran matricez



Problema de la mochila:
Error común: El problema es que `combinación` es **la misma variable** que usa el `for` externo para controlar cuántas veces se repite el bucle grande. Al hacer `combinación = combinación / 2` dentro del bucle interno, estás destruyendo el valor que el `for` externo, el cual hace que pueda quedar en bucle infinito
```
for(combinación = 0; combinación <= fin; combinación ++){
	for(i=0; i<productos;i++){
		incluir = combinación % 2;
		combincación = combinación/2; // Mucho cuidado aca que estas modificando 
		el valor y no saldra del bucle
	}
}
```
Solución: Usar una variable temporal. Al copiar el valor a `tmp` antes de entrar al bucle interno, todas las divisiones y operaciones "destructivas" se hacen sobre `tmp`, dejando intacta la variable `combinación` que el `for` externo necesita para funcionar correctamente.
```
for(combinación = 0; combinación <= fin; combinación ++){
	tmp = combinación;
	for(i=0; i<productos;i++){
		incluir = tmp % 2;
		tmp = tmp/2;
	}
}
```


Iterar cada solución
Suma de pesos de productos seleccionados

