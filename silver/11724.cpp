#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool bfs(vector<vector<int>>& graph, vector<bool>& visited, int idx) {
    if (visited[idx]) return false;
    std::queue<int> que;
    que.push(idx);
    visited[idx] = true;

    while (!que.empty()) {
        int top = que.front();
        que.pop();

        for (int neighbor : graph[top]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                que.push(neighbor);
            }
        }
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int N, M, res = 0;
    cin >> N >> M;

    vector<vector<int>> graph(N);
    vector<bool> visited(N, false);

    for (int i = 0; i < M; i++) {
        int node1, node2;
        cin >> node1 >> node2;
        node1--; node2--;
        graph[node1].push_back(node2);
        graph[node2].push_back(node1);
    }

    for (int i = 0; i < N; i++) {
        if (bfs(graph, visited, i)) {
            res++;
        }
    }

    cout << res << '\n';
}
