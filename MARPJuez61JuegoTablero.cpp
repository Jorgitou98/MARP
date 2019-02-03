#include <iostream>
#include <vector>
#include <algorithm>
#include "Matriz.h"
using namespace std;

bool resuelveCaso() {
	int N;
	cin >> N;
	if (!std::cin) // fin de la entrada
		return false;
	Matriz<int> M(N+1, N+1);

	//Inicializo la matriz
	for (int j = 0; j < N + 1; ++j)
		M[0][j] = 0;
	for (int i = 1; i < N + 1; ++i)
		M[i][0] = 0;

	for (int i = 1; i < N+1; ++i)
		for (int j = 1; j < N+1; ++j) {
			cin >> M[i][j];
		}
	int mejor;
	vector <int> mejorSol = M[1];
	int anterior;
	for (int i = 2; i < N + 1; ++i) {
		anterior = 0;
		for (int j = 1; j < N + 1; ++j) {
			if (j < N) mejor = max(anterior, max(mejorSol[j], mejorSol[j + 1]));
			else mejor = max(anterior, mejorSol[j]);
			anterior = mejorSol[j];
			mejorSol[j] = mejor + M[i][j];
		}
	}

	int maximo = mejorSol[1];
	int posMaximo = 1;
	for (int j = 2; j < N + 1; ++j) {
		if (mejorSol[j] > maximo) {
			maximo = mejorSol[j];
			posMaximo = j;
		}
	}
	cout << mejorSol[posMaximo] << " " << posMaximo << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}

