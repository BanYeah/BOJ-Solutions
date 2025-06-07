#include <iostream>
#include <stack>
#include <queue>

using namespace std;

char vertices[1001][1001] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    int v, u;
    for (int i = 0; i < M; i++) {
        cin >> v >> u;
        vertices[v][u] = 1;
        vertices[u][v] = 1;
    }

    // DFS 수행 (stack 이용)
    char visited1[10001] = {};
    stack<int> st;
    st.push(V);
    while (!st.empty()) {
        v = st.top();
        st.pop();

        if (visited1[v] == 0) {
            visited1[v] = 1;
            cout << v << " ";
        }

        for (int i = N; i > 0; i--) {
            if (vertices[v][i] == 1 && visited1[i] == 0)
                st.push(i);
        }
    }
    cout << "\n";

    // BFS 수행 (queue 이용)
    char visited2[10001] = {};
    queue<int> q;
    q.push(V);
    while (!q.empty()) {
        v = q.front();
        q.pop();

        if (visited2[v] == 0) {
            visited2[v] = 1;
            cout << v << " ";
        }

        for (int i = 1; i <= N; i++) {
            if (vertices[v][i] == 1 && visited2[i] == 0)
                q.push(i);
        }
    }
    cout << "\n";
}