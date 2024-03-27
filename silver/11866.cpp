#include <iostream>
#include <queue>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
	int N, K; cin >> N >> K;
	queue<int> Q;

	for (int i = 1; i <= N; i++)
		Q.push(i);
	cout << '<';
	while (Q.size()) {
		for (int i = 1; i < K; i++) {
			Q.push(Q.front());
			Q.pop();
		}
		cout << Q.front();
		Q.pop();
		if (Q.size())
			cout << ", ";
	}
	cout << ">\n";
}
