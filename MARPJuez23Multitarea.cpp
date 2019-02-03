#include <iostream>
#include <queue>
#include <functional>
using namespace std;

struct tIntervalo {
	int inicio, fin, periodo;
};

bool operator >(tIntervalo const& i1, tIntervalo const& i2) {
	return (i1.inicio > i2.inicio || (i1.inicio == i2.inicio && i1.fin >= i2.fin));
}

bool resuelveCaso() {
	int n;
	cin >> n;
		if (!std::cin) // fin de la entrada
			return false;
	int m, t;
	cin >> m >> t;
	priority_queue<tIntervalo, vector <tIntervalo>, greater<tIntervalo>> pq;
	int periodo;
	tIntervalo intervalo;

	for (int i = 0; i < n; ++i) {
		cin >> intervalo.inicio >> intervalo.fin;
		intervalo.periodo = 0;
		if (intervalo.inicio < t) pq.push(intervalo);
	}
	for (int i = 0; i < m; ++i) {
		cin >> intervalo.inicio >> intervalo.fin >> intervalo.periodo;
		if (intervalo.inicio < t) pq.push(intervalo);
	}
	tIntervalo actual, sig;
	bool conflicto = false;
	while (pq.size() > 1 && !conflicto) {
		actual = pq.top();
		pq.pop();

		if (actual.periodo > 0) {
			intervalo.inicio = actual.inicio + actual.periodo;
			intervalo.fin = actual.fin + actual.periodo;
			intervalo.periodo = actual.periodo;
			if (intervalo.inicio < t)pq.push(intervalo);
		}

		sig = pq.top();
		if (sig.inicio < actual.fin) conflicto = true;
	}

	if (conflicto) cout << "SI\n";
	else cout << "NO\n";
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
