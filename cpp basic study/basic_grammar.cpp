#include <iostream>
using namespace std;

int main()
{
	int	lucky_number = 3;
	int	user_input;

	cout << "Guess my lucky number!" << '\n';
	while (1)
	{
		cout << "Take a guess : ";
		cin >> user_input;
		if (lucky_number == user_input)
		{
			cout << "You find my lucky number!! congrats!" << '\n';
			break ;
		}
		else
			cout << "Try another guess!" << '\n';
	}
	return (0);
}