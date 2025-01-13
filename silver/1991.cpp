#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N;

void f(vector<vector<int> > &tree, int start)
{
	if (start < 0)
		return;
	else
	{
		cout << (char)(start + 'A');
		f(tree, tree[start][0]);
		f(tree, tree[start][1]);
	}
}

void m(vector<vector<int> > &tree, int start)
{
	if (start < 0)
		return;
	else
	{
		m(tree, tree[start][0]);
		cout << (char)(start + 'A');
		m(tree, tree[start][1]);
	}
}

void e(vector<vector<int> > &tree, int start)
{
	if (start < 0)
		return;
	else
	{
		e(tree, tree[start][0]);
		e(tree, tree[start][1]);
		cout << (char)(start + 'A');
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	vector<vector<int> > tree(26, vector<int>(3, -1));
	while (N--)
	{
		char node, left, right;
		cin >> node >> left >> right;
		tree[(int)node - 'A'][0] = (int)left - 'A';
		tree[(int)node - 'A'][1] = (int)right - 'A';
		if ((int)left - 'A' > 0)
			tree[(int)left - 'A'][2] = (int)node - 'A';
		if ((int)right - 'A' > 0)
			tree[(int)right - 'A'][2] = (int)node - 'A';
	}
	f(tree, 0);
	cout << '\n';
	m(tree, 0);
	cout << '\n';
	e(tree, 0);
	cout << '\n';
}
