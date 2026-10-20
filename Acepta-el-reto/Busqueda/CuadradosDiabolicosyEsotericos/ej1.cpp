#include <iostream>
#include <vector>

using namespace std;

// Fase 1: Comprobar filas, columnas y diagonales
bool esDiabolico(const vector<vector<int>>& matriz, int n, int& cm) {
    // 1. Calcula la Constante Mágica (cm) sumando la primera fila
    cm = 0;
    for (int j = 0; j < n; j++)
        cm += matriz[0][j];

    // 2. Comprueba que TODAS las demás filas sumen 'cm'
    for (int i = 1; i < n; ++i) { // Empezamos en la fila 1 (la 0 ya es la de 'cm')
        int sumaFila = 0;         // Reseteamos la suma para cada fila
        for (int j = 0; j < n; ++j) {
            sumaFila += matriz[i][j];
        }
        if (sumaFila != cm) {
            return false; // Si esta fila ya no cuadra, paramos todo
        }
    }

    // 3. Comprueba que TODAS las columnas sumen 'cm'
    for (int i = 0; i < n; ++i) { 
        int sumaCol = 0;        
        for (int j = 0; j < n; ++j) {
            sumaCol += matriz[j][i];
        }
        if (sumaCol != cm) {
            return false; 
        }
    }

    // 4. Comprueba que la diagonal principal sume 'cm'
    int sumaDiagPrin = 0;
    for (int i = 0; i < n; ++i) {
        sumaDiagPrin += matriz[i][i];
    }
    if (sumaDiagPrin != cm) return false;

    // 5. Comprueba que la diagonal secundaria sume 'cm'
    int sumaDiagSec = 0;
    for (int i = 0; i < n; ++i) {
        sumaDiagSec += matriz[i][n - 1 - i]; // Ojo al -1
    }
    if (sumaDiagSec != cm) return false;

    // Si algo falla, return false. Si todo cuadra, return true.
    return true;
}

bool tieneTodosLosNumeros(const vector<vector<int>>& matriz, int n) {
    int maxNum = n * n;
    vector<bool> vistos(maxNum + 1, false);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int num = matriz[i][j];

            // 1. Comprueba si 'num' es menor que 1 o mayor que maxNum (fuera de rango)
            if (num < 1 || num > maxNum) return false;

            // 2. Comprueba si ya lo habíamos visto (número repetido)
            if (vistos[num]) return false;

            // 3. Si es un número válido y nuevo, márcalo como visto en el vector
            vistos[num] = true;
        }
    }
    return true; // Si termina los bucles sin fallar, es que están todos perfectos
}

bool esEsoterico(const vector<vector<int>>& matriz, int n, int cm) {
    // 1. Comprobamos que tiene todos los números del 1 al n^2
    if (!tieneTodosLosNumeros(matriz, n)) return false;

    // 2. Calculamos CM2
    int cm2 = (4 * cm) / n;

    // 3. Esquinas
    int esquinas = matriz[0][0] + matriz[0][n - 1] + matriz[n - 1][0] + matriz[n - 1][n - 1];
    if (esquinas != cm2) return false;

    // 4. Dependiendo de si es par o impar
    int mitad = n / 2;

    if (n % 2 != 0) { // Si 'n' es IMPAR
        // A) Multiplicar el valor de la casilla central por 4
        if (matriz[mitad][mitad] * 4 != cm2) return false;

        // B) Sumar los 4 centros de los laterales
        int centrosLaterales = matriz[0][mitad] + matriz[n - 1][mitad] +
            matriz[mitad][0] + matriz[mitad][n - 1];
        if (centrosLaterales != cm2) return false;

    }
    else { // Si 'n' es PAR
        // A) La suma de las cuatro casillas centrales
        int centro = matriz[mitad - 1][mitad - 1] + matriz[mitad - 1][mitad] +
            matriz[mitad][mitad - 1] + matriz[mitad][mitad];
        if (centro != cm2) return false;

        // B) La suma de las dos casillas centrales de los cuatro laterales
        int latArriba = matriz[0][mitad - 1] + matriz[0][mitad];
        int latAbajo = matriz[n - 1][mitad - 1] + matriz[n - 1][mitad];
        int latIzq = matriz[mitad - 1][0] + matriz[mitad][0];
        int latDer = matriz[mitad - 1][n - 1] + matriz[mitad][n - 1];

        if ((latArriba + latAbajo + latIzq + latDer) != 2 * cm2) return false;
    }

    return true;
}

bool resuelveCaso() {
    int n;
    cin >> n;
    if (n == 0) return false;

    vector<vector<int>> matriz(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matriz[i][j];
        }
    }

    int cm = 0;
    if (!esDiabolico(matriz, n, cm)) {
        cout << "NO\n";
    }
    else if (esEsoterico(matriz, n, cm)) {
        cout << "ESOTERICO\n";
    }
    else {
        cout << "DIABOLICO\n";
    }

    return true;
}

int main() {
    while (resuelveCaso());
    return 0;
}