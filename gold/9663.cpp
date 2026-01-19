#include <iostream>
using namespace std;
// #include <cmath>
// int board[14];
int N, res = 0;

// void bt(int r)
// {
// 	if (r == N)
// 	{
// 		res++;
// 		return;
// 	}
// 	for (int i = 0; i < N; i++)
// 	{
// 		bool canPlace = true;
// 		for (int j = 0; j < r; j++)
// 		{
// 			if (board[j] == i || abs(r - j) == abs(board[j] - i))
// 			{
// 				canPlace = false;
// 				break;
// 			}
// 		}
// 		if (canPlace)
// 		{
// 			board[r] = i;
// 			bt(r + 1);
// 		}
// 	}
// }

bool col[15];
bool diag1[30];
bool diag2[30];

void bt(int r)
{
	if (r == N)
	{
		res++;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (col[i] || diag1[r - i + N - 1] || diag2[r + i])
			continue;
		col[i] = diag1[r - i + N - 1] = diag2[r + i] = true;
		bt(r + 1);
		col[i] = diag1[r - i + N - 1] = diag2[r + i] = false;
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	bt(0);
	cout << res << '\n';
}
