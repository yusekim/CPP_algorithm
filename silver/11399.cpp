#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;
	vector<int> vec;
	while (N--)
	{
		int input;
		cin >> input;
		vec.push_back(input);
	}
	sort(vec.begin(), vec.end());
	int res = vec[0];
	for (int i = 1; i < vec.size(); i++)
	{
		vec[i] += vec[i - 1];
		res += vec[i];
	}
	cout << res << '\n';
}
