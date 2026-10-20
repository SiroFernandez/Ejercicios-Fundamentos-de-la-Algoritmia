#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Nombre del alumno Siro Fernandez Garcia
// Usuario del Juez J-10


// función que resuelve el problema
int recursionFinal(int n1, int n2, int total, int d) {
    if (n1 == 0 && n2 == 0)
        return total;

    int dig = (n1 + n2) % 10;
    total += dig * d;
    
    return recursionFinal(n1 / 10, n2 / 10, total, d*10);
}

int recursionNoFinal(int n1, int n2) {
    if (n1 == 0 && n2 == 0)
        return 0;

    return recursionNoFinal(n1 / 10, n2 / 10) * 10 + (n1 + n2) % 10;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n1, n2, total = 0;
    cin >> n1 >> n2;

    int sol1 = recursionFinal(n1, n2, 0, 1);
    int sol2 = recursionNoFinal(n1, n2);

    cout << sol1 << " " << sol2 << "\n";
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