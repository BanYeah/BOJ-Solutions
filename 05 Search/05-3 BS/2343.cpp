#include <iostream>
#include <vector>

using namespace std;

int BS(vector<int> &sum_vec, int target) {
    if (sum_vec.back() <= target)
        return -1;

    int start = 1, end = sum_vec.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (sum_vec.at(mid) == target)
            return target;
        else if (sum_vec.at(mid) < target)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return sum_vec.at(end);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, n, m;
    cin >> N >> M;

    vector<int> sum_vec;
    sum_vec.push_back(0); // dummy
    for (int i = 0; i < N; i++) {
        cin >> n;
        m = sum_vec.back();
        sum_vec.push_back(n + m);
    }

    int part_size = sum_vec.back() / N; // size of partition
    while (true) {
        int bound = part_size;
        for (int split = 0; split < M; split++) {
            bound = BS(sum_vec, bound) + part_size;
            if (bound == part_size - 1) {
                cout << part_size << "\n";
                return 0;
            }
        }

        int remain = (sum_vec.back() - bound - part_size) / N;
        part_size += remain > 0 ? remain : 1;
    }
}