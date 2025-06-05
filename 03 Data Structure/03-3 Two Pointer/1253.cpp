#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, n;
    cin >> N;

    vector<int> vec;
    for (int i = 0; i < N; i++) {
        cin >> n;
        vec.push_back(n);
    }
    if (N < 3) { // 예외 처리
        cout << 0 << "\n";
        return 0;
    }

    sort(vec.begin(), vec.end()); // 정렬

    int count = 0;
    for (int target = 0; target < vec.size(); target++) { // 범위가 정수임에 주의
        int start = 0, end = vec.size() - 1;
        while (start < end) {
            if (start == target) {
                start++;
                continue;
            } else if (end == target) {
                end--;
                continue;
            }

            if (vec.at(start) + vec.at(end) == vec.at(target)) {
                count++;
                break;
            } else if (vec.at(start) + vec.at(end) < vec.at(target))
                start++;
            else // vec.at(start) + vec.at(end) > target
                end--;
        }
    }

    cout << count << "\n";
}