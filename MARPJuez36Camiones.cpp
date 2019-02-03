#include <iostream>
#include "GrafoValorado.h"
using namespace std;


void camino(GrafoValorado<int> const& g, int v1, int v2, vector<bool> & marcado, int ancho, bool &hayCamino) {
	if (!hayCamino) {
		for (Arista<int> elem : g.ady(v1)) {
			if (ancho <= elem.valor()) {
				if (elem.otro(v1) == v2) hayCamino = true;
				else if (!marcado[elem.otro(v1)]) {
					marcado[elem.otro(v1)] = true;
					camino(g, elem.otro(v1), v2, marcado, ancho, hayCamino);
				}
			}
		}
	}
}


bool resuelveCaso() {
	int v, e;
	cin >> v;
		if (!std::cin) // fin de la entrada
			return false;
	cin >> e;
	int v1, v2, ancho;
	GrafoValorado<int> g(v + 1);
	for (int i = 0; i < e; ++i) {
		cin >> v1 >> v2 >> ancho;
		g.ponArista(Arista<int>(v1, v2, ancho));
	}
	int k;
	cin >> k;
	vector <bool> marcado(v+1);
	bool hayCamino = false;
	for (int j = 0; j < k; ++j) {
		cin >> v1 >> v2 >> ancho;
		hayCamino = false;
		marcado[v1] = true;
		if (v1 == v2) cout << "SI\n";
		else {
			camino(g, v1, v2, marcado, ancho, hayCamino);
			if(hayCamino) cout << "SI\n";
			else cout << "NO\n";
		}
		for (int i = 0; i < v + 1; ++i) marcado[i] = false;
	}


		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}