#include <iostream>
#include <vector>
#include "PriorityQueue.h"

using namespace std;


bool resuelveCaso() {
	int n; 
	cin >> n;
		if (n == 0)
			return false;
		PriorityQueue<int, greater<int>> p1;
		PriorityQueue <int> p2;
		vector <int> medianas;
		int valor;
		cin >> valor;
		p2.push(valor);
		medianas.push_back(2 * valor);
		for (int i = 1; i < n; ++i) {
			cin >> valor;
			if ((i + 1) % 2 == 0) {
				if (valor > p2.top()) {
					p2.push(valor);
					p1.push(p2.top());
					p2.pop();
				}
				else p1.push(valor);

				medianas.push_back(p1.top() + p2.top());
			}
			else {
				if (valor > p2.top()) p2.push(valor);
				else {
					p1.push(valor);
					p2.push(p1.top());
					p1.pop();
				}
				medianas.push_back(2 * p2.top());
			}

		}
			for (int i = 0; i < medianas.size(); ++i) {
				cout << medianas[i];
				if (i < medianas.size() - 1) cout << " ";
			}
			cout << '\n';


		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
