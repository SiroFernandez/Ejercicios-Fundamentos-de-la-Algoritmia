// Siro Fernandez Garcia
// J-10

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

// función que resuelve el problema
int resolver(const vector<int>& p, const int& leere) {
    int empieza = 0, sumaPunts = 0, maxPunts = 0, mejor = 0;

    for (int i = 0; i < leere; i++) {
        sumaPunts += p[i];
    }

    maxPunts = sumaPunts;

    for (int i = leere; i < p.size(); i++) {
        sumaPunts = sumaPunts + p[i] - p[i - leere];

        if (sumaPunts >= maxPunts) {
            maxPunts = sumaPunts;
            mejor = i - leere + 1;
        }
    }

    return mejor;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int paginas, nLeere;
    cin >> paginas >> nLeere;
    if (paginas == 0 && nLeere == 0)
        return false;

    vector<int> puntuaciones(paginas);

    for (int i = 0; i < paginas; i++) {
        cin >> puntuaciones[i];
    }

    int sol = resolver(puntuaciones, nLeere);

    // escribir sol
    cout << sol << "\n";

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