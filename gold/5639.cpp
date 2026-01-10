#include <iostream>
#include <vector>
using namespace std;

// solution 1: build tree and trav
struct Node
{
	int val;
	int left = -1;
	int right = -1;
};

vector<Node> tree;

int build(int cur_idx, int val)
{
	if (cur_idx == -1)
	{
		tree.push_back({val, -1, -1});
		return tree.size() - 1;
	}
	if (val < tree[cur_idx].val)
		tree[cur_idx].left = build(tree[cur_idx].left, val);
	else
		tree[cur_idx].right = build(tree[cur_idx].right, val);
	return cur_idx;
}

void post_trav(int cur_idx)
{
	if (cur_idx == -1)
		return;
	post_trav(tree[cur_idx].left);
	post_trav(tree[cur_idx].right);
	cout << tree[cur_idx].val << '\n';
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int val, root_idx = -1;
	while (cin >> val)
		root_idx = build(root_idx, val);
	post_trav(root_idx);
}

// solution 2: divide and conquer
vector<int> preorder;

void solve(int start, int end)
{

	if (start >= end)
	{
		if (start == end)
			cout << preorder[start] << '\n';
		return;
	}
	int root = preorder[start];
	int r_start = start + 1;
	while (r_start <= end)
	{
		if (preorder[r_start] > root)
			break;
		r_start++;
	}
	solve(start + 1, r_start - 1);
	solve(r_start, end);
	cout << root << '\n';
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	while (cin >> n)
		preorder.push_back(n);
	if (preorder.size())
		solve(0, preorder.size() - 1);
}
