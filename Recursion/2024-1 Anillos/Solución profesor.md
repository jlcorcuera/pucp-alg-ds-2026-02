Recursividad, problema de los anillos:
Matriz de como van las coordenadas
```
(x-2,y-2)(x-2,y-1)(x-2,y) (x-2,y+1)(x-2,y+2)
(x-1,y-2)(x-1,y-1)(x-1,y) (x-1,y+1)(x-1,y+2)
 (x,y-2)  (x,y-1)  (x,y)   (x,y+1)  (x,y+2)
(x+1,y-2)(x+1,y-1)(x+1,y) (x+1,y+1)(x+1,y+2)
(x+1,y-2)(x+2,y-1)(x+2,y) (x+2,y+1)(x+2,y+2)
```

```c++
const int N;
const int M;

int unos = buscar(matriz,x,y,0);

bool posicion_valida(x,y){
	return x>=0 && x<N && y >=0 && y < M;
}

int buscar(matiz,x,y){
	if(radio==0){
		return (matriz[x][y] == 1) + buscar(matriz,x,y,radio+1);
	}
	int contador_unos = 0;
	bool radio_valido = true;
	//horizontal arriba
	int x_horizontal_arriba = x - radio;
	for(int offset = -1*radio; offset <= radio; offset++){
		int x_offset = x_horizontal_arriba;
		int y_offset = y - offset;
		if(posicion_valida(x_offset,y_offset)){
			contador_unos += matriz[x][y] == 1;
		} else{
			return 0;
		}
	}
	
	//horizontal abajo
	//vertical derecha
	int y_vertical_derecha = y + radio;
	for(int offset = -1*(radio-1); offset <= (radio-1); offset++){
		int x_offset = x + offset;
		int y_offset = y_vertical_derecha;
		if(posicion_valida(x_offset,y_offset)){
			contador_unos += matriz[x][y] == 1;
		} else{
			return 0;
		}
	}
	//vertical izquierda
	
	return contador_unos + buscar(matriz,x,y,radio+1);
}
```