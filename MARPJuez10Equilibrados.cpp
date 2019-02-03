#include <iostream>
#include <algorithm>
#include "bintree_eda.h"
using namespace std;

// Coste lineal en el numero de nodos del arbol
void equilibrado(bintree<char> const& arbol, bool & eq, int & alt) {
	if (arbol.empty()) {
		alt = 0;
		eq = true;
	}
	else {
		int altI, altD;
		bool eqI, eqD;
		equilibrado(arbol.left(), eqI, altI);
		equilibrado(arbol.right(), eqD, altD);
		eq = (abs(altI - altD) <= 1) && eqI & eqD;
		alt = max(altI, altD) + 1;
	}
}

void resuelveCaso() {
	bintree <char> arbol = leerArbol('.');
	bool eq;
	int alt;
	equilibrado(arbol, eq, alt);
	if (eq) cout << "SI \n";
	else cout << "NO \n";
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
