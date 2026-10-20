#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

//SIRO FERNANDEZ GARCIA

// función que resuelve el problema
long long int resolverFinal(long long int d, long long int num, long long int digito) {
    if (d == 0)
        return num;

    if ((d % 10) % 2 != 0) {
        return resolverFinal(d / 10, num + (d % 10) * digito, digito * 10);
    }

    return resolverFinal(d / 10, num, digito);
}

long long int resolverNoFinal(long long int d) {
    if (d == 0)
        return 0;

    long long num = resolverNoFinal(d / 10);

    if ((d % 10) % 2 != 0)
        return num * 10 + (d % 10);

    return num;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long long int d;
    cin >> d;

    if (!std::cin)
        return false;

    long long int sol1 = resolverFinal(d, 0, 1);
    long long int sol2 = resolverNoFinal(d);

    // escribir sol
    cout << sol1 << " " << sol2 << endl;

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