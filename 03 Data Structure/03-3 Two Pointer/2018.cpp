#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, count = 0;
    cin >> N;

    int p1 = 0, p2 = 1, range_sum = 1;
    while (p2 <= N) {
        if (range_sum == N) {
            count++;
            range_sum += ++p2;
        } else if (range_sum > N)
            range_sum -= ++p1;
        else // range_sum < N
            range_sum += ++p2;
    }
    cout << count << "\n";
}