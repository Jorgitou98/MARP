#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct tVarilla {
	int longitud, coste;
};

struct tInfo {
	int formas, nMin, costeMin;
};

bool resuelveCaso() {
	int N;
	cin >> N;
		if (!std::cin) // fin de la entrada
			return false;
	int L;
	cin >> L;
	int longi, cte;
	vector <tVarilla> varillas;
	for (int i = 0; i < N; ++i) {
		cin >> longi >> cte;
		varillas.push_back({ longi,cte });
	}
	vector<tInfo> info;
	//Inicializacion
	info.push_back({ 1,0,0 });
	for (int j = 1; j < L + 1; ++j) {
		if (j == varillas[0].longitud) info.push_back({ 1,1,varillas[0].coste });
		else info.push_back({ 0,0,0 });
	}

	for (int i = 1; i < N; ++i)
		for (int j = L; j >= 0; --j) {
			if (varillas[i].longitud <= j) {
				if (info[j].formas > 0 && info[j - varillas[i].longitud].formas > 0) {
					info[j].formas += info[j - varillas[i].longitud].formas;
					info[j].nMin = min(info[j].nMin, info[j - varillas[i].longitud].nMin + 1);
					info[j].costeMin = min(info[j].costeMin, info[j - varillas[i].longitud].costeMin + varillas[i].coste);
				}
				else if (info[j - varillas[i].longitud].formas > 0) {
					info[j].formas = info[j - varillas[i].longitud].formas;
					info[j].nMin = info[j - varillas[i].longitud].nMin + 1;
					info[j].costeMin = info[j - varillas[i].longitud].costeMin + varillas[i].coste;
				}
			}
		}
	if (info[L].formas > 0) cout << "SI " << info[L].formas << " " << info[L].nMin << " " << info[L].costeMin;
	else cout << "NO";
	cout << '\n';
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}