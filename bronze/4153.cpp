#include <iostream>
#include <set>
#include <cmath>

int main()
{
	std::multiset<int> set;
	while (true)
	{
		for (int i = 0; i < 3; i++)
		{
			int input;
			std::cin >> input;
			set.insert(input);
		}
		if (*set.begin() == 0 && *std::prev(set.end()) == 0)
			break;
		auto it = set.begin();
		int a = *it++;
		int b = *it++;
		int c = *it;
		if (a * a + b * b == c * c)
			std::cout << "right\n";
		else
			std::cout << "wrong\n";
		set.clear();
	}
}
