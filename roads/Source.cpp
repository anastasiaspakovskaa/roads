#include <iostream>
#include <fstream>

using namespace std;

int findSet(int u, int* set) {
	int repU = set[u];
	while (repU != set[repU]) {
		repU = set[repU];
	}
	return repU;
}

bool unionSet(int u, int v, int* set) {
	int repU = findSet(u, set);
	int repV = findSet(v, set);
	if (repU != repV) {
		set[repV] = repU;
		return true;
	}
	else {
		return false;
	}
}

int main() {
	fstream in;
	in.open("input.txt", ios::in);

	ofstream out;
	out.open("output.txt", ios::out);

	int n, q;

	in >> n >> q;

	int* set = new int[n + 1];

	for (int i = 1; i < n + 1; i++) {
		set[i] = i;
	}

	int u, v;
	int num = n;

	for (int i = 0; i < q; i++) {
		in >> u >> v;
		if (unionSet(u, v, set)) {
			num--;
		}
		out << num << "\n";
	}

	in.close();
	out.close();

	return 0;
}