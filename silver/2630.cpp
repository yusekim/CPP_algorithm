#include <iostream>
#include <vector>

using namespace std;

int w = 0, b = 0;

void rec(const vector<vector<int> >& map, int N, int i, int j) {
	int val = map[i][j];
	for (int a = 0; a < N; a++) {
		for (int b = 0; b < N; b++) {
			if (val != map[i + a][j + b]) {
				rec(map, N / 2, i, j);
				rec(map, N / 2, i, j + N / 2);
				rec(map, N / 2, i + N / 2, j);
				rec(map, N / 2, i + N / 2, j + N / 2);
				return;
			}
		}
	}
	val ? b++ : w++;
}

int main() {
	int N;
	cin >> N;

	vector<vector<int> > map(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	rec(map, N, 0, 0);
	cout << w << '\n' << b << '\n';
}
