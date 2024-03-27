#include <iostream>
#include <cmath>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int arr[1000001];
int	main() {
	fastio;
	int N, M; cin >> N >> M;

	for (int i = 2; i <= M; i++) {
			arr[i] = i;
	}
	for (int i = 2; i <= sqrt(M); i++) {
		if (arr[i] == 0)
			continue;
		for (int j = i * i; j <= M; j += i)
			arr[j] = 0;
	}
	for (int i = N; i <= M; i++) {
		if (arr[i])
			cout << arr[i] << '\n';
	}
}
