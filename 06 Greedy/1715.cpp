#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, n, m;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> pq; // min heap
    for (int i = 0; i < N; i++) {
        cin >> n;
        pq.push(n);
    }

    int cmp_num = 0;
    while (pq.size() > 1) {
        n = pq.top();
        pq.pop();

        m = pq.top();
        pq.pop();

        cmp_num += n + m;
        pq.push(n + m);
    }
    cout << cmp_num << "\n";
}