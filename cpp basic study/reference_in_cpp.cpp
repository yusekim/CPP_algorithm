#include <iostream>
using namespace std;
/*
int main()
{
	int	a = 3;
	int &another_a = a;

	another_a = 5;
	cout << "a : " << a << '\n';
	cout << "another_a : " << another_a << '\n';

	return (0);
}

int change_val(int &p)
{
	p = 3;

	return 0;
}
int main()
{
	int	number = 5;

	cout << number << '\n';
	change_val(number);
	cout << number << '\n';
}*/

int main()
{
	int x;
	int &y = x;
	int &z = y;

	x = 1;
	cout << "x : " << x << " y : " << y << " z :" << z << '\n';

	y = 2;
	cout << "x : " << x << " y : " << y << " z :" << z << '\n';

	z = 3;
	cout << "x : " << x << " y : " << y << " z :" << z << '\n';
}