#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>
#include "Matriz.h"
using namespace std;
bool resuelveCaso() {
	int l, n;
	cin >> l >> n;
		if (l == 0 && n == 0)
			return false;
	vector <int> cortes;
	cortes.push_back(0);
	int valor;
	for (int i = 0; i < n; ++i) {
		cin >> valor;
		cortes.push_back(valor);
	}
	cortes.push_back(l);
	Matriz<int> M(n + 2, n + 2, 0); // Consideramos 0 y l como puntos
	for (int d = 2; d < n + 2; ++d)  // Diagonales desde la segunda
		for (int i = 0; i < n + 2 - d; ++i) {
			int j = d + i;
				int mejor = INT_MAX;
				for (int m = i + 1; m < j; ++m) {
					mejor = min(mejor, M[i][m] + M[m][j]);
				}
				M[i][j] = mejor + 2 * (cortes[j] - cortes[i]);
		}
	cout << M[0][n + 1] << '\n';
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
