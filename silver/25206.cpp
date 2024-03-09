#include <iostream>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

double	getResult(string str, double credit) {
	string grades[] = {"A+", "A0", "B+", "B0", "C+", "C0", "D+", "D0", "F"};

	for (int i = 0; i < 10; i++) {
		if (str == grades[i])
		{
			if (str == "F")
				return (0);
			else
				return ((4.5 - (i * 0.5)) * credit);
		}
	}
	return (-1);
}

int	main() {
	double	resultAdd = 0;
	double	credit = 0;
	double	GPA = 0;

	string str;
	for (int i = 0; i < 20; i++) {
		getline(cin, str);
		string::size_type SpacePos = str.find(' ');
		str = str.substr(SpacePos + 1);
		SpacePos = str.find(' ');
		double	tempCredit = stod(str.substr(0, 3));
		str = str.substr(SpacePos + 1);
		double	result = getResult(str, tempCredit);
		if (result == -1)
			continue;
		resultAdd += result;
		credit += tempCredit;
	}
	GPA = resultAdd / credit;
	cout << GPA << '\n';
}
