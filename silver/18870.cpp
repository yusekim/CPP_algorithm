#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


int	main() {
	fastio;
	int N; cin >> N;

	vector<int> vec1(N);
	for (int i = 0; i < N; i++) {
		cin >> vec1[i];
	}
	vector<int> vec2(vec1);
	sort(vec2.begin(), vec2.end());
	vec2.erase(unique(vec2.begin(), vec2.end()), vec2.end());
	for (int i = 0; i < N; i++) {
		auto it = lower_bound(vec2.begin(), vec2.end(), vec1[i]);
		cout << it - vec2.begin() << ' ';
	}
	cout << '\n';
}
