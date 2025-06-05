#include <iostream>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, n;
    cin >> N;

    deque<int> deq;
    for (int i = 0; i < N; i++) {
        deq.push_back(i+1);
    }

    while (deq.size() != 1) {
        deq.pop_front();

        n = deq.front();
        deq.pop_front();
        deq.push_back(n);
    }
    
    cout << deq.front() << "\n";
}