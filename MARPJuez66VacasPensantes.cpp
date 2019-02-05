#include <iostream>
#include <algorithm>
#include "Matriz.h"
#include <vector>
using namespace std;
bool resuelveCaso() {
	int N;
	cin >> N;
		if (N == 0)
			return false;
	vector <int> cubos;
	int valor;
	for (int i = 0; i < N; ++i) {
		cin >> valor;
		cubos.push_back(valor);
	}
	Matriz<int> M(N, N);
	for (int i = 0; i < N; ++i) M[i][i] = cubos[i];

	for (int d = 1; d < N; ++d)
		for (int i = 0; i < N - d; ++i) {
			int j = i + d;
			int suma1, suma2;

			if (i + 1 == j) suma1 = cubos[i];
			else if (cubos[i + 1] >= cubos[j]) suma1 = cubos[i] + M[i + 2][j];
			else suma1 = cubos[i] + M[i + 1][j-1];

			if (j - 1 == i) suma2 = cubos[j];
			else if (cubos[j-1] >= cubos[i]) suma2 = cubos[j] + M[i][j-2];
			else suma2 = cubos[j] + M[i + 1][j - 1];

			M[i][j] = max(suma1, suma2);
		}

	cout << M[0][N - 1] << '\n';
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}