#include <iostream>
#include <string>
#include <cstring>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int	main() {
	int canvas[100][100];
	int N; cin >> N;

	memset(canvas, 0, sizeof(canvas));
	for (int i = 0; i < N; i++) {
		int x, y; cin >> x >> y;
		for (int Y = 0; Y < 10; Y++) {
			for (int X = 0; X < 10; X++) {
				canvas[y + Y][x + X] = 1;
			}
		}
	}
	int result = 0;
	for (int i=0; i < 100; i++) {
		for (int j=0; j < 100; j++) {
			if (canvas[i][j])
				result++;
		}
	}
	cout << result << '\n';
	return 0;
}
