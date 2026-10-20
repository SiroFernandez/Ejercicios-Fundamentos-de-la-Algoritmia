// Siro Fernandez Garcia
// J10


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

struct movil {
    int peso;
    bool equilibrado;
};

// función que resuelve el problema
movil resolver() {
    int pd, dd, pi, di;
    cin >> pd >> dd >> pi >> di;

    bool equilibrado = true;

    if (pd == 0) {
        movil derecha = resolver();
        pd = derecha.peso;
        if (!derecha.equilibrado)
            equilibrado = false;
    }
    if (pi == 0) {
        movil izquierda = resolver();
        pi = izquierda.peso;
        if (!izquierda.equilibrado)
            equilibrado = false;
    }

    if (pi * di != pd * dd)
        equilibrado = false;

    return { pd + pi, equilibrado };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada

    bool sol = resolver().equilibrado;
   
    // escribir sol

    if (sol)
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