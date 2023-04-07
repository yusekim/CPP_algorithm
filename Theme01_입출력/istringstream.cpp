#include <iostream>
#include <sstream>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace	std;

int main()
{
	fastio;
	istringstream in_1("123 456 789");
	int n;
	while (in_1 >> n) cout << n << '\n'; // 123\n456\n789

	istringstream in_2;
	string s = "hi my name is yuseung", t;
	in_2.str(s);
	cout << in_2.str() << '\n';	// hi my name is yuseung\n
	while (in_2 >> t) cout << t << '\n'; // hi\nmy\nmane\nis\nyuseung\n

	return (0);
}