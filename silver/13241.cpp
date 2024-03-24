#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

long long gcd(long long A, long long B) {
	if (A % B == 0)
		return B;
	return (gcd(B, A%B));
}

int	main() {
	fastio;
	long long A, B; cin >> A >> B;
	long long g = 0;
	if (A > B)
		g = gcd(A, B);
	else
		g = gcd(B, A);
	cout << A * B / g << '\n';

}
