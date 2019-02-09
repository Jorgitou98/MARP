#include <iostream>
#include "Matriz.h"
#include <algorithm>
#include <vector>
using namespace std;

bool resuelveCaso() {
	int N;
	cin >> N;
		if (N == 0)
			return false;
	char aux;
	int horas, minutos, dur, ini;
	vector <pair<int, int>> pelis;
	for (int i = 0; i < N; ++i) {
		cin >> horas >> aux >> minutos >> dur;
		ini = horas * 60 + minutos;
		pelis.push_back({ ini, dur});
	}
	sort(pelis.begin(), pelis.end());
	// 1441 = 24*60 +1 (horas del dia)
	vector <int> V;
	for (int j = 0; j < 1451; ++j) V.push_back(0);

	for (int i = 1; i < N+1; ++i)
		for (int j = 1450; j > 0; --j) {
			if (j >= pelis[i-1].first + pelis[i-1].second + 10)
				V[j] = max(V[j], V[pelis[i-1].first] + pelis[i-1].second);
		}
	cout << V[1450] << '\n';

		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}