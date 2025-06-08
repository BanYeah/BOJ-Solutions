#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int time[501] = {};
int inDegree[501] = {};
vector<int> inVec[501];
vector<int> outVec[501];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, n, m;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> n;
        time[i] = n; // 각 건물을 짓는데 걸리는 시간

        // 그 건물을 짓기 위해 먼저 지어져야 하는 건물들의 번호
        while (true) {
            cin >> n;

            if (n == -1) 
                break;

            outVec[i].push_back(n); // i <- n
            inVec[n].push_back(i); // n -> i
            inDegree[i]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (inDegree[i] == 0)
            q.push(i);
    }

    while (!q.empty()) {
        n = q.front();
        q.pop();

        int max_time = 0;
        for (int i = 0; i < outVec[n].size(); i++) {
            m = outVec[n].at(i); // n <- m
            if (time[m] > max_time)
                max_time = time[m];
        }
        time[n] += max_time;

        for (int i = 0; i < inVec[n].size(); i++) {
            m = inVec[n].at(i); // n -> m

            inDegree[m]--;
            if (inDegree[m] == 0)
                q.push(m);
        }
    }

    for (int i = 1; i <= N; i++)
        cout << time[i] << "\n";
}