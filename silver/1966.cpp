#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int print_queue(vector<pair<int, bool> > &vec)
{
	int ret = 1;
	int max_elem = (*max_element(vec.begin(), vec.end(),
		[](const std::pair<int, bool> &a, const std::pair<int, bool> &b)
		{return a.first < b.first;})).first;
	while (true)
	{
		pair<int, bool> top = vec.front();
		vec.erase(vec.begin());
		if (top.first == max_elem)
		{
			if (top.second)
				break;
			max_elem = (*max_element(vec.begin(), vec.end(),
			[](const std::pair<int, bool> &a, const std::pair<int, bool> &b)
			{return a.first < b.first;})).first;
			ret++;
		}
		else
			vec.push_back(top);
	}
	return ret;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N, M, idx, w;
	cin >> N;
	while (N--)
	{
		cin >> M >> idx;
		vector<pair<int, bool> > vec;
		for (int i = 0; i < M; i++)
		{
			bool is_target = i == idx;
			cin >> w;
			vec.push_back(make_pair(w, is_target));
		}
		cout << print_queue(vec) << '\n';
	}
}
