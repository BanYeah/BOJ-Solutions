#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<pair<int, int>> vec[20001];
char visited[20001] = {};
int dist[20001];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, K;
    cin >> V >> E >> K;

    int u, v, w;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        vec[u].push_back(pair<int, int>(v, w));
    }

    for (int i = 1; i <= V; i++) {
        dist[i] = INT_MAX; // INF
    }
    dist[K] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // 정점 번호 | 거리
    pq.push({0, K});

    pair<int, int> k;
    while (!pq.empty()) {
        k = pq.top();
        pq.pop();

        if (visited[k.second]) continue;
        visited[k.second] = 1;

        for (pair<int, int> p : vec[k.second]) { // k -> p
            v = p.first;
            if (dist[v] > dist[k.second] + p.second) {
                dist[v] = dist[k.second] + p.second;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= V; i++) {
        if (dist[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
}