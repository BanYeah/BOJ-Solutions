#include <iostream>

using namespace std;

int N, K;
long long Max_K(long long B_k) {
    long long max_k = 0, ki;
    for (int i = 1; i <= N; i++) {
        ki = B_k / i;

        if (ki == 0)
            break;
        else if (ki <= N)
            max_k += ki;
        else
            max_k += N;
    }
    return max_k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    // 지수 탐색 (B[k]가 앞쪽에 있을 확률이 높음)
    long long e = 1, k = 1;
    for (;; e *= 2) {
        k = Max_K(e);

        if (k >= K)
            break;
    }

    // 이진 탐색
    long long start = e / 2, end = e, ans = -1;
    while (start <= end) {
        long long mid = start + (end - start) / 2;
        if (Max_K(mid) >= K) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    cout << ans << "\n";
}