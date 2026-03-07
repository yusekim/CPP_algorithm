#include <iostream>
#include <cstring>
using namespace std;
int N;
long long B;
int mat[37][5][5], res[5][5], temp[5][5];

void compute(int A[5][5], int B[5][5], int C[5][5])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
				C[i][j] += (A[i][k] % 1000) * (B[k][j] % 1000) % 1000;
			C[i][j] %= 1000;
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> B;

	memset(mat, 0, sizeof(mat));
	memset(res, 0, sizeof(res));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> mat[0][i][j];
		res[i][i] = 1;
	}

	for (int i = 0; i < 36; i++)
		compute(mat[i], mat[i], mat[i + 1]);

	int cnt = 0;
	while (B)
	{
		if (B & 1)
		{
			memset(temp, 0, sizeof(temp));
			compute(mat[cnt], res, temp);
			memcpy(res, temp, sizeof(res));
		}
		B >>= 1;
		cnt++;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << res[i][j] % 1000 << ' ';
		cout << '\n';
	}
}
