#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, n;
    cin >> N >> M;

    vector<int> vec(M, 0);
    int remain_sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> n;
        remain_sum = (remain_sum + n) % M;
        vec.at(remain_sum)++;
    }

    long long result = vec.at(0); // 오버플로우 주의
    for (int i = 0; i < M; i++) {
        if (vec.at(i) > 0)
            if (vec.at(i) % 2 == 0)
                result += (long long)vec.at(i) / 2 * (vec.at(i) - 1); // 오버플로우 주의
            else
                result += (long long)vec.at(i) * ((vec.at(i) - 1) / 2);
    }
    cout << result << "\n";
}