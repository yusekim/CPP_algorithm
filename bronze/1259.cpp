#include <iostream>
#include <typeinfo>

void isPalindrome(std::string str)
{
	int i = 0, j = str.size() - 1;
	bool res = true;

	while (i < j)
	{
		if (str[i] != str[j]) {
			res = false;
			break ;
		}
		i++;
		j--;
	}
	if (res == true)
		std::cout << "yes" << std::endl;
	else
		std::cout << "no" << std::endl;
}

int main()
{
	std::string N;

	std::cin >> N;

	while (std::stoi(N) != 0)
	{
		isPalindrome(N);
		std::cin >> N;
	}
}
