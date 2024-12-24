#include <iostream>

using namespace std;

void getval(int N, int r, int c, int count)
{
	int half_size = 1, tmp_count = 0;
	for (int i = 1; i < N; i++)
		half_size *= 2;
	if (c >= half_size)
	{
		tmp_count += 1;
		c -= half_size;
	}
	if (r >= half_size)
	{
		tmp_count += 2;
		r -= half_size;
	}
	if (N == 1)
		cout << count + tmp_count << '\n';
	else
		getval(N - 1, r, c, count + tmp_count * half_size * half_size);
	return;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N, r, c;
	cin >> N >> r >> c;
	getval(N, r, c, 0);
}
