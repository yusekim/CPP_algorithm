#include <iostream>
#include <vector>
using namespace std;
int N, M, S, D;

unsigned long long dijkstra(vector<pair<bool, unsigned long long >> cities, vector<vector<pair<int, int>>> routes)
{
	cities[S - 1].second = 0;
	int target_num = S - 1;
	vector<pair<int, int>> &target_city = routes[S - 1];
	for (int i = 0; i < N; i++)
	{
		for (auto it = target_city.begin(); it != target_city.end(); it++) // *it = <d_city, weight>
		{
			int d_city = (*it).first;
			int weight = (*it).second;
			if (cities[target_num].second + weight < cities[d_city].second)
				cities[d_city].second = cities[target_num].second + weight;
		}
		cities[target_num].first = 1;
		unsigned long long sd = -1;
		for (int idx = 0; idx < N; idx++)
		{
			if (cities[idx].first == false && cities[idx].second < sd)
			{
				target_num = idx;
				sd = cities[idx].second;
			}
		}
		target_city = routes[target_num];
	}
	return cities[D - 1].second;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	vector<pair<bool, unsigned long long>> cities(N, make_pair(0, -1)); // {<visited, shortest dist>, <visited, shortest dist>, ...}
	vector<vector<pair<int, int>>> routes(N); // routes[s_city] = {<d_city, weight>, <d_city, weight>, ...}
	for (int i = 0; i < M; i++)
	{
		int s, d, w;
		cin >> s >> d >> w;
		routes[s - 1].push_back(make_pair(d - 1, w));
	}
	cin >> S >> D;
	// cout << "\n========================================\n" << N << ' ' << M << '\n';
	// for (int i = 0; i < N; i++)
	// {
	// 	for (auto it = routes[i].begin(); it != routes[i].end(); it++)
	// 		cout << i + 1 << ' ' << (*it).first + 1 << ' ' << (*it).second << '\n';
	// }
	// cout << S << ' ' << D << '\n';
	cout << dijkstra(cities, routes) << '\n';
}
