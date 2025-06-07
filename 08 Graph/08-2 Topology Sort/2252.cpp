#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int inDegree[32001] = {};
vector<int> vec[32001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int A, B;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        vec[A].push_back(B);
        inDegree[B]++;
    }

    queue<int> ready;
    for (A = 1; A <= N; A++) {
        if (!inDegree[A])
            ready.push(A);
    }

    while (!ready.empty()) {
        A = ready.front();
        ready.pop();

        for (int j = 0; j < vec[A].size(); j++) {
            B = vec[A].at(j);
            inDegree[B]--;

            if (!inDegree[B])
                ready.push(B);
        }

        cout << A << " ";
    }
    cout << "\n";
}