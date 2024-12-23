#include <iostream>
#include <cmath>

int isPrime(int value)
{
	if (value <= 1)	return 0;
	for (int i = 2; i <= sqrt(value); ++i)
		if (value % i == 0) return 0;
	return 1;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, val, res = 0;;
	std::cin >> N;

	for (int i = 0; i < N; ++i)
	{
		std::cin >> val;
		res += isPrime(val);
	}

	std::cout << res << '\n';
}
