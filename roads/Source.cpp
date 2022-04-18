#include <iostream>
#include <fstream>

using namespace std;

int main() {
	fstream in;
	in.open("input.txt", ios::in);
	if (!in.is_open()) {
		cout << "file is not open" << endl;
	}

	ofstream out;
	out.open("output.txt", ios::out);
	if (!out.is_open()) {
		cout << "file is not open" << endl;
	}

	int n, q;

	in >> n >> q;

	int* set = new int[n + 1];

	for (int i = 1; i < n + 1; i++) {
		set[i] = i;
	}

	int u, v, num = n;

	for (int i = 0; i < q; i++) {
		in >> u >> v;
		if (set[u] != set[v]) {
			for (int i = 1; i < n + 1; i++) {
				if (set[i] == set[u]) {
					set[i] = set[v];
				}
			}
			num--;
		}
		out << num << "\n";
	}

	in.close();
	out.close();

	return 0;
}