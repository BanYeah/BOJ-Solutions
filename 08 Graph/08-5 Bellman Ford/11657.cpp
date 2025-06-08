#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<pair<int, int>> vec[501];
long long dist[501]; // int로 선언 시, 500 * 6,000 * (-10,000)으로 오버플로우 발생

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    if (N == 1) return 0;

    int u, v, w;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        vec[u].push_back({v, w});
    }

    for (u = 1; u <= N; u++)
        dist[u] = LONG_LONG_MAX;
    dist[1] = 0;

    // 벨만-포드 알고리즘
    for (int i = 0; i < N - 1; i++) {
        for (u = 1; u <= N; u++) {
            if (dist[u] == LONG_LONG_MAX)
                continue;
            
            for (auto p : vec[u]) {
                v = p.first;
                w = p.second;

                if (dist[v] > dist[u] + w)
                    dist[v] = dist[u] + w;
            }
        }
    }

    // 음수 사이클 확인
    bool hasCycle = false;
    for (u = 1; u <= N && !hasCycle; u++) {
        if (dist[u] == LONG_LONG_MAX)
            continue;
        
        for (auto p : vec[u]) {
            v = p.first;
            w = p.second;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                hasCycle = true;
            }
        }
    }

    if (hasCycle)
        cout << -1 << "\n";
    else {
        for (u = 2; u <= N; u++) {
            if (dist[u] == LONG_LONG_MAX)
                cout << -1 << "\n";
            else
                cout << dist[u] << "\n";
        }
    }
}