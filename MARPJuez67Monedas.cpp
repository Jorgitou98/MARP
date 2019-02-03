#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

struct tMoneda {
	int valor, cantidad;
};


bool resuelveCaso() {
	int N;
	cin >> N;
		if (!std::cin) // fin de la entrada
			return false;
	vector<tMoneda> moneda(N);
	for (int i = 0; i < N; ++i) {
		cin >> moneda[i].valor;
	}
	for (int i = 0; i < N; ++i) {
		cin >> moneda[i].cantidad;
	}

	int C;
	cin >> C;
	vector<int> V(C + 1);

	for (int i = 0; i < N + 1; ++i)
		V[0] = 0;

	for (int j = 1; j < C + 1; ++j)
		V[j] = INT_MAX;

	for (int i = 1; i < N+1; ++i)
		for (int j = C; j >= 0; --j) {
			int mini = INT_MAX;
			for (int k = 0; k <= moneda[i - 1].cantidad && k * moneda[i - 1].valor <= j; ++k) {
				if (V[j - k * moneda[i-1].valor] != INT_MAX) {
					mini = min(V[j - k * moneda[i-1].valor] + k, mini);
				}
			}
			V[j] = mini;
		}

	if (V[C] == INT_MAX) cout << "NO";
	else cout << "SI " << V[C];
	cout << '\n';

		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
