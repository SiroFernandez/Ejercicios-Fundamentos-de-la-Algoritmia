// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// función que resuelve el problema
int digitos(int datos) {
    int digit = 0;
    if (datos == 0)
        return 1;
    while (datos > 0) {
        datos = datos / 10;
        digit++;
    }
    return digit;
}

bool resolver(int datos, int digit, int &suma) {
    if (datos < 10) {
        suma = datos;
        return true;
    }

    bool loEs = resolver(datos / 10, digit - 1, suma);
    suma += (datos % 10);

    if (!loEs)
        return false;

    return(suma % digit == 0);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int n, suma = 0;
    cin >> n;
    if (n == 0)
        return false;

    int digit = digitos(n);
    bool sol = resolver(n, digit, suma);

    // escribir sol

    if (sol)
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
