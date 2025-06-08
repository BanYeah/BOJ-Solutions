#include <iostream>
#include <vector>
#include <climits>

using namespace std;

vector<pair<int, int>> vec[50];
long long money[50];
long long income[50];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, A, B, M;
    cin >> N >> A >> B >> M;

    int u, v, w;
    for (int i = 0; i < M; i++) {
        cin >> u >> v >> w;
        vec[u].push_back({v, w});
    }

    int m;
    for (u = 0; u < N; u++) {
        cin >> m;
        money[u] = m;
    }

    for (u = 0; u < N; u++)
        income[u] = LONG_LONG_MIN;
    income[A] = money[A];

    // 벨만-포드 알고리즘
    for (int i = 0; i < N*2; i++) {
        for (u = 0; u < N; u++) {
            if (income[u] == LONG_LONG_MIN)
                continue;

            for (auto p : vec[u]) {
                v = p.first;
                w = p.second;

                if (income[u] == LONG_LONG_MAX)
                    income[v] = LONG_LONG_MAX;
                else if (income[v] < income[u] + money[v] - w) {
                    income[v] = income[u] + money[v] - w;

                    if (i >= N-1)
                        income[v] = LONG_LONG_MAX;
                }
            }
        }
    }

    if (income[B] == LONG_LONG_MIN)
        cout << "gg\n";
    else if (income[B] == LONG_LONG_MAX)
        cout << "Gee\n";
    else
        cout << income[B] << "\n";
}