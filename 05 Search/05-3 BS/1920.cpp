#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int BS(vector<int> const &A, int target) {
    int start = 0, end = A.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (A.at(mid) == target)
            return 1;
        else if (A.at(mid) < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, a;
    cin >> N;
    
    vector<int> A;
    for (int i = 0; i < N; i++) {
        cin >> a;
        A.push_back(a);
    }

    sort(A.begin(), A.end());

    int M, m;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> m;
        cout << BS(A, m) << "\n";
    }
}