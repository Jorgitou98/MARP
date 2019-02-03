#include <iostream>
#include <string>
#include <functional>
#include "PriorityQueue.h"

using namespace std;

struct tPaciente {
	string nombre;
	int gravedad;
	int cicloEntra;
};

bool operator > (tPaciente const& t1, tPaciente const& t2) {
	return t1.gravedad > t2.gravedad || (t1.gravedad == t2.gravedad && t1.cicloEntra < t2.cicloEntra);
}

bool resuelveCaso() {
	int n;
	cin >> n;
		if (n == 0)
			return false;
		char op;
		PriorityQueue <tPaciente, greater<tPaciente>> pq;
		tPaciente paciente;
		for (int i = 0; i < n; ++i) {
			cin >> op;
			if (op == 'I') {
				cin >> paciente.nombre >> paciente.gravedad;
				paciente.cicloEntra = i;
				pq.push(paciente);
			}
			else if (op == 'A') {
				cout << pq.top().nombre << '\n';
				pq.pop();
			}
		}
		cout << "----\n";

		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}
