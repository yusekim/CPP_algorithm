#include <iostream>
#include <vector>
#include <sstream>

int main()
{
	int N;
	double max, score, sum = 0;
	std::string line;
	std::vector<int> V;


	std::cin >> N;
    std::cin >> std::ws;
	std::getline(std::cin, line);
	std::istringstream iss(line);
	while (iss >> score)
	{
		if (score > max)
			max = score;
		V.push_back(score);
	}
	for (auto it = V.begin(); it != V.end(); ++it)
		sum += (*it / max) * 100;
	std::cout << sum / static_cast<double>(N) << std::endl;
}
