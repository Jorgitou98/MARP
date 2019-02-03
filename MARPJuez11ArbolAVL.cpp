#include <iostream>
#include <algorithm>
#include "bintree_eda.h"
using namespace std;

// Coste lineal en el numero de nodos del arbol
void equilibrado(bintree<int> const& arbol, bool & eq, int & alt, int & minimo, int & maximo, bool & avl) {
	if (arbol.empty()) {
		alt = 0;
		eq = true;
		avl = true;
	}
	else {
		int altI, altD, minimoI, minimoD, maximoI, maximoD;
		bool eqI, eqD, avlI, avlD;
		if (!arbol.left().empty() && !arbol.right().empty()) {
			equilibrado(arbol.left(), eqI, altI, minimoI, maximoI, avlI);
			equilibrado(arbol.right(), eqD, altD, minimoD, maximoD, avlD);
			eq = (abs(altI - altD) <= 1) && eqI && eqD;
			alt = max(altI, altD) + 1;
			minimo = minimoI;
			maximo = maximoD;
			avl = (maximoI < arbol.root()) && (minimoD > arbol.root()) && avlI && avlD && eq;
		}
		else if (!arbol.left().empty()) {
			equilibrado(arbol.left(), eqI, altI, minimoI, maximoI, avlI);
			eq = altI <= 1 && eqI;
			alt = altI + 1;
			minimo = minimoI;
			maximo = arbol.root();
			avl = (maximoI < arbol.root()) && avlI && eq;
		}
		else if (!arbol.right().empty()) {
			equilibrado(arbol.right(), eqD, altD, minimoD, maximoD, avlD);
			eq = altD <= 1 && eqD;
			alt = altD + 1;
			minimo = arbol.root();
			maximo = maximoD;
			avl = (minimoD > arbol.root()) && avlD && eq;
		}
		else {
			eq = true;
			alt = 1;
			minimo = arbol.root();
			maximo = arbol.root();
			avl = true;
		}
	}
}

void resuelveCaso() {
	bintree <int> arbol = leerArbol(-1);
	int alt, maximo, minimo;
	bool eq, avl;
	equilibrado(arbol, eq, alt, minimo, maximo, avl);
	if (avl) cout << "SI \n";
	else cout << "NO \n";
	
}
int main() {
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
