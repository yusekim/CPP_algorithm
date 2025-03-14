#include <iostream>
#include <unordered_map>
using namespace std;
int arr[200000];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int left = 0, right = 0, res = 0;
	unordered_map<int, int> umap;
	while (right < n)
	{
		umap[arr[right]]++;
		while (umap.size() > 2)
		{
			umap[arr[left]]--;
			if (umap[arr[left]] == 0)
				umap.erase(arr[left]);
			left++;
		}
		res = max(res, right - left + 1);
		right++;
	}
	cout << res << '\n';
}
