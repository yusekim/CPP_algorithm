#include <iostream>
#include <unordered_set>
#include <sstream>


std::unordered_set<int> set;

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M, val;
	std::string str;

	std::cin >> N;
	set.reserve(N);
	std::cin >> std::ws;
	std::getline(std::cin, str);
	std::istringstream iss(str);
	while (iss >> val)
		set.insert(val);
	std::cin >> M;
	std::cin >> std::ws;
	std::getline(std::cin, str);
	std::istringstream iss2(str);
	while (iss2 >> val)
	{
		if (set.find(val) == set.end())
			std::cout << 0 << '\n';
		else
			std::cout << 1 << '\n';
	}
}
