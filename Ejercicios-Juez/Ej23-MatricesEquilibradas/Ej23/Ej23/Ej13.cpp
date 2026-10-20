// Siro Fernandez Garcia
// J-10


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct matriz {
    bool loEs;
    int parcela;
};

// función que resuelve el problema
matriz resolver(const vector<vector<int>>& m, int f, int c, int d) {
    if (d == 1)
        return {true, m[f][c]};

    int mitad = d / 2;

    matriz cuadrante1 = resolver(m, f, c, mitad);
    matriz cuadrante2 = resolver(m, f, c + mitad, mitad);
    matriz cuadrante3 = resolver(m, f + mitad, c, mitad);
    matriz cuadrante4 = resolver(m, f + mitad, c + mitad, mitad);

    if (!cuadrante1.loEs && !cuadrante2.loEs && !cuadrante3.loEs && !cuadrante4.loEs)
        return { false, 0 };

    int total = cuadrante1.parcela + cuadrante2.parcela + cuadrante3.parcela + cuadrante4.parcela;
    if (total < ((d*d)/4 - 1) || total > ((3 * d * d) /4)) {
        return { false, 0 };
    }

    int maximo = max({ cuadrante1.parcela, cuadrante2.parcela, cuadrante3.parcela, cuadrante4.parcela });
    int minimo = min({ cuadrante1.parcela, cuadrante2.parcela, cuadrante3.parcela, cuadrante4.parcela });
    if (maximo - minimo > 2) {
        return { false, 0 };
    }

    return { true, total };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    vector<vector<int>> m(n, vector<int>(n,0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> m[i][j];
        }
    }

    matriz sol = resolver(m, 0, 0, n);
    // escribir sol

    if (sol.loEs)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}