#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);

	long K, N;
	cin >> K >> N;
	vector<long> vec(K);
	for (long i = 0; i < K; i++)
		cin >> vec[i];

	long low = 1;
	long high = *max_element(vec.begin(), vec.end());
	long result = 0;

	while (low <= high) {
		long mid = low + (high - low) / 2;
		long pieces = 0;
		for (int i = 0; i < K; i++)
			pieces += vec[i] / mid;
		if (pieces >= N)
		{
			result = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	cout << result << '\n';
}
