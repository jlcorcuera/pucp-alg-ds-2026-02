
### Listas:

Formas de recorrer una lista.
```c++
Nodo * ptr = // Inicio de una lista
//Como iterar el contenido de una lista:
Nodo * recorrido = ptr;
while(recorrido != nullptr){
	cout << recorrido->dato<<endl;
	recorrido = recorrido->siguiente;
}

//Otra forma
for(Nodo*recorrido = ptr; recorrido != nullptr; recorrido->siguiente){
	cout<<recorrido->dato<<endl;
}

```

Si se tiene por ejemplo una lista de 2->3->7-> nullptr y se quiere eliminar el valor 3 y el siguiente del 2 debe ser el 7 para luego eliminar el 3 por completo de la lista.


### Lista enlazada:

Estructura básica del nodo
```c++
struct Nodo{
	Elemento elemento; //Guarda la estructura de datos int double char etc
	struct Nodo * siguiente; // Puntero a una variable de tipo nodo
}

```
Estructura básica de la lista
```c++
struct Lista{
	struct Nodo * cabeza;
	int longitud;
}
```

Operaciones de las listas:
- Crear la lista
- Esta vacía la lista
- Insertar en la lista
- Eliminar un elemento de la lista
- Tamaño de la lista
- Destruir la lista
- Imprimir la lista}

Lo desafiante en el curso es realizar estas operaciones de manera iterativa

### Ejercicio invertir Listas
```c++
ptr = // Inicio de la lista
Nodo * ptr_resultado = nullptr;
//Para este problema el for no es adecuado ya que se modifica el recorrido
for(Nodo * recorrido = ptr; recorrido != nullptr; recorrido = recorrido->siguiente){
if(ptr_resultado == nullptr){
	ptr_resultado = recorrido;
} else{
	Nodo * inicio_actual = ptr_resultado;
	ptr_resultado = recorrido;
	recorrido->siguiente = inicio_actual;
	}
}

//POr lo que se usa while
Nodo * recorrido_siguiente;

while(recorrido!=nullptr){
if(ptr_resultado == nullptr){
	ptr_resultado = recorrido;
	recorrido = recorrido_siguiente;
} else{
	Nodo * inicio_actual = ptr_resultado;
	ptr_resultadp = recorrido;
	recorrido_siguiente = recorrido_siguiente;
	recorrido->siguiente = inicio_actual;
	recorrido = recorrido_siguiente
	}
}
```

### Listas doblemente enlazadas

Estructura básica del nodo
```c++
struct Nodo{
	Elemento elemento; //Guarda la estructura de datos int double char etc
	struct Nodo * siguiente; // Puntero a una variable de tipo nodo
	struct Nodo * anterior;
}

```
Estructura básica de la lista
```c++
struct Lista{
	struct Nodo * cabeza;
	struct Nodo * cola;
	int longitud;
}
```
