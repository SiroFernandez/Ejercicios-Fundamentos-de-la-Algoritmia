// Siro Fernandez Garcia
// J-10

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct Edificio{
    string id;
    int altura;
    int alturaMax;
};

// función que resuelve el problema
vector<string> resolver(const vector<Edificio>& edificios) {
    vector<string> sol;
    int max = 0;

    for (int i = edificios.size() - 1; i >= 0; i--) {
        if (edificios[i].alturaMax > max)
            sol.push_back(edificios[i].id);
        if (edificios[i].altura > max)
            max = edificios[i].altura;
    }

    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;
    if (n == 0)
        return false;

    vector<Edificio> edificios(n);

    for (int i = 0; i < n; i++) {
        cin >> edificios[i].id >> edificios[i].altura >> edificios[i].alturaMax;
    }

    vector<string> sol = resolver(edificios);

    // escribir sol
    if (sol.empty())
        cout << "Ninguno" << "\n";
    else {
        cout << sol.size();
        cout << "\n";
        for (int i = 0; i < sol.size(); i++) {
            cout << sol[i];
            if (i < sol.size() - 1)
                cout << " ";
        }
        cout << "\n";
    }

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