
Versión del profesor:
```c++
const int N;
const int M;

int [][] matrix;

bool is_valid(x, y) {

}

bool galerias(matrix, x, y, nivel) {
     if (y >= M) {
        galerias(matrix, N - nivel - 1, 0, nivel + 1);
     } else {
     if (is_valid(x + 1, y) && matrix[x + 1][y] == 0) {
             // hacia abajo
             matrix[x + 1][y] = nivel;
             if (galerias(matrix, x + 1, y, nivel)) {
                return true;
             }
             matrix[x + 1][y] = 0;
          } else if (is_valid(x, y + 1) &&  matrix[x][y + 1] == 0) {
             // hacia derecha
             matrix[x][y] = nivel;
             if (galerías(matrix, x, y + 1, nivel)) {
                 return true;
             }
             matrix[x + 1][y] = 0;
          } else if (is_valid(x - 1, y) && matrix[x - 1][y] == 0) {
             // hacia arriba
             matrix[x - 1][y] = nivel;
             if (galerias(matrix, x - 1, y, nivel)) {
                 return true;
             }
             matrix[x - 1][y] = 0;
          }
     }
     return false;
}

galerias(matrix, N - 1, 0, 1)
```

