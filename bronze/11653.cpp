#include <iostream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


void	factorization(int N) {
	if (N == 1)
		return ;
	int i = 2;
	while (1) {
		if (N % i == 0) {
			cout << i << '\n';
			N /= i;
			return (factorization(N));
		}
		i++;
	}
}

int	main() {
	int N; cin >> N;

	factorization(N);
	return 0;
}
