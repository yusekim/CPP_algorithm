#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<int> vec(N);
    for (int i = 0; i < N; ++i) {
        cin >> vec[i];
    }

    int low = 0, high = *max_element(vec.begin(), vec.end());
    int res = 0;

    while (low <= high) {
        int mid = (low + high) / 2;
        long cut = 0;

        for (int height : vec) {
            if (height > mid) {
                cut += height - mid;
            }
        }

        if (cut >= M) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << res << '\n';
    return 0;
}
