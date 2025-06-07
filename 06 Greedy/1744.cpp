#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, n, m;
    cin >> N;

    deque<int> pos, neg;
    for (int i = 0; i < N; i++) {
        cin >> n;
        if (n >= 0)
            pos.push_back(n);
        else
            neg.push_back(n);
    }

    sort(pos.begin(), pos.end()); // 오름차순 정렬
    sort(neg.begin(), neg.end());

    int sum = 0;
    bool has0 = false;
    while (!pos.empty()) {
        n = pos.back(); // 최대값
        pos.pop_back();

        if (n == 0)
            has0 = true;
        else if (n == 1 || pos.empty())
            sum += n; // 곱셈보다 덧셈이 이득
        else {
            m = pos.back(); // 최대값
            pos.pop_back();

            if (m == 1)
                sum += n + m;
            else if (m == 0) {
                sum += n;
                has0 = true;
            } else {
                sum += n * m;
            }
        }
    }
    
    while (!neg.empty()) {
        n = neg.front(); // 최소값
        neg.pop_front();

        if (neg.empty()) {
            if (!has0)
                sum += n;
        } else {
            m = neg.front(); // 최소값
            neg.pop_front();

            sum += n * m;
        }
    }

    cout << sum << "\n";
}