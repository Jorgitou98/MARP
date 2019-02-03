#include <iostream>
#include <vector>
#include <algorithm>
#include "Matriz.h"


using namespace std;

struct tCofre{
	int profundidad, oro;
	bool cogido;
};

bool resuelveCaso() {
	int T;
	cin >> T;
		if (!std::cin) // fin de la entrada
			return false;
	int n;
	cin >> n;
	int p, o;
	vector <tCofre> cofres;
	for (int i = 0; i < n; ++i) {
		cin >> p >> o;
		cofres.push_back({ p,o, false });
	}
	Matriz<int> M(n+1, T+1);
	for (int i = 0; i < n+1; ++i) M[i][0] = 0;
	for (int j = 1; j < T+1; ++j) M[0][j] = 0;

	for (int i = 1; i < n+1; ++i) {
		for (int j = 1; j < T+1; ++j) {
			if (3 * cofres[i - 1].profundidad > j) M[i][j] = M[i - 1][j];
			else M[i][j] = max( M[i - 1][j],  M[i - 1][j - 3 * cofres[i - 1].profundidad] + cofres[i - 1].oro );
		}
	}
	int j = T;
	int cont = 0;
	for (int i = n; i > 0; --i) {
		if (M[i][j] != M[i - 1][j]) {
			cofres[i-1].cogido = true;
			j -= 3 * cofres[i - 1].profundidad;
			cont++;
		}
	}
	cout << M[n][T] << '\n';
	cout << cont << '\n';
	for (int i = 0; i < n; ++i)
		if (cofres[i].cogido) cout << cofres[i].profundidad << " " << cofres[i].oro << '\n';
	cout << "----"<< '\n';
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}