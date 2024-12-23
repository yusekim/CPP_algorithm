#include <iostream>
#include <vector>
int main()
{
	std::vector<int> shirtSizes;
	int N, tmp, T, P, shirt = 0, penPack, penIndiv;
	std::cin >> N;
	for (int i = 0; i < 6; i++)
	{
		std::cin >> tmp;
		shirtSizes.push_back(tmp);
	}
	std::cin >> T >> P;
	for (auto it = shirtSizes.begin(); it != shirtSizes.end(); it++)
		shirt += *it / T + (*it % T ? 1 : 0);
	penPack = N / P;
	penIndiv = N % P;

	std::cout << shirt << '\n' << penPack << ' ' << penIndiv << '\n';
}
