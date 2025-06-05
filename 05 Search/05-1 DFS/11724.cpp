#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> vec[1001];
int visited[1001] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int u, v;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    int visited_sum = 0, count = 0;
    stack<int> st;
    while (visited_sum < N) {
        count++; // 연결 요소의 수

        int n = 1;
        for (; n <= N && visited[n] != 0; n++);
        st.push(n);

        do {
            n = st.top();
            st.pop();

            if (visited[n] == 0) {
                visited_sum++; // 방문한 정점의 수
                visited[n] = 1;
            }

            for (int i = 0; i < vec[n].size(); i++) {
                v = vec[n].at(i); 
                if (visited[v] == 0)
                    st.push(v);
            }
        } while (!st.empty());
    }

    cout << count << "\n";
}   