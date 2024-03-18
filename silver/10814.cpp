#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


int	main() {
	fastio;
	int N; cin >> N;

	vector<pair<int, string> > V;
	vector<int> vec;
	while (N--) {
		int age; cin >> age;
		string name; cin >> name;
		V.push_back(make_pair(age, name));
		vec.push_back(age);
	}
	stable_sort(V.begin(), V.end(), [](pair<int, string> a, pair<int, string> b) {return (a.first < b.first);});
	for (auto a:V) cout << a.first << ' ' << a.second << '\n';
	return 0;
}
