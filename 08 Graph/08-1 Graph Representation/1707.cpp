#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    cin >> K;

    for (int k = 0; k < K; k++) {
        vector<int> vec[20001];

        int V, E;
        cin >> V >> E;

        int u, v;
        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        char visited[20001] = {};
        int visited_sum = 0;
        queue<int> q;

        bool flag = true;
        while (visited_sum < V) {
            for (v = 1; v <= V; v++) {
                if (!visited[v]) {
                    q.push(v);
                    visited[v] = 'a';
                    visited_sum++;
                    break;
                }
            }

            while (!q.empty()) {
                v = q.front();
                q.pop();

                for (int i = 0; i < vec[v].size(); i++) {
                    u = vec[v].at(i);
                    if (!visited[u]) {
                        q.push(u);
                        if (visited[v] == 'a')
                            visited[u] = 'b';
                        else
                            visited[u] = 'a';
                        visited_sum++;
                    } else if (visited[v] == visited[u]) {
                        cout << "NO\n";
                        flag = false;
                        break;
                    }
                }
                if (!flag) break;
            }
            if (!flag) break;
        }
        if (flag) cout << "YES\n";
    }
}