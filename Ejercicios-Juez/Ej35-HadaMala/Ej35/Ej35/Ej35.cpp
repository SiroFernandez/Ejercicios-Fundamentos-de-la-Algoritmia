// Siro Fernandez Garcia
// J-10


//Vector solucion -> sol = (x0, x1, ..., x{m-1}) de tamaño m
//Arbol de Exploracion -> profundidad de m niveles, en cada nodo del nivel k, se abren hasta n ramas

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct TipoDatos {
    int n;
    int m;
    int h;
    vector<vector<int>> satisfaccion;
};

struct TipoSolucion {
    int maxS;
    int n;
};

void resolver(const TipoDatos& datos, int k, int actualS, int supersticiones, bool incluida, vector<bool>& usado, const vector<int>& maxF, TipoSolucion& sol) {

    int max_restante = 0;
    for (int i = k; i < datos.m; ++i) {
        max_restante += maxF[i];
    }
    if (actualS + max_restante < sol.maxS) {
        return;
    }

    if (k == datos.m) {
        if (incluida) {
            if (actualS > sol.maxS) {
                sol.maxS = actualS;
                sol.n = 1;
            }
            else if (actualS == sol.maxS) {
                sol.n++;
            }
        }
        return;
    }

    for (int p = 0; p < datos.n; ++p) {
        if (!usado[p] && datos.satisfaccion[k][p] >= 0) {

            int nueva_supersticion = supersticiones;
            if (k == p) nueva_supersticion++;

            if (nueva_supersticion <= datos.m / 3) {
                usado[p] = true;
                bool nueva_hada_incluida = incluida || (p == datos.h);

                resolver(datos, k + 1, actualS + datos.satisfaccion[k][p],
                    nueva_supersticion, nueva_hada_incluida,
                    usado, maxF, sol);

                usado[p] = false;
            }
        }
    }
}


TipoSolucion resolverSol(const TipoDatos& datos) {
    TipoSolucion sol = { -1, 0 };
    vector<bool> usado(datos.n, false);
    vector<int> maxF(datos.m, 0);

    for (int i = 0; i < datos.m; ++i) {
        int max_fila = -1;
        for (int j = 0; j < datos.n; ++j) {
            max_fila = max(max_fila, datos.satisfaccion[i][j]);
        }
        maxF[i] = max_fila;
    }

    resolver(datos, 0, 0, 0, false, usado, maxF, sol);

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    TipoDatos datos;
    cin >> datos.n >> datos.m >> datos.h;
    if (datos.n == 0)
        return false;

    datos.satisfaccion.assign(datos.m, vector<int>(datos.n));
    for (int i = 0; i < datos.m; ++i) {
        for (int j = 0; j < datos.n; ++j) {
            cin >> datos.satisfaccion[i][j];
        }
    }

    TipoSolucion sol = resolverSol(datos);

    if (sol.n == 0) {
        cout << "NO\n";
    }
    else {
        cout << sol.maxS << " " << sol.n << "\n";
    }

    return true;

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