// Siro Fernandez Garcia
// J10

//El vector solucion es un vector de tamaño n con valores binarios, 1 si sí montamos, 0 si no 
//La altura del árbol es de n niveles ya que tomamos una decisión por cada atraccion
//En el nivel k guardamos el tiempo gastado, la satisfacción, y el recuento de atracciones que mojan y que salpican
//En la estimacion ordenamos las atracciones por rentabilidad, en cada ndo se estima la satisfcacion maxima, si no la supera, podamos

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Actividades {
    string nombre;
    int dura;
    int satisfaccion;
    int acuatico;
};

struct tDatos {
    int num;
    int tiempo;
    vector<Actividades> actividades;
};

class Comparador {
public:
    bool operator()(const Actividades& p1, const Actividades& p2) {
        return p1.satisfaccion * p2.dura > p2.satisfaccion * p1.dura;
    }
};

int estimar(tDatos const& datos, int k, int tiempo) {
    int estimacion = 0;
    int i = k;

    while (i < datos.num && tiempo > 0) {
        if (datos.actividades[i].dura <= tiempo) {
            estimacion += datos.actividades[i].satisfaccion;
            tiempo -= datos.actividades[i].dura;
        }
        else {
            estimacion += (datos.actividades[i].satisfaccion * tiempo) / datos.actividades[i].dura;
            tiempo = 0;
        }
        ++i;
    }

    return estimacion;
}

void resolver(const tDatos& datos, int k, int tiempo, int satisfaccion, int moja, int salpica, int& maxS) {
    if (k == datos.num) {
        if (moja <= salpica && satisfaccion > 0) {
            if (satisfaccion > maxS) {
                maxS = satisfaccion;
            }
        }
        return;
    }

    int estimacion = estimar(datos, k, datos.tiempo - tiempo);
    if (satisfaccion + estimacion <= maxS) {
        return;
    }

    if (tiempo + datos.actividades[k].dura <= datos.tiempo) {
        int mojaNuevo = moja;
        int salpicaNuevo = salpica;

        if (datos.actividades[k].acuatico == 1) {
            mojaNuevo++;
        }
        else {
            salpicaNuevo++;
        }

        resolver(datos, k + 1, tiempo + datos.actividades[k].dura,
            satisfaccion + datos.actividades[k].satisfaccion, mojaNuevo, salpicaNuevo, maxS);
    }

    resolver(datos, k + 1, tiempo, satisfaccion, moja, salpica, maxS);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    tDatos datos;
    int n, tiempo;
    cin >> n >> tiempo;
    if (n == 0 && tiempo == 0)
        return false;

    datos.num = n;
    datos.tiempo = tiempo;

    datos.actividades.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> datos.actividades[i].nombre >> datos.actividades[i].dura >> datos.actividades[i].satisfaccion >> datos.actividades[i].acuatico;
    }

    sort(datos.actividades.begin(), datos.actividades.end(), Comparador());

    int maxS = 0;
    resolver(datos, 0, 0, 0, 0, 0, maxS);

    if (maxS == 0) {
        cout << "NINGUNA\n";
    }
    else {
        cout << maxS << "\n";
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