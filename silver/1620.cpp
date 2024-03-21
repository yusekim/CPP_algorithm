#include <iostream>
#include <string>
#include <vector>
#include <map>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


int	main() {
	fastio;
	int N, M; cin >> N >> M;
	map <string,int> m;
	vector<string> vec;

	for (int i = 0; i < N; i++) {
		string name; cin >> name;
		vec.push_back(name);
		m[name] = i + 1;
	}
	for (int i = 0; i < M; i++) {
		string val; cin >> val;
		if (val[0] >= '0' && val[0] <= '9') {
			int idx = stoi(val);
			cout << vec[idx - 1] << '\n';
		}
		else
			cout << m.find(val)->second << '\n';
	}
}
