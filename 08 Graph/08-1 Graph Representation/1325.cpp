#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[10001];
int imp[10001] = {}; // importance

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int u, v;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        vec[v].push_back(u);
    }

    // BFS 수행
    for (int i = 1; i <= N; i++) {
        queue<int> q;
        int visited[10001] = {};

        q.push(i);
        visited[i] = 1;

        while (!q.empty()) {
            v = q.front();
            q.pop();

            for (int j = 0; j < vec[v].size(); j++) {
                u = vec[v].at(j);
                if (!visited[u]) {
                    q.push(u);
                    visited[u] = 1;
                }
            }
        }

        int sum = 0;
        for (int j = 1; j <= N; j++) {
            if (visited[j])
                sum++;
        }
        imp[i] = sum;
    }

    // 최대 importance를 갖는 정점 파악
    int max_imp = 0;
    vector<int> ans;
    for (int i = 1; i <= N; i++) {
        if (imp[i] == max_imp)
            ans.push_back(i);
        else if (imp[i] > max_imp) {
            max_imp = imp[i];
            ans.clear();
            ans.push_back(i);
        }
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++)
        cout << ans.at(i) << " ";
    cout << "\n";
}