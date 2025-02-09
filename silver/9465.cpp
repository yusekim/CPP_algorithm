#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T, N;
	cin >> T;
	while (T--)
	{
		cin >> N;
		vector<int> vec1(N + 1, 0), vec2(N + 1, 0);
		for (int i = 1; i <= N; i++)
			cin >> vec1[i];
		for (int i = 1; i <= N; i++)
			cin >> vec2[i];
		for (int i = 2; i <= N; i++)
		{
			vec1[i] = vec1[i] + max(vec2[i - 1], vec2[i - 2]);
			vec2[i] = vec2[i] + max(vec1[i - 1], vec1[i - 2]);
		}
		cout << max(vec1[N], vec2[N]) << '\n';
	}
}
