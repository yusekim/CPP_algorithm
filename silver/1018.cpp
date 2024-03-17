#include <iostream>
#include <string>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;


int	get_square_num(string *board, int i, int j) {

	char startcol = 'W';
	int Wres = 0;
	for (int a = 0; a < 8; a++) {
		for (int b = 0; b < 8; b++) {
			if ((a % 2 == 0 && b % 2 == 0 && board[i + a][j + b] != startcol) ||
				(a % 2 && b % 2 && board[i + a][j + b] != startcol))
				Wres++;
			if ((a % 2 == 0 && b % 2 && board[i + a][j + b] == startcol) ||
				(a % 2 && b % 2 == 0 && board[i + a][j + b] == startcol))
				Wres++;
		}
	}
	startcol = 'B';
	int Bres = 0;
	for (int a = 0; a < 8; a++) {
		for (int b = 0; b < 8; b++) {
			if ((a % 2 == 0 && b % 2 == 0 && board[i + a][j + b] != startcol) ||
				(a % 2 && b % 2 && board[i + a][j + b] != startcol))
				Bres++;
			if ((a % 2 == 0 && b % 2 && board[i + a][j + b] == startcol) ||
				(a % 2 && b % 2 == 0 && board[i + a][j + b] == startcol))
				Bres++;
		}
	}
	return (Wres < Bres) ? Wres : Bres;
}

int	main() {
	fastio;
	int	N, M; cin >> N >> M;

	string *board = new string [N];

	for (int i = 0; i < N; i++) {
		cin >> board[i];
	}

	int res = 64;
	for (int i = 0; (N - i >= 8) && res > 0; i++) {
		for (int j = 0; M - j >= 8; j++) {
			int temp = get_square_num(board, i, j);
			if (temp < res)
				res = temp;
		}
	}
	cout << res << '\n';
	return 0;
}
