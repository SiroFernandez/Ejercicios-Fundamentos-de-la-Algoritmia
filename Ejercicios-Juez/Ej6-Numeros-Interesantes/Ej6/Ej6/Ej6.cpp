#include <iostream>
#include <iomanip>
#include <fstream>

//SIRO FERNANDEZ GARCIA
//J-10

using namespace std;

// función que resuelve el problema
pair<bool, int> resolver(int n, int derecha) {
    if (n == 0) {
        return { true, 0 };
    }

    int digito = n % 10;

    if (digito == 0)
        return {false, 0};

    bool divideDercha = (derecha % digito == 0);

    pair<bool, int> recorre = resolver(n / 10, derecha + digito);

    bool divideIzqda = (recorre.second % digito == 0);
    recorre.second += digito;

    return {divideDercha && divideIzqda && recorre.first, recorre.second};
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int n;
    cin >> n;

    pair<bool, int> sol = resolver(n, 0);
    // escribir sol

    if (sol.first)
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