#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;
int N, M, val;
vector<pair<int, int>> house, chicken;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> val;
			if (val == 1)
				house.push_back(make_pair(i, j));
			if (val == 2)
				chicken.push_back(make_pair(i, j));
		}
	}
	val = chicken.size();
	vector<vector<pair<int, int>>> comb;
	vector<bool> mask(val);
	fill(mask.begin(), mask.begin() + M, false);
	fill(mask.begin() + M, mask.end(), true);
	do {
		vector<pair<int, int>> cur_comb;
		for (int i = 0; i < val; i++)
			if (!mask[i])
				cur_comb.push_back(chicken[i]);
		comb.push_back(cur_comb);
	} while(next_permutation(mask.begin(), mask.end()));
	val = INT_MAX;
	for (const auto& c : comb)
	{
		int temp = 0;
		for (auto it = house.begin(); it != house.end(); it++)
		{
			int min_d = INT_MAX;
			for (auto it2 = c.begin(); it2 != c.end(); it2++)
			{
				int dist = abs((*it).first - (*it2).first) + abs((*it).second - (*it2).second);
				if (min_d > dist)
					min_d = dist;
			}
			temp += min_d;
		}
		if (val > temp)
			val = temp;
	}
	cout << val << '\n';
}



/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits> // INT_MAX 사용

using namespace std;

int N, M;
vector<pair<int, int>> house, chicken;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M;

    int input_val; // 입력용 변수 별도 선언
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> input_val;
            if (input_val == 1)
                house.push_back({i, j});
            if (input_val == 2)
                chicken.push_back({i, j});
        }
    }

    int chicken_cnt = chicken.size();

    // M개를 뽑기 위한 마스크 (0: 선택, 1: 비선택) -> 오름차순 정렬 필요
    vector<bool> mask(chicken_cnt);
    fill(mask.begin(), mask.begin() + M, false); // 앞 M개 선택
    fill(mask.begin() + M, mask.end(), true);    // 나머지 비선택 (범위 수정됨!)

    int min_city_chicken_dist = INT_MAX; // 결과값 (아주 큰 값으로 초기화)

    do {
        int current_city_dist = 0;

        // 현재 조합에 대해 도시의 치킨 거리 계산
        for (const auto& h : house)
        {
            int min_dist_for_house = INT_MAX; // 각 집의 치킨 거리

            for (int i = 0; i < chicken_cnt; i++)
            {
                if (!mask[i]) // 선택된 치킨집만 계산 (false가 선택된 것)
                {
                    int dist = abs(h.first - chicken[i].first) + abs(h.second - chicken[i].second);
                    if (min_dist_for_house > dist)
                        min_dist_for_house = dist;
                }
            }
            current_city_dist += min_dist_for_house;
        }

        // 최솟값 갱신
        if (min_city_chicken_dist > current_city_dist)
            min_city_chicken_dist = current_city_dist;

    } while(next_permutation(mask.begin(), mask.end()));

    cout << min_city_chicken_dist << '\n';

    return 0;
}*/
