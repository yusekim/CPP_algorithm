#include <iostream>
#include <string>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


int	main() {
	fastio;
	string S; cin >> S;

	sort(S.begin(), S.end());
	for (int i = S.length() - 1; i >= 0; i--) {
		cout << S[i];
	}
	cout << '\n';
	return 0;
}
