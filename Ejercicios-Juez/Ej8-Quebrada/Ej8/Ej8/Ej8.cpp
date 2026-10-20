//Siro Fernandez Garcia
//J-10

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

int resolverFinal(vector<int>& altura, int ini, int fin, int min) {
    if (ini > fin)
        return 0;

    if (altura[ini] == min && altura[fin] == min)
        return fin - ini + 1;

    int mitad = (ini + fin) / 2;

    if (altura[mitad] > min && altura[ini] > altura[mitad])
        return resolverFinal(altura, mitad + 1, fin, min);

    if (mitad + 1 <= fin && altura[mitad+1] > min && altura[fin] > altura[mitad+1])
        return resolverFinal(altura, ini, mitad, min);

    return resolverFinal(altura, mitad + 1, fin, min) + resolverFinal(altura, ini, mitad, min);
}

// función que resuelve el problema
int resolverMin(vector<int>& altura, int ini, int fin) {
    if (ini > fin)
        return 0;

    if (ini == fin)
        return altura[ini];

    int mitad = (ini + fin) / 2;

    if (mitad + 1 <= fin && altura[mitad] > altura[mitad + 1])
        return resolverMin(altura, mitad + 1, fin);

    else
        return resolverMin(altura, ini, mitad);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, sol, min;
    cin >> n;
    if (n == -1)
        return false;
    else if (n == 0) {
        cout << 0 << endl;
        return true;
    }

    vector<int> altura(n);
    for (int i = 0; i < n; i++) {
        cin >> altura[i];
    }

    min = resolverMin(altura, 0, n - 1);
    sol = resolverFinal(altura, 0, n-1, min);
    // escribir sol
    cout << sol << endl;

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
