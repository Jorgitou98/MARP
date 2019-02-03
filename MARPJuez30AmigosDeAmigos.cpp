#include <iostream>
#include "Grafo.h"
using namespace std;

void recorreEnProfundidad(int &visitados, Grafo const& g, int inicio, vector<bool> & marcados) {
	visitados++;
	marcados[inicio] = true;
	for (int elem : g.ady(inicio))
		if (!marcados[elem]) recorreEnProfundidad(visitados, g, elem, marcados);
}


void resuelveCaso() {
	int n, m, v1, v2;
	cin >> n >> m;
	Grafo g(n+1);
	for (int i = 0; i < m; ++i) {
		cin >> v1 >> v2;
		g.ponArista(v1, v2);
	}
	vector <bool> marcados(n+1, false);
	int maxAmigos = 0, visitados;
	for (int i = 1; i <= n; ++i) {
		visitados = 0;
		recorreEnProfundidad(visitados, g, i, marcados);
		if (visitados > maxAmigos) maxAmigos = visitados;
	}
	cout << maxAmigos << '\n';
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i)
		resuelveCaso();
	return 0;
}
