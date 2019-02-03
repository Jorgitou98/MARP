#include <iostream>
#include <vector>
#include "GrafoValorado.h"
#include "PriorityQueue.h"
#include "ConjuntosDisjuntos.h"
using namespace std;

bool resuelveCaso() {
	int i, p;
	cin >> i;
		if (!std::cin) // fin de la entrada
			return false;
	cin >> p;
	GrafoValorado<int> g(i);
	int v1, v2, valor;
	PriorityQueue<Arista<int>> pq;
	for (int j = 0; j < p; ++j) {
		cin >> v1 >> v2 >> valor;
		Arista<int> a(v1 - 1, v2 - 1, valor);
		g.ponArista(a);
		pq.push(a);
	}
	int mstNum = 0;
	vector <Arista<int>> mst;
	ConjuntosDisjuntos c(i);
	while (!pq.empty() && mst.size() < i - 1) {
		Arista<int> e = pq.top();
		pq.pop();
		int prim = e.uno(); int otr = e.otro(prim);
		if (!c.unidos(prim, otr)) {
			c.unir(prim, otr);
			mst.push_back(e);
			mstNum += e.valor();
		}
	}

	if (c.num_cjtos() > 1) cout << "No hay puentes suficientes\n";
	else cout << mstNum << '\n';
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}