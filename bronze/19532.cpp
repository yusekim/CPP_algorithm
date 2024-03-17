#include <iostream>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int	main() {
	fastio;
	int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;

	for (int X = -999; X < 1000; X++) {
		for (int Y = -999; Y < 1000; Y++) {
			if ((a*X + b*Y) == c && (d*X + e*Y == f))
				cout << X << ' ' << Y << '\n';
		}
	}
}
