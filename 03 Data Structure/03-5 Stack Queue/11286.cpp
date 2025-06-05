#include <iostream>
#include <queue>

using namespace std;

class Abs {
    public:
        int value;
        int abs_value;

        Abs(int value, int abs_value)
            : value(value), abs_value(abs_value) {}

        bool operator<(const Abs& other) const {
            if (abs_value != other.abs_value)
                return abs_value > other.abs_value;
            else
                return value > other.value;
        }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, x;
    cin >> N;

    priority_queue<Abs> pq; // 그냥 int로 한 뒤에, operator를 overloading하는 방식이 나았을 듯...
    for (int i = 0; i < N; i++) {
        cin >> x;
        if (x == 0) {
            if (pq.empty())
                cout << 0 << "\n";
            else {
                cout << pq.top().value << "\n";
                pq.pop();
            } 
        }
        else
            pq.push(Abs(x, x > 0 ? x : -x));
    }
}