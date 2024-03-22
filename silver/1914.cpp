#include <iostream>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

void hanoi(int target, int pos, int dest) {
	if (target == 1) {
		cout << pos + 1 << ' ' << dest + 1 << '\n';
		return ;
	}
	hanoi(target - 1, pos, 3 - (pos + dest));
	cout << pos + 1 << ' ' << dest + 1 << '\n';
	hanoi(target - 1, 3 - (pos + dest), dest);
}

void getNum(string& num, int idx) {
	if (idx == 0) {
		int i = num.size() - 1;
		num[i] -= 1;
		cout << num << '\n';
		return ;
	}
	else {
		string res;
		int carry = 0;
		for (int i = num.size() - 1; i >= 0; i--) {
			int digit = num[i] - '0';
			int product = digit * 2 + carry;
			res.insert(res.begin(), '0' + product % 10);
			carry = product / 10;
		}
		if (carry) {
			res.insert(res.begin(), '0' + carry);
		}
		getNum(res, idx - 1);
	}
}

int	main() {
	fastio;
	int N; cin >> N;
	string num = "1";
	getNum(num, N);
	if (N <= 20)
		hanoi(N, 0, 2);
}
