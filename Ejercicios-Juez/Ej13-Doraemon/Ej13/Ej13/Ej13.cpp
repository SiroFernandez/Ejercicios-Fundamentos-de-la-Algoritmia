//SIRO FERNANDEZ GARCIA
//J-10

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct sol {
    bool hablan;
    int v1, v2;
};

// función que resuelve el problema
sol resolver(const vector<int>& v1, const vector<int>& v2, int ini, int fin) {
    if (ini + 1 == fin) {
        if (v1[ini] == v2[ini])
            return { true, v1[ini], 0 };
        
        if (v1[fin] == v2[fin])
            return{ true, v1[fin] , 0 };

        return { false, v1[ini], v1[fin]};
    }

    int mitad = (ini + fin) / 2;

    if (v1[mitad] == v2[mitad])
        return { true, v1[mitad], 0};

    else if (v1[mitad] < v2[mitad])
        return resolver(v1, v2, mitad, fin);

    else
        return resolver(v1, v2, ini, mitad);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;

    cin >> n;

    if (n == 0)
        return false;

    vector<int> v1(n);
    vector<int> v2(n);

    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }
    for (int j = 0; j < n; j++) {
        cin >> v2[j];
    }

    sol solucion = resolver(v1, v2, 0, n - 1);

    if (solucion.hablan == true)
        cout << "HABLAN " << solucion.v1 << endl;
    else
        cout << "SE CRUZAN " << solucion.v1 << " " << solucion.v2 << endl;
    
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
