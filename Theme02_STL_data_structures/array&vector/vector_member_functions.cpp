#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main()
{
	fastio;
	vector<int> v(3), t(2,5);
	// v = { 0, 0, 0 }, t = { 5, 5 }

	vector<vector<int> > w(2, vector<int>(3, -1));
	// w = { { -1, -1, -1 }, { -1, -1, -1 } }

	v.push_back(1);
	// v = { 0, 0, 0, 1 }

	v.pop_back();
	// v = { 0, 0, 0 }

	v.insert(v.begin(), 2);
	// insert 2 at v[0], v = { 2, 0, 0, 0 }

	v.insert(v.begin() + 2, 3, 4);
	// insert { 4, 4, 4 } at v[2], v = { 2, 0, 4, 4, 4, 0, 0 }

	v.insert(v.begin(), t.begin(), t.end());
	// insert [t.begin(), t.end()) at v.begin(), v = { 5, 5, 2, 0, 4, 4, 4, 0, 0 }

	v.erase(v.begin() + 2);
	// erase v[2], v = { 5, 5, 0, 4, 4, 4, 0, 0 }

	v.erase(v.begin(), v.begin() + 6);
	// erase [v[0], v[6]), v = { 0, 0 }

	cout << "v.size() : " << v.size() << '\n';	// 2
	cout << "v.empty() ; " << v.empty() << '\n';	//0
	v.clear();	// v = { }
	v.resize(1); // v = { 0 }
	v.resize(3, 2);	// v = {0, 2, 2}
	v[1] = 1;	// v = { 0, 1, 2 }

	for (auto it = v.begin(); it != v.end(); it++)
		cout << "pos : " << it - v.begin() << ", v[pos] : " << *it << '\n';
	cout << '\n';

	for (auto it = v.rbegin(); it != v.rend(); it++)
		cout << "pos : " << it - v.rbegin() << ", v[pos] : " << *it << '\n';
	cout << '\n';

	cout << "v.front() : " << v.front() << '\n';	// 0
	cout << "v.back() :  " << v.back() << '\n';		// 2
}
