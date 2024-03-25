#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int gcd(int A, int B) {
	if (A % B == 0)
		return B;
	return (gcd(B, A%B));
}

int	main() {
	fastio;
	int a, b, c, d; cin >> a >> b >> c >> d;
	int bd = gcd(b, d);
	int deno = b * d / bd;
	int nume = a * d / bd + c * b / bd;
	bd = gcd(deno, nume);
	cout << nume / bd << ' ' << deno / bd << '\n';
}
