#include <iostream>

using namespace std;

int sumaDigitos(int n){
	if (n == 0)
		return 0;

	return ((n % 10) + sumaDigitos(n / 10));
}

void resuelveCaso() {
	int nElem, n;

	cin >> nElem >> n;

	int suma = sumaDigitos(n);

	for (int i = 0; i < nElem; i++) {
		int elem;
		cin >> elem;

		if (suma == sumaDigitos(elem))
			cout << elem << " ";
	}

	cout << endl;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		resuelveCaso();
	}

	return 0;
}