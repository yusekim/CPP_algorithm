#include <iostream>
#include <sstream>
#include <iomanip>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	ostringstream out;
	out << "Hello World!" << '\n';
	out << setw(5) << setfill ('0') << 123 << '\n';
	out << fixed << setprecision(10) << 123.456789 << '\n';
	string s = out.str();
	cout << s << '\n';
}