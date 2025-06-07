#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K, n;
    cin >> N >> K;

    vector<int> coins;
    for (int i = 0; i < N; i++) {
        cin >> n;
        coins.push_back(n);
    }

    int num = 0;
    while (!coins.empty()) {
        n = coins.back();
        coins.pop_back();

        while (n <= K) {
            K -= n;
            num++;
        }
    }
    cout << num << "\n";
}