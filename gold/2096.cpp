#include <iostream>
using namespace std;
int N;
int arr[100000][3], maxarr[3], minarr[3];

void dp()
{
	for (int i = 1; i < N; i++)
	{
		int a = maxarr[0], b = maxarr[1], c = maxarr[2];
		maxarr[0] = arr[i][0] + max(a, b);
		maxarr[1] = arr[i][1] + max(max(a, b), c);
		maxarr[2] = arr[i][2] + max(b, c);
		a = minarr[0];
		b = minarr[1];
		c = minarr[2];
		minarr[0] = arr[i][0] + min(a, b);
		minarr[1] = arr[i][1] + min(min(a, b), c);
		minarr[2] = arr[i][2] + min(b, c);
	}
	cout << max(max(maxarr[0], maxarr[1]), maxarr[2]) << ' ' << min(min(minarr[0], minarr[1]), minarr[2]) << '\n';
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin	>> N;
	for (int i = 0; i < N; i++)
	{
		int a, b, c;
		for (int j = 0; j < 3; j++)
			cin >> arr[i][j];
	}
	for (int i = 0; i < 3; i++)
	{
		maxarr[i] = arr[0][i];
		minarr[i] = arr[0][i];
	}
	dp();
}
