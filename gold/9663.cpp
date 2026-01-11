#include <iostream>
#include <cmath>
using namespace std;
int board[14];
int N, res = 0;

void bt(int r)
{
	if (r == N)
	{
		res++;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		bool canPlace = true;
		for (int j = 0; j < r; j++)
		{
			if (board[j] == i || abs(r - j) == abs(board[j] - i))
			{
				canPlace = false;
				break;
			}
		}
		if (canPlace)
		{
			board[r] = i;
			bt(r + 1);
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	bt(0);
	cout << res << '\n';
}
