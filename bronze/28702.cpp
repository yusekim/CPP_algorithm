#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int val;
	string a, b, c, out = "";
	cin >> a >> b >> c;
	if (a != "Fizz" && a != "Buzz" && "FizzBuzz")
		val = atoi(a.c_str()) + 3;
	else if (b != "Fizz" && b != "Buzz" && "FizzBuzz")
		val = atoi(b.c_str()) + 2;
	else
		val = atoi(c.c_str()) + 1;
	if (val % 3 == 0)
		out.append("Fizz");
	if (val % 5 == 0)
		out.append("Buzz");
	if (out.size())
		cout << out << '\n';
	else
		cout << val << '\n';
}
