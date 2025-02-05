#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> printvec;

void print(vector<int> &vec, vector<bool> &bvec)
{
	for (int i = 0; i < printvec.size(); i++)
		cout << printvec[i] << ' ';
	cout << '\n';
}

void bt(vector<int> &vec, vector<bool> &bvec, int depth)
{
	if (depth == M)
		return print(vec, bvec);
	for (int i = 0; i < N; i++)
	{
		if (bvec[i])
			continue;
		bvec[i] = true;
		printvec.push_back(vec[i]);
		bt(vec, bvec, depth + 1);
		printvec.pop_back();
		bvec[i] = false;
	}

}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	vector<int> vec(N);
	vector<bool> bvec(N, false);
	for (int i = 0; i < N; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end());
	bt(vec, bvec, 0);
}
