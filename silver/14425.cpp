#include <iostream>
#include <string>
#include <set>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


int	main() {
	fastio;
	int N, M; cin >> N >> M;
	set<string> S;
	for (int i = 0; i < N; i++) {
		string tmp; cin >> tmp;
		S.insert(tmp);
	}
	int res = 0;
	for (int i = 0; i < M; i++) {
		string tmp;
		cin >> tmp;
		if (S.count(tmp))
			res++;
	}
	cout << res << '\n';
}
