#include <iostream>
#include "TreeMap_AVL.h"
using namespace std;

bool resuelveCaso() {
	int n;
	cin >> n;
	if (n == 0)
		return false;
	int elem, m;
	map<int, int> arbol;
	for (int i = 0; i < n; ++i) {
		cin >> elem;
		arbol.insert({ elem,1 });
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> elem;
		if (elem > arbol.size()) cout << "??";
		else {
			cout << arbol.KEsimoMenor(elem);
		}
		cout << '\n';
	}
	cout << "----\n";

	return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
