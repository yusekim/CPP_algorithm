#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;
unsigned long long idx = 0;

int gcd(int A, int B) {
	if (A % B == 0)
		return B;
	return (gcd(B, A%B));
}

int	main() {
	fastio;
	int N; cin >> N;
	while (N--) {
		int A, B; cin >> A >> B;
		int g = 0;
		if (A > B)
			g = gcd(A, B);
		else
			g = gcd(B, A);
		cout << A * B / g << '\n';
	}
}
