#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int arr[1000001];
int	main() {
	fastio;
	for (int i = 1; i <= 1000000; i++) {
		arr[i] = i;
	}
	for (int i = 2; i * i <= 1000000; i++) {
		if (arr[i] == 0)
			continue;
		for (int j = i * i; j <= 1000000; j += i)
			arr[j] = 0;
	}
	int N; cin >> N;
	while (N--) {
		int tcase, cnt = 0; cin >> tcase;
		for (int i = 2; i < tcase; i++) {
			if (arr[tcase - i] + arr[i] == tcase) {
				cnt++;
				if (tcase - i == i)
					cnt++;
			}
		}
		cout << cnt / 2 << '\n';
	}
}
