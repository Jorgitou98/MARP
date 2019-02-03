#include <iostream>
#include "Matriz.h"
#include "ConjuntosDisjuntos.h"

using namespace std;

bool resuelveCaso() {
	int f, c;
	cin >> f;
	if (!std::cin) // fin de la entrada
		return false;
	cin >> c;
	getchar(); // Fuera el salto de linea
	bool hayPetroleo = false;
	Matriz<char> mat(f, c);
	ConjuntosDisjuntos disj(f * c);
	char elem;
	for (int i = 0; i < f; ++i) {
		for (int j = 0; j < c; ++j) {
			elem = getchar();
			mat[i][j] = elem;
			if (elem == '#') {
				hayPetroleo = true;
				if (mat.posCorrecta(i - 1, j - 1) && mat[i - 1][j - 1] == '#') disj.unir(i * c + j, (i - 1) * c + j - 1);
				if (mat.posCorrecta(i - 1, j) && mat[i - 1][j] == '#') disj.unir(i * c + j, (i - 1) * c + j);
				if (mat.posCorrecta(i - 1, j + 1) && mat[i - 1][j + 1] == '#') disj.unir(i * c + j, (i - 1) * c + j + 1);
				if (mat.posCorrecta(i, j - 1) && mat[i][j - 1] == '#') disj.unir(i * c + j, i * c + j - 1);
			}
		}
		getchar(); // Me quito el salto de linea
	}
	if (hayPetroleo) cout << disj.componenteMasGrande();
	else cout << "0";

	int k, v1, v2;
	cin >> k;
	if(k > 0) cout << " ";
	for (int i = 0; i < k; ++i) {
		cin >> v1 >> v2;
		v1--;
		v2--;
		mat[v1][v2] = '#';
		if (mat.posCorrecta(v1 - 1, v2 - 1) && mat[v1 - 1][v2 - 1] == '#') disj.unir(v1 * c + v2, (v1 - 1) * c + v2 - 1);
		if (mat.posCorrecta(v1 - 1, v2) && mat[v1 - 1][v2] == '#') disj.unir(v1 * c + v2, (v1 - 1) * c + v2);
		if (mat.posCorrecta(v1 - 1, v2 + 1) && mat[v1 - 1][v2 + 1] == '#') disj.unir(v1 * c + v2, (v1 - 1) * c + v2 + 1);
		if (mat.posCorrecta(v1, v2 - 1) && mat[v1][v2 - 1] == '#') disj.unir(v1 * c + v2, v1 * c + v2 - 1);
		if (mat.posCorrecta(v1, v2 + 1) && mat[v1][v2 + 1] == '#') disj.unir(v1 * c + v2, v1 * c + v2 + 1);
		if (mat.posCorrecta(v1 + 1, v2 - 1) && mat[v1 + 1][v2 - 1] == '#') disj.unir(v1 * c + v2, (v1 + 1) * c + v2 - 1);
		if (mat.posCorrecta(v1 + 1, v2) && mat[v1 + 1][v2] == '#') disj.unir(v1 * c + v2, (v1 + 1) * c + v2);
		if (mat.posCorrecta(v1 + 1, v2 + 1) && mat[v1 + 1][v2 + 1] == '#') disj.unir(v1 * c + v2, (v1 + 1) * c + v2 + 1);
		cout << disj.componenteMasGrande();
		if(i < k-1) cout << " ";
	}
	cout << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}