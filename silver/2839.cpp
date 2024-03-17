#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int	main() {
	fastio;
	int	N, res = -1; cin >> N;

	int F = N / 5, T = 0;
	while (1 && F >= 0) {
		int remain = N - F * 5;
		if (remain % 3 == 0) {
			res = F + (remain / 3);
			break ;
		}
		F--;
	}
	cout << res << '\n';
}
