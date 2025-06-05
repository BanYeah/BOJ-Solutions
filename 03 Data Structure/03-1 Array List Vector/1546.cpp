#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, max = 0, sum = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> M;
        sum += M;
        if (M > max) max = M;
    }

    cout << fixed << setprecision(6) << double(sum) / max * 100 / N;
}