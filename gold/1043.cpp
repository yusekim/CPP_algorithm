#include <iostream>
#include <vector>
using namespace std;
int N, M, num;
vector<vector<int>> parties;

class unifind
{
	vector<int> par;
public:
	unifind(int size)
	{
		par.resize(size + 1);
		for (int i = 1; i <= size; i++)
			par[i] = i;
	}
	int find(int i)
	{
		if (par[i] == i)
			return i;
		return find(par[i]);
	}
	void unite(int i, int j)
	{
		int irep = find(i);
		int jrep = find(j);
		par[irep] = jrep;
	}
};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M >> num;
	if (num == 0)
	{
		cout << M << '\n';
		return 0;
	}
	vector<int> knowers;
	for (int i = 0; i < num; i++)
	{
		int idx;
		cin >> idx;
		knowers.push_back(idx);
	}
	unifind uf(N);
	for (int i = 0; i < M; i++)
	{
		int cnt;
		cin >> cnt;
		vector<int> party(cnt);
		for (int j = 0; j < cnt; j++)
		{
			cin >> party[j];
			if (j > 0)
				uf.unite(party[j], party[j - 1]);
		}
		parties.push_back(party);
	}
	int res = M;
	for (auto it = parties.begin(); it != parties.end(); it++)
	{
		for (int i = 0; i < num; i++)
		{
			if (uf.find(knowers[i]) == uf.find((*it)[0]))
			{
				res--;
				break;
			}
		}
	}
	cout << res << '\n';
}
