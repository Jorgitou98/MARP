#include <iostream>
#include "Grafo.h"
using namespace std;

void marcaCompConexaBlanca(Grafo const& g, vector<bool>& marcados, int inicio, vector<char> const& imagen) {
	for (int elem : g.ady(inicio)) {
		if (!marcados[elem] && imagen[elem] == '.') {
			marcados[elem] = true;
			marcaCompConexaBlanca(g, marcados, elem, imagen);
		}
	}
}



bool resuelveCaso() {
	int ancho, alto;
	cin >> ancho;
		if (!std::cin) // fin de la entrada
			return false;
	cin >> alto;
	char pixel;
	vector<char> imagen;
	Grafo g(ancho * alto);
	for (int i = 0; i < alto; ++i) {
		for (int j = 0; j < ancho; ++j) {
			cin >> pixel;
			imagen.push_back(pixel);
			if (i > 0) g.ponArista(i*ancho + j, (i - 1)*ancho + j);
			if (i < alto - 1) g.ponArista(i*ancho + j, (i + 1)*ancho + j);
			if (j > 0) g.ponArista(i*ancho + j, i*ancho + j - 1);
			if(j < ancho -1) g.ponArista(i*ancho + j, i*ancho + j + 1);
		}
	}

	vector <bool> marcados(ancho * alto, false);
	int compConexas = 0;
	for (int i = 0; i < alto; ++i) {
		for (int j = 0; j < ancho; ++j) {
			if (!marcados[i*ancho + j] && imagen[i*ancho + j] == '.') {
				marcaCompConexaBlanca(g, marcados, i*ancho + j, imagen);
				compConexas++;
			}
		}
	}
	cout << compConexas - 1 << '\n';
		return true;
}
int main() {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	while (resuelveCaso());
	return 0;
}