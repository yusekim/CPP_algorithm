#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	vector<int> vec(N + 1, 0);
	for (int i = 1; i < vec.size(); i++)
	{
		cin >> vec[i];
		vec[i] += vec[i - 1];
	}
	while (M--)
	{
		int start, end;
		cin >> start >> end;
		cout << vec[end] - vec[start - 1] << '\n';
	}
}
