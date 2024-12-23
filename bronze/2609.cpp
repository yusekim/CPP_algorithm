#include <iostream>
#include <cmath>

int gcd(int n, int m)
{
	while (m != 0)
	{
		int temp = m;
		m = n % m;
		n = temp;
	}
	return n;
}

int main()
{
	int N, M, GCD, LCM;

	std::cin >> N >> M;
	GCD = gcd(N, M);
	LCM = N * M / GCD;

	std::cout << GCD << '\n' << LCM << '\n';
}
