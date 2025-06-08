#include <iostream>
#include <climits>

using namespace std;

int matrix[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) matrix[i][j] = 0;
            else matrix[i][j] = INT_MAX;
        }
    }

    int u, v, w;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        if (matrix[u][v] == INT_MAX || matrix[u][v] > w)
            matrix[u][v] = w;
    }

    // 플로이드-워셜 알고리즘
    for (int k = 1; k <= N; k++) { // K: 경유지
        for (int s = 1; s <= N; s++) { // S: 출발지
            for (int e = 1; e <= N; e++) { // E: 도착지
                if (matrix[s][k] == INT_MAX || matrix[k][e] == INT_MAX)
                    continue;

                if (matrix[s][e] > matrix[s][k] + matrix[k][e])
                    matrix[s][e] = matrix[s][k] + matrix[k][e];
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (matrix[i][j] == INT_MAX)
                cout << 0 << " ";
            else
                cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}