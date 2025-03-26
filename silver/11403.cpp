#include <iostream>
using namespace std;

int arr[100][100];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];


	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] == 0 && arr[i][k] + arr[k][j] > 1)
					arr[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout <<  arr[i][j] << ' ';
		cout << '\n';
	}
}
