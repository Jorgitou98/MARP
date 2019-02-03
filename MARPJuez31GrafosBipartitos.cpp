#include <iostream>
#include "Grafo.h"

using namespace std;

void recorreEnProfundidad(vector<char> & color, Grafo const& g, bool &bipartito, int inicio, char proximoColor) {
	if (bipartito) {
		color[inicio] = proximoColor;
		for (int elem : g.ady(inicio)) {
			if (color[elem] == 'n') {
				if (color[inicio] == 'r') recorreEnProfundidad(color, g, bipartito, elem, 'a');
				else recorreEnProfundidad(color, g, bipartito, elem, 'r');
			}
			else if (color[elem] == proximoColor) bipartito = false;
		}
	}
}


bool resuelveCaso() {
	int v, a;
	cin >> v;
		if (!std::cin) // fin de la entrada
			return false;
	cin >> a;
	Grafo g(v);
	int v1, v2;
	for (int i = 0; i < a; ++i) {
		cin >> v1 >> v2;
		g.ponArista(v1, v2);
	}
	bool bipartito = true;
	vector<char> color(v, 'n');
	int i = 0;
	while (bipartito && i < v) {
		if (color[i] == 'n') recorreEnProfundidad(color, g, bipartito, i, 'a');
		++i;
	}

	if (bipartito) cout << "SI\n";
	else cout << "NO\n";

		return true;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}