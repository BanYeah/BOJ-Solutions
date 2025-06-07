#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> vec[2000];
int visited[2000] = {};

void follow_path(int v, int path) {
    visited[v] = 1;

    for (int i = 0; i < vec[v].size(); i++) {
        int u = vec[v].at(i);
        if (visited[u] == 0) {
            if (path + 1 >= 4) {
                cout << 1 << "\n";
                exit(0); // 즉시 반환하지 않으면, 백트래킹으로 인해 시간 초과
            }
            follow_path(u, path + 1);
        }
    }

    visited[v] = 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    // 모든 정점에 대해 DFS 수행
    for (int i = 0; i < N; i++) {
        follow_path(i, 0);
    }
    cout << 0 << "\n";
}