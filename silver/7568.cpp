#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N, rank = 1;
	cin >> N;
	vector<pair<int, int> > vec(N, make_pair(0, 0));
	for (int i = 0; i < N; i++)
		cin >> vec[i].first >> vec[i].second;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			if (vec[i].first < vec[j].first && vec[i].second < vec[j].second)
				rank++;
		cout << rank << '\n';
		rank = 1;
	}
}
