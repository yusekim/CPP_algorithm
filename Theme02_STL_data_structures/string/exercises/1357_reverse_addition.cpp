#include <iostream>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	string a, b;
	cin >> a >> b;
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	string ans = to_string(stoi(a) + stoi(b));
	while (ans.size() && ans.back() == '0')
		ans.pop_back();
	reverse(ans.begin(), ans.end());
	cout << ans <<'\n';
}
