#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N, M, tmp;
	cin >> N >> M;
	vector<vector<int> > map(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> tmp;
			if (j == 0)
				map[i][j] = tmp;
			else
				map[i][j] = tmp + map[i][j - 1];
		}
	}
	while (M--)
	{
		int res = 0;
		vector<int> coords(4, 0);
		for (int i = 0; i < 4; i++)
			cin >> coords[i];
		for (int j = coords[0]; j <= coords[2]; j++)
			res += map[j][coords[3]] - map[j][coords[1] - 1];
		cout << res << '\n';
	}
}
