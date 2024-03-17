#include <iostream>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

bool	is_shom(int res) {
	string S = to_string(res);
	if (S.find("666") != string::npos)
		return (true);
	else
		return (false);
}

int	main() {
	fastio;
	int N; cin >> N;

	int n = 0;
	int	res = 666;
	while (1) {
		if (is_shom(res)) {
			n++;
			if (N == n)
				break ;
		}
		res++;
	}
	cout << res << '\n';
}
