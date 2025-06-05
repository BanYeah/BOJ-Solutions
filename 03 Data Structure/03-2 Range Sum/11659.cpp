#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, n;
    cin >> N >> M;

    // N이 최대 100,000이므로, 100,000 크기의 배열 선언 가능
    // sum_vec.at(0)을 0으로 초기화하여 코드 복잡도 간소화 가능
    vector<long> sum_vec; // 쓸꺼면 long long을 썼어야...
    for (int i = 0; i < N; i++) {
        cin >> n;
        sum_vec.push_back(i == 0 ? n : sum_vec.at(i-1) + n);
    }

    int i, j;
    for (int k = 0; k < M; k++) {
        cin >> i >> j;
        cout << sum_vec.at(j-1) - (i == 1 ? 0 : sum_vec.at(i-2)) << "\n";
    }
}