#include <iostream>
#include "ConjuntosDisjuntos.h"
#include "Matriz.h"
#include <cmath>
#include <stack>
using namespace std;
bool resuelveCaso() {
	int N;
	cin >> N;
		if (!std::cin) // fin de la entrada
			return false;
	int M, K, n;
	cin >> M >> K >> n;
	M++;
	N++;
	ConjuntosDisjuntos c(N*M);
	Matriz<bool> mat(N, M, false);
	mat[0][0] = true;
	mat[N-1][M-1] = true;
	stack<pair<int,int>> pila;
	int v1, v2;
	for (int i = 0; i < n; ++i) {
		cin >> v1 >> v2;
		pila.push({ v1,v2 });
	}
	bool fin = false;
	int prim, seg;
	while (!pila.empty() && !fin) {
		prim = pila.top().first;
		seg = pila.top().second;
		for (int j = -K; j <= K && !fin; ++j) {
			for (int m = -K; m <= K && !fin; ++m) {
				if (sqrt(j*j + m * m) <= K && mat.posCorrecta(prim + j, seg + m) && mat[prim + j][seg + m]) {
					c.unir(prim * M + seg, (prim + j) * M + seg + m);
				}
				if (c.unidos(0, N * M - 1)) fin = true;
			}
		}
		mat[prim][seg] = true;
		pila.pop();
	}
	if (!fin) cout << "NUNCA SE PUDO\n";
	else cout << prim << " " << seg << '\n';

		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}