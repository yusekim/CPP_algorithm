#include <iostream>
#include <stack>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
	fastio;
	int K; cin >> K;
	stack<int> stk;

	while (K--) {
		int val; cin >> val;
		if (val == 0)
			stk.pop();
		else
			stk.push(val);
	}
	int res = 0;
	while (stk.size()) {
		res += stk.top();
		stk.pop();
	}
	cout << res << '\n';
}
