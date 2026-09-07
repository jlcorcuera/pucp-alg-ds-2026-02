
```c++
const int N;  
const int M;  
  
  
int [][] almacen;  
int [][] actualizado;  
  
// action: 1 -> encontrar mayor, 2 -> actualizar matriz  
  
void actualizar(almacen, &actualizado, x, y, &maximo, action) {  
   if (y == M) {  
       y = 0;  
       x = x + 1;  
   }  
   if (x == N) {  
      if (action == 1) {  
          actualizar(almacen, actualizado, 0, 0, maximo, 2);  
      }  
      return;  
   }  
  
   int stock = almacen[x][y];  
   if (action == 1) {  
      maximo = max(maximo, stock);  
      actualizar(almacen, actualizado, x, y + 1, maximo, action);  
   } else {  
      actualizado[x][y] = maximo - stock;  
   }  
}  
int maximo;  
actualizar(almacen, actualizao, 0, 0, maximo, 1);
```