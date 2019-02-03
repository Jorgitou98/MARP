#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0)
		return false;
	vector <int> rivales, locales;
	int valor;
	for (int i = 0; i < n; ++i) {
		cin >> valor;
		rivales.push_back(valor);
	}
	for (int i = 0; i < n; ++i) {
		cin >> valor;
		locales.push_back(valor);
	}
	sort(rivales.begin(), rivales.end());
	sort(locales.begin(), locales.end(), greater<int>());
	int suma = 0;
	bool mayor = true;
	int i = 0;
	while (i < n && mayor) {
		if (locales[i] > rivales[i]) suma += locales[i] - rivales[i];
		else mayor = false;
		++i;
	}
	cout << suma << '\n';
	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}