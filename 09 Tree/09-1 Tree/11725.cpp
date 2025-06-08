#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[100001];
bool visited[100001] = {};
int parent[100001] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int u, v;
    for (int i = 0; i < N-1; i++) {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int p = q.front(); // parent
        q.pop();

        for (int c : vec[p]) { // child
            if (!visited[c]) {
                parent[c] = p;

                q.push(c);
                visited[c] = 1;
            }
        }
    }

    for (int i = 2; i <= N; i++) 
        cout << parent[i] << "\n";
}