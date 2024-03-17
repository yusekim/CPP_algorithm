#include <iostream>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int	main() {
	fastio;
	int	N; cin >> N;

	for (int i = 0; i <= N; i++) {
		string S = to_string(i);
		int		val = i;
		for (int j = 0; j < S.length(); j++) {
			val += S[j] - '0';
		}
		if (val == N) {
			cout << i << '\n';
			return 0;
		}
	}
	cout << 0 << '\n';
	return 0;
}
