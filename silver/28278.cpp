#include <iostream>
#include <stack>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
	fastio;
	int N; cin >> N;
	stack<int> stk;

	while (N--) {
		int temp; cin >> temp;
		switch (temp)
		{
		case 1:
			int n; cin >> n;
			stk.push(n);
			break;
		case 2:
			if (stk.size()) {
				cout << stk.top() << '\n';
				stk.pop();
			}
			else
				cout << -1 << '\n';
			break;
		case 3:
			cout << stk.size() << '\n';
			break;
		case 4:
			if (stk.empty())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
			break;
		case 5:
			if (stk.size())
				cout << stk.top() << '\n';
			else
				cout << -1 << '\n';
		default:
			break;
		}
	}
}
