#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, start, end, res = 0;
	vector<pair<int, int> > vec;
	cin >> N;
	while (N--) {
		cin >> start >> end;
		vec.push_back(make_pair(end, start));
	}
	sort(vec.begin(), vec.end());
	int now = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i].second >= now)
		{
			res++;
			now = vec[i].first;
		}
	}
	cout << res << '\n';
}
