#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N, max = -4001, min = 4001;
	double sum = 0;
	cin >> N;
	vector<int> vec(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
		sum += vec[i];
		if (vec[i] > max)
			max = vec[i];
		if (vec[i] < min)
			min = vec[i];
	}
	sort(vec.begin(), vec.end());
	vector<int> mode;
	int count_max = 1;
	for (int i = 0; i < N; i++)
	{
		int cur = vec[i], count = 0;
		while (i < N && vec[i] == cur)
		{
			count++;
			i++;
		}
		i--;
		if (count >= count_max)
		{
			if (count > count_max)
			{
				mode.clear();
				count_max = count;
			}
			mode.push_back(vec[i]);
		}
	}
	cout << static_cast<int>(round(sum / N)) << '\n' << vec[N / 2] << '\n' << mode[mode.size() > 1 ? 1 : 0] << '\n' << max - min << '\n';
}
