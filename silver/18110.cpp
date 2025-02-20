#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	if (N == 0)
		cout << 0 << '\n';
	else
	{
		vector<int> vec(N, 0);
		for (int i = 0; i < N; i++)
			cin >> vec[i];
		sort(vec.begin(), vec.end());
		double sum = 0, outlier = round(static_cast<double>(N) * 0.15);
		for (int i = static_cast<int>(outlier); i < N - static_cast<int>(outlier); i++)
			sum += vec[i];
		cout << round(sum / (N - outlier * 2)) << '\n';
	}
}
