#include <iostream>
#include <string>
#include <vector>
#ifndef MATRIZ_H
#define MATRIZ_H

#include <vector>

template <typename Object>
class Matriz {
public:
	// crea una matriz con fils filas y cols columnas,
	// con todas sus celdas inicializadas al valor e
	Matriz(int fils, int cols, Object e = Object()) : datos(fils, std::vector<Object>(cols, e)) {}

	// operadores para poder utilizar notación M[i][j]
	std::vector<Object> const& operator[](int f) const {
		return datos[f];
	}
	std::vector<Object> & operator[](int f) {
		return datos[f];
	}

	// métodos que lanzan una excepción si la posición no existe
	Object const& at(int f, int c) const {
		return datos.at(f).at(c);
	}
	Object & at(int f, int c) { // este método da problemas cuando Object == bool
		return datos.at(f).at(c);
	}

	int numfils() const { return datos.size(); }
	int numcols() const { return numfils() > 0 ? datos[0].size() : 0; }

	bool posCorrecta(int f, int c) const {
		return 0 <= f && f < numfils() && 0 <= c && c < numcols();
	}

private:
	std::vector<std::vector<Object>> datos;
};

#endif
using namespace std;

struct tTipo {
	string cad;
	int primAp;
	bool igual;
};

bool resuelveCaso() {
	string cad;
	cin >> cad;
	if (!std::cin) // fin de la entrada
		return false;
	cad = " " + cad;
	int n = cad.size() - 1;
	Matriz<string> pat(n + 1, n + 1, "");
	for (int i = 1; i <= n; i++)
	{
		pat[i][i] = cad[i];
	}
	for (size_t d = 1; d <= n - 1; d++)
	{
		for (size_t i = 1; i <= n - d; i++)
		{
			size_t j = i + d; // Comparaciones cada 1, cada 2, cada 3 etc..
			if (cad[i] == cad[j]) { // Coiniden las letras e la comparacion, ensadwicho entre ella el palindromo de dentro
				pat[i][j] = cad[i] + pat[i + 1][j - 1] + cad[i]; // Lo he rellenado anteriormente
			}
			else {
				if (pat[i + 1][j].size() >= pat[i][j - 1].size()) pat[i][j] = pat[i + 1][j];
				else pat[i][j] = pat[i][j - 1];
			}
		}
	}

	cout << pat[1][n] << '\n';

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}

