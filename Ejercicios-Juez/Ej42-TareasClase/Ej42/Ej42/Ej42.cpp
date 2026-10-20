//Siro Fernandez Garcia
//FAL-J10

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//*******************************
// Aqui explicacion del algoritmo de vuelta atras. Como es el vector solucion y como se obtiene
// El vector solucion utilizado es un vector de tamñao n*2, donde se guardan los dos alumnos asignados a una misma tarea
// La profunddad maxima del arbol tambien es n*2 niveles
//*******************************

template <class T>
using tMatriz = std::vector<std::vector<T>>;

struct tDatos {
    int numTareas; // Numero de tareas a realizar
    int numAlumnos;  // Numero de alumnos de la clase
    int maxTareas;   // maximo numero de tareas que puede realizar un alumno
    tMatriz<int> preferencias;  // En cada fila las preferencias de cada alumno a cada tarea
};

// Aqui las funciones implementadas por el alumno

void resolver(const tDatos& datos, int k, int pref, int& maxPref, vector<int>& sol, vector<int>& tareas) {
    //Caso base
    if (k == datos.numTareas * 2) {
        if (pref >= maxPref)
            maxPref = pref;
        return;
    }

    //Caso recursivo
    int tareaAsig = k / 2;
    int alumnoIni = 0;

    if(k%2 == 1)
        alumnoIni = sol[k - 1] + 1;


    for (int i = alumnoIni; i < datos.numAlumnos; ++i) {
        if (tareas[i] < datos.maxTareas) {
            //Marcar
            sol[k] = i;
            tareas[i]++;

            resolver(datos, k + 1, pref + datos.preferencias[i][tareaAsig], maxPref, sol, tareas);

            //Desmarcar
            tareas[i]--;
        }
    }
}



bool resuelveCaso() {
    // Lectura de los datos de entrada
    tDatos d;
    std::cin >> d.numTareas >> d.numAlumnos >> d.maxTareas;
    if (d.numTareas == 0 && d.numAlumnos == 0 && d.maxTareas == 0) return false;
    // lectura de las preferencias
    d.preferencias.resize(d.numAlumnos, std::vector<int>(d.numTareas));
    for (int i = 0; i < d.numAlumnos; ++i)
        for (int j = 0; j < d.numTareas; ++j)
            std::cin >> d.preferencias[i][j];

    // preparar datos para la llamada a la funcion de VA
    vector<int> sol(2 * d.numTareas);
    vector<int> tareas(d.numAlumnos, 0);
    int maxPref = 0;

    // LLamada a la funcion de VA
    resolver(d, 0, 0, maxPref, sol, tareas);

    // Escribir solucion
    cout << maxPref << endl;

    return true;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

    // Para restablecer entrada. 
#ifndef DOMJUDGE 
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}