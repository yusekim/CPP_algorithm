#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> map;
unsigned int n, m, b, height, timetaken = -1;

void shoveling(int inventory, int goal)
{
	int timeval = 0;
	for (auto kv : map)
	{
		if (goal < kv.first)
		{
			timeval += (kv.first - goal) * 2 * kv.second;
			inventory += (kv.first - goal) * kv.second;
		}
		if (goal > kv.first)
		{
			timeval += (goal - kv.first) * kv.second;
			inventory -= (goal - kv.first) * kv.second;
		}
	}
	if (inventory >= 0)
	{
		if (timeval <= timetaken)
		{
			timetaken = timeval;
			if (goal >= height)
				height = goal;
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> b;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> height;
			map[height]++;
		}
	}
	height = 0;
	for (int i = 0; i <= 256; i++)
		shoveling(b, i);
	cout << timetaken << ' ' << height << '\n';
}






















// using namespace std;
// vector<vector<int> > vec(501, vector<int>(501, 0));

// int main()
// {
// 	int n, m, b;
// 	cin >> n >> m >> b;
// 	unordered_map<int, size_t> map;
// 	pair<int, size_t> maxelem(0, 0), maxheight(0, 0), temp(2147483647, -1);
// 	for (int i = 1; i <= n; i++)
// 	{
// 		for (int j = 1; j <= m; j++)
// 		{
// 			cin >> vec[i][j];
// 			if (map.find(vec[i][j]) == map.end())
// 			{
// 				map[vec[i][j]] = 1;
// 				if (vec[i][j] > maxheight.first)
// 				{
// 					maxheight = make_pair(vec[i][j], 1);
// 				}
// 				if (vec[i][j] >= maxelem.first && maxelem.second <= 1)
// 					maxelem = make_pair(vec[i][j], 1);
// 			}
// 			else
// 			{
// 				map[vec[i][j]] += 1;
// 				if (vec[i][j] == maxheight.first)
// 					maxheight.second += 1;
// 				if (map[vec[i][j]] > maxelem.second)
// 					maxelem = make_pair(vec[i][j], map[vec[i][j]]);
// 				else if (map[vec[i][j]] == maxelem.second && vec[i][j] > maxelem.first)
// 					maxelem.first = vec[i][j];
// 			}
// 		}
// 	}
// 	int eraseblock = 0;
// 	while(maxheight.first >= 0)
// 	{
// 		int putdown = 0;
// 		for (const auto& kv : map)
// 			putdown += (maxheight.first - kv.first) * kv.second;
// 		if (b - putdown >= 0)
// 		{
// 			if (putdown + eraseblock < temp.first)
// 				temp = make_pair(putdown + eraseblock, maxheight.first);
// 		}
// 		map.erase(maxheight.first);
// 		maxheight.first -= 1;
// 		if (map.find(maxheight.first) == map.end())
// 			map[maxheight.first] = maxheight.second;
// 		else
// 			map[maxheight.first] += maxheight.second;
// 		b += maxheight.second;
// 		eraseblock += 2 * maxheight.second;
// 		maxheight = make_pair(maxheight.first, map[maxheight.first]);
// 		if (maxheight.first + 1 == maxelem.first)
// 			maxelem = maxheight;
// 	}
// 	cout << temp.first << ' ' << temp.second << '\n';
// }
