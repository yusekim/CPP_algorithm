#include <iostream>
#include <cmath>

int main()
{
	int N, K, a = 1, b = 1;
	std::cin >> N >> K;

	for (int i = 0; i < K; i++)
		a *= (N - i);
	for (int i = 0; i < K; i++)
		b *= (K - i);

	std::cout << (a / b) << '\n';
}
