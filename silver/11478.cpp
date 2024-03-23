#include <iostream>
#include <set>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


int	main() {
	fastio;
	string str; cin >> str;
	set<string> S;

	int length = 1;
	for (int i = 0; i < str.size(); i++) {
		for (int j = 0; j + length <= str.size(); j++) {
			S.insert(str.substr(j, length));
		}
		length++;
	}
	cout << S.size() << '\n';
}
