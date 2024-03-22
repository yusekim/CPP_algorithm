#include <iostream>
#include <cmath>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

void hanoi(int target, int pos, int dest) {
	if (target == 1) {
		cout << pos + 1 << ' ' << dest + 1 << '\n';
		return ;
	}
	hanoi(target - 1, pos, 3 - (pos + dest));
	cout << pos + 1 << ' ' << dest + 1 << '\n';
	hanoi(target - 1, 3 - (pos + dest), dest);
}

int	main() {
	fastio;
	int N; cin >> N;
	cout << (unsigned long long)(pow(2, N) - 1) << '\n';
	hanoi(N, 0, 2);
}
