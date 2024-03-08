#include <iostream>
#include <string>
#include <string.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

void	trim_croatian(string& S) {
	string targets[] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};
	int		i = -1;

	while (S.c_str()[++i]) {
		int j = 0;
		while (j < 8) {
			if (strncmp(S.c_str() + i, targets[j].c_str(), targets[j].length()) == 0)
				break ;
			j++;
		}
		if (j == 8)
			continue;
		S.erase(i + 1, targets[j].length() - 1);
	}
}

int	main() {
	fastio;
	string S;
	cin >> S;

	trim_croatian(S);
	cout << S.length() << '\n';
	return 0;
}
