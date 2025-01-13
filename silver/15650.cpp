#include <iostream>
#include <vector>

using namespace std;
int N, M;

void print(vector<int> &vec, vector<bool> &bvec)
{
	for (int i = 0; i < N; i++)
		if (bvec[i])
			cout << vec[i] << ' ';
	cout << '\n';
}

void bt(vector<int> &vec, vector<bool> &bvec, int val, int cnt)
{
	if (cnt == M)
		return print(vec, bvec);
	for (int i = val; i < N; i++)
	{
		if (bvec[i])
			continue;
		bvec[i] = true;
		bt(vec, bvec, i, cnt + 1);
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
		vec[i] = i + 1;
	bt(vec, bvec, 0, 0);
}
