#include <iostream>
#include <vector>
#include <deque>

using namespace std;

#if 0
// 이진탐색 이용
class Bsearch {
    public:
        void insert(int n) {
            vec.insert(vec.begin() + _find(n), n); // 시간 복잡도가 O(L)
        }
        void erase(int n) {
            vec.erase(vec.begin() + _find(n)); // 시간 복잡도가 O(L)
        }
        int leftmost() {
            return vec.at(0);
        }
    private:
        vector<int> vec;
        int _find(int n) {
            if (vec.size() == 0) return 0;

            int start = 0, end = vec.size() - 1, mid;
            while (start <= end) {
                mid = start + (end - start) / 2;
                if (vec.at(mid) == n)
                    return mid;
                else if (vec.at(mid) < n)
                    start = mid + 1;
                else
                    end = mid - 1;
            }

            if (vec.at(mid) > n)
                return mid;
            else
                return mid + 1;
        }
};

#elif 0
#include <set>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L, n;
    cin >> N >> L;

    vector<int> vec;
    multiset<int> ms; // BST를 기반으로 항상 정렬 상태 유지
    for (int i = 0; i < N; i++) {
        cin >> n;
        vec.push_back(n);

        ms.insert(n); // O(log L)이나, 상수값이 커서...
        if (i >= L) ms.erase(ms.find(vec.at(i - L)));
        cout << *ms.begin() << " ";
    }
    cout << "\n";
}

#else
typedef struct _node {
    int value;
    int index;
} Node;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L, n;
    cin >> N >> L;

    deque<Node> deq;
    for (int i = 0; i < N; i++) {
        cin >> n;
        while (!deq.empty() && deq.back().value > n)
            deq.pop_back();
        deq.push_back({n, i});

        while (!deq.empty() && deq.front().index <= i-L)
            deq.pop_front();
        cout << deq.front().value << " ";
    }
    cout << "\n";
}
#endif