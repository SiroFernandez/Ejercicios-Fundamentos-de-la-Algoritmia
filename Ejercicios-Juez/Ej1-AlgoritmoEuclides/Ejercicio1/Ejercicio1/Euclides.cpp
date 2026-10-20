#include <iostream>

using namespace std;

int resuelve(const int& a, const int& b) {
	if (b == 0)
		return a;
	else {
		return resuelve(b, a % b);
	}
}

bool resolverCaso() {
	int a, b, sol;
	cin >> a >> b;

	if (a == 0 && b == 0)
		return false;

	sol = resuelve(a, b);

	cout << sol << endl;

	return true;
}

int main() {
	while (resolverCaso()) {
	}

	return 0;
}