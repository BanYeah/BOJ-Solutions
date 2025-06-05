#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, n;
    cin >> N >> M;

    vector<int> vec;
    for (int i = 0; i < N; i++) {
        cin >> n;
        vec.push_back(n);
    }

    sort(vec.begin(), vec.end()); // 정렬

    int count = 0, start = 0, end = vec.size() - 1;
    while (start < end)
    {
        if (vec.at(start) + vec.at(end) == M) {
            count++;
            start++;
            end--;
        } else if (vec.at(start) + vec.at(end) < M)
            start++;
        else // vec.at(start) + vec.at(end) > M
            end--;
    }
    cout << count << "\n";
}