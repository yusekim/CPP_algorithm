#include <iostream>
#include <string>
#include <map>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


int	main() {
	fastio;
	int N; cin >> N;
	map <string,int> M;

	while (N--) {
		string name, stat; cin >> name >> stat;
		if (stat == "leave")
			M[name] = 0;
		else
			M[name] = 1;
	}
	for (auto it = M.rbegin(); it != M.rend(); it++) {
		if (it->second)
			cout << it->first << "\n";
	}
}
