#include <iostream>
#include <vector>

using namespace std;
int N, M;

void print(vector<int> &vec, vector<int> &cvec)
{
	int i;
	for (i = 0; i < N; i++)
		for (int j = 0; j < cvec[i]; j++)
			cout << vec[i] << ' ';
	cout << '\n';
}

void bt(vector<int> &vec, vector<int> &cvec, int val, int cnt)
{
	if (cnt == M)
		return print(vec, cvec);
	for (int i = val; i < N; i++)
	{
		cvec[i] += 1;
		bt(vec, cvec, i, cnt + 1);
		cvec[i] -= 1;
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	vector<int> vec(N);
	vector<int> cvec(N, 0);
	for (int i = 0; i < N; i++)
		vec[i] = i + 1;
	bt(vec, cvec, 0, 0);
}
