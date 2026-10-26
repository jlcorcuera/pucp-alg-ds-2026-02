#include <iostream>
using namespace std;

int CalcularMaxMitad(int arr[], int left, int mid, int right) {
    int suma=0;
    int max_izq = -99999999;
    int max_der = -99999999;

    for (int i = mid; i >= left; i--) {
        suma = suma + arr[i];
        if (suma > max_izq) {
            max_izq = suma;
        }
    }
    suma = 0;
    for (int i = mid+1; i <= right; i++) {
        suma = suma + arr[i];
        if (suma > max_der) {
            max_der = suma;
        }
    }

    return max_izq + max_der;
}

int solve(int arr[], int left, int right) {
    if (left == right) return arr[left];
    int mid = (left + right) / 2;

    int max_izq = solve(arr, left, mid);
    int max_der = solve(arr, mid + 1, right);
    int max_mitad = CalcularMaxMitad(arr, left, mid, right);

    return max(max_izq, max(max_der, max_mitad));

}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr)/sizeof(arr[0]);

    int mayor_suma = solve(arr, 0, n-1);
    cout << mayor_suma << endl;

    return 0;
}