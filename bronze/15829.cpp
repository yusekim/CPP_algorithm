#include <iostream>
#include <string>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N;
	unsigned long long res = 0;
	string str;
	cin >> N >> str;
	for (int i = N - 1; i >= 0; i--)
		res = res * 31 % 1234567891 + (str[i] - 'a' + 1);
	cout << res << '\n';
}
