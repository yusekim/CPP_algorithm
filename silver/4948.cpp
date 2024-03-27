#include <iostream>
#include <cmath>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int arr[1000001];
int	main() {
	fastio;
	int N; cin >> N;

	while (N != 0) {
		int n2 = N * 2;
		for (int i = 2; i <= n2; i++) {
			arr[i] = i;
		}
		for (int i = 2; i <= sqrt(n2); i++) {
			if (arr[i] == 0)
				continue;
			for (int j = i * i; j <= n2; j += i)
				arr[j] = 0;
		}
		int res = 0;
		for (int i = N + 1; i <= n2; i++) {
			if (arr[i])
				res++;
		}
		cout << res << '\n';
		cin >> N;
	}
}
