#include <iostream>
#include <algorithm>

struct Triple {
    int first = 0;
    int second;
    int third;
};

Triple arr[40];

void getfibonum(int n, int *zero, int *one)
{
	if (n < 0)
		return ;
	if (arr[n].first)
	{
		*zero += arr[n].second;
		*one += arr[n].third;
		return ;
	}
	else
	{
			getfibonum(n - 1, zero, one);
			getfibonum(n - 2, zero, one);
			arr[n].first = 1;
			arr[n].second = *zero;
			arr[n].third = *one;
			return;
	}
}

int main()
{
	int N, M, one, zero;
	std::cin >> N;
	arr[0].first = 1;
	arr[1].first = 1;
	arr[0].second = 1;
	arr[1].second = 0;
	arr[0].third = 0;
	arr[1].third = 1;
	while (N--)
	{
		zero = 0;
		one = 0;
		std::cin >> M;
		getfibonum(M, &zero, &one);
		std::cout << zero << ' ' << one << '\n';
	}
}
