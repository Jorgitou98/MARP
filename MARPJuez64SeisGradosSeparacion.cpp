#include <iostream>
#include <unordered_map>
#include <climits>
#include <algorithm>
#include <string>
#include "Matriz.h"
using namespace std;
bool resuelveCaso() {
	int p;
	cin >> p;
		if (!std::cin) // fin de la entrada
			return false;
	int r;
	cin >> r;
	Matriz<int> ady(p, p, INT_MAX);
	unordered_map<string, int> numPersona;
	int num = 0;
	string nombre1, nombre2;
	for (int i = 0; i < r; ++i) {
		cin >> nombre1 >> nombre2;
		if (!numPersona.count(nombre1)) {
			numPersona.insert({ nombre1, num });
			num++;
		}
		if (!numPersona.count(nombre2)) {
			numPersona.insert({ nombre2, num });
			num++;
		}
		ady[numPersona[nombre1]][numPersona[nombre2]] = 1;
		ady[numPersona[nombre2]][numPersona[nombre1]] = 1;
	}
	for (int i = 0; i < p; ++i) ady[i][i] = 0;

	for (int k = 0; k < p; ++k)
		for (int i = 0; i < p; ++i)
			for (int j = 0; j < p; ++j)
				if(ady[i][k] != INT_MAX && ady[k][j] != INT_MAX) ady[i][j] = min(ady[i][j], ady[i][k] + ady[k][j]);

	int maximo = 0;

	for (int i = 0; i < p; ++i)
		for (int j = 0; j < p; ++j)
			maximo = max(maximo, ady[i][j]);

	if (maximo == INT_MAX) cout << "DESCONECTADA\n";
	else cout << maximo << '\n';
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}

