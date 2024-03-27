#include <iostream>
#include <deque>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
	fastio;
	int N; cin >> N;
	deque<int> dq;

	while (N--) {
		int cmd; cin >> cmd;
		if (cmd == 1 || cmd == 2) {
			int arg; cin >> arg;
			if (cmd == 1)
				dq.push_front(arg);
			else
				dq.push_back(arg);
		}
		else if (cmd == 3) {
			if (dq.size()) {
				cout << dq.front() << '\n';
				dq.pop_front();
			}
			else
				cout << -1 << '\n';
		}
		else if (cmd == 4) {
			if (dq.size()) {
				cout << dq.back() << '\n';
				dq.pop_back();
			}
			else
				cout << -1 << '\n';
		}
		else if (cmd == 5)
			cout << dq.size() << '\n';
		else if (cmd == 6)
			cout << dq.empty() << '\n';
		else if (cmd == 7) {
			if (dq.size())
				cout << dq.front() << '\n';
			else
				cout << -1 << '\n';
		}
		else if (cmd == 8) {
			if (dq.size())
				cout << dq.back() << '\n';
			else
				cout << -1 << '\n';
		}
	}
}
