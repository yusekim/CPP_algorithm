#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int gcd(int A, int B) {
	if (A % B == 0)
		return B;
	return (gcd(B, A%B));
}

int	main() {
	fastio;
	int N, span, count; cin >> N;
	vector<int> vec;

	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		vec.push_back(temp);
	}
	span = vec[1] - vec[0];
	for (int i = 2; i < vec.size(); i++) {
		span = gcd(vec[i] - vec[i - 1], span);
	}
	count = ((*(vec.end() - 1) - *vec.begin()) / span) - (N - 1);
	cout << count << '\n';
}
