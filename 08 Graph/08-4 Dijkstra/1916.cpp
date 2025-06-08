#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<pair<int, int>> vec[1001];
bool visited[1001] = {};
int dist[1001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int u, v, w;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        vec[u].push_back({v, w});
    }

    int U, V;
    cin >> U >> V;

    for (int i = 1; i <= N; i++)
        dist[i] = INT_MAX;
    dist[U] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 최단거리 | 정점 번호 (Min-heap)
    pq.push({0, U});

    while (!pq.empty()) {
        u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;

        for (auto p : vec[u]) {
            v = p.first;
            w = p.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            } 
        }
    }

    cout << dist[V] << "\n";
}