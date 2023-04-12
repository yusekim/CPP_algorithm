#include <iostream>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	int	cnt = 0;
	for (string s; cin >> s; cnt++);
	cout << cnt << '\n';
}
