#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	unordered_map<string, string> m;
	while (N--)
	{
		string url, pw;
		cin >> url >> pw;
		m[url] = pw;
	}
	while (M--)
	{
		string target;
		cin >> target;
		cout << m[target] << '\n';
	}
}
