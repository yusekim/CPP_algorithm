#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n;
vector<int> apt_complex(0);

void bfs(vector<vector<int> > &vec, pair<int, int> &point)
{
	int count = 1;
	queue<pair<int, int> > que;
	vec[point.first][point.second] = 0;
	que.push(point);
	while (que.size())
	{
		int i = que.front().first, j = que.front().second;
		que.pop();
		if (i - 1 >= 0 && vec[i - 1][j] == '1')
		{
			vec[i - 1][j] = 0;
			que.push(make_pair(i - 1, j));
			count++;
		}
		if (i + 1 < n && vec[i + 1][j] == '1')
		{
			vec[i + 1][j] = 0;
			que.push(make_pair(i + 1, j));
			count++;
		}
		if (j - 1 >= 0 && vec[i][j - 1] == '1')
		{
			vec[i][j - 1] = 0;
			que.push(make_pair(i, j - 1));
			count++;
		}
		if (j + 1 < n && vec[i][j + 1] == '1')
		{
			vec[i][j + 1] = 0;
			que.push(make_pair(i, j + 1));
			count++;
		}
	}
	apt_complex.push_back(count);
	point.first = -1;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	vector<vector<int> > vec(n, vector<int>(n, 0));
	pair<int, int> point(-1, -1);
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			vec[i][j] = str[j];
			if (point.first == -1 && str[j] == '1')
				point = make_pair(i, j);
		}
	}
	while (point.first != -1)
	{
		bfs(vec, point);
		for (int i = 0; i < n; i++)
		{
			if (point.first != -1)
				break;
			for (int j = 0; j < n; j++)
			{
				if (point.first == -1 && vec[i][j] == '1')
				{
					point = make_pair(i, j);
					break;
				}
			}
		}
	}
	cout << apt_complex.size() << '\n';
	sort(apt_complex.begin(), apt_complex.end());
	for (auto &num : apt_complex)
		cout << num << '\n';
}
