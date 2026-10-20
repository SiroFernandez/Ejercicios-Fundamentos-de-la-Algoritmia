// Siro Fernández García
// J-10

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

struct degradado {
    bool loEs;
    int suma;
};

// función que resuelve el problema
degradado resolver(const vector<int>&m, int ini, int fin) {
    if (ini == fin) {
        return { true, m[ini] };
    }

    int mitad = (ini + fin) / 2;
    degradado degIzqda = resolver(m, ini, mitad);
    degradado degDrcha = resolver(m, mitad + 1, fin);

    bool sigue = degIzqda.loEs && degDrcha.loEs && (degIzqda.suma < degDrcha.suma);
    int total = degIzqda.suma + degDrcha.suma;

    return { sigue, total };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int fila, col;
    bool loEs = true;

    if (!(cin>>fila>>col))
        return false;

    vector<int> m(col);

    for (int i = 0; i < fila; i++) {
        for (int j = 0; j < col; j++) {
            cin >> m[j];
        }
        if (loEs) {
            if (!resolver(m, 0, col - 1).loEs)
                loEs = false;
        }
    }

    // escribir sol
    if (loEs)
        cout << "SI" << endl;
    else
        cout << "NO" << endl;

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