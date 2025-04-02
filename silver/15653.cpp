#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> path;
vector<int> inputvec;
vector<bool> bvec;

void bt(int depth)
{
	if (depth == m)
	{
		for (int num : path)
			cout << num << ' ';
		cout << '\n';
		return;
	}

	int last = -1;
	for (int i = 0; i < n; i++)
	{
		if (bvec[i])
			continue;
		if (last == inputvec[i])
			continue;
		bvec[i] = true;
		path.push_back(inputvec[i]);
		last = inputvec[i];
		bt(depth + 1);
		bvec[i] = false;
		path.pop_back();
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	inputvec.resize(n);
	bvec.resize(n, false);
	for (int i = 0; i < n; i++)
		cin >> inputvec[i];
	sort(inputvec.begin(), inputvec.end());
	bt(0);
}
