#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[300001];
char visited[300001] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K, X;
    cin >> N >> M >> K >> X;

    int u, v;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        vec[u].push_back(v);
    }

    // BFS 수행
    int level = 0;
    queue<int> q;
    q.push(X);
    q.push(-1); // level 표시용
    visited[X] = 1;

    vector<int> ans;
    while (!q.empty()) {
        v = q.front();
        q.pop();

        if (v == -1) {
            level++;
            if (!q.empty())
                q.push(-1);
        } else if (level == K)
            ans.push_back(v);
        else {
            for (int i = 0; i < vec[v].size(); i++) {
                u = vec[v].at(i);
                if (!visited[u]) {
                    q.push(u);
                    visited[u] = 1;
                }
            }
        }
    }

    sort(ans.begin(), ans.end());

    if (ans.size() == 0)
        cout << -1 << "\n";
    else {
        for (int i = 0; i < ans.size(); i++)
            cout << ans.at(i) << "\n";
    }
}