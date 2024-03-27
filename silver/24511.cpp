#include <iostream>
#include <deque>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

bool flag[100001];

int main() {
	fastio;
	int N; cin >> N;
	deque<int> dq;

	for (int i = 1; i <= N; i++) {
		int type; cin >> type;
		flag[i] = type;
	}
	for (int i = 1; i <= N; i++) {
		int arg; cin >> arg;
		if (flag[i] == 0)
			dq.push_back(arg);
	}
	int M; cin >> M;
	while (M--) {
		int arg; cin >> arg;
		dq.push_front(arg);
		cout << dq.back() << ' ';
		dq.pop_back();
	}
	cout << '\n';
}
