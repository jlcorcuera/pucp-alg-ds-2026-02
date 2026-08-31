Desarrollar una función recursiva que data una coordenada de la matriz, calcule la suma de la cruz teniendo dicha coordenada como centro.

| 5   | 31  | 5     | 111 | 120 | 131 |
| --- | --- | ----- | --- | --- | --- |
| 20  | 8   | 8     | 51  | 41  | 151 |
| 15  | 10  | ==9== | -1  | -2  | 161 |
| 10  | 9   | 20    | 18  | 0   | 21  |
| 15  | 14  | 13    | 10  | 11  | 19  |



(n,m), desde el punto que esta marcado aplicar Sumacruz
Direcciones:
- 1 es arriba
- 2 es derecha
- 3 es abajo
- 4 es izquierda

``` c++
int main{
	matriz[][] {...} // Lo que esta arriba
	sumaCruz(matriz,x,y,0);
}
int sumaCruz(int [][]matriz, int x, int y, int direccion){
	if(x < 0 or x > N or y > M or y < 0){
		return 0;
	}	
	if(dirección == 1){
		return matriz[x][y] + sumaCruz(matriz,x-1,y,1);	
	} else if(dirección == 2){
		return matriz[x][y] + sumaCruz(matriz,x,y+1,2);	
	} else if(dirección == 3){
		return matriz[x][y] + sumaCruz(matriz,x+1,y,3);	
	} else if(dirección == 4){
		return matriz[x][y] + sumaCruz(matriz,x,y-1,4);	
	}
	return matriz[x][y] + sumaCruz(matriz,x-1,y,1) + sumacruz(matriz,x+1,y,3)
			+sumaCruz(matriz,x,y+1,2) + sumaCruz(matriz,x,y-1,4)
}
```
