#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

bool isprime(long long n) {
	if (n < 2)
		return false;
	if (n == 2 || n == 3)
		return true;
	for (long long i = 2; i * i <= n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int	main() {
	fastio;
	long long N; cin >> N;
	while (N--) {
		long long n; cin >> n;
		while (!isprime(n))
			n++;
		cout << n << '\n';
	}
}
