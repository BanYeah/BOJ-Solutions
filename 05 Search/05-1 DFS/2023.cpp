#include <iostream>
#include <deque>

using namespace std;

// char not_prime[100000000] = {}; // 에라토스테네스의 체 사용 시, 메모리 초과

bool is_prime(int x) {
    if (x == 2 || x == 3)
        return true;
    else if (x % 2 == 0)
        return false;

    for (int i = 3; i < x; i += 2)
        if (x % i == 0)
            return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, n;
    cin >> N;

    int power = 1;
    for (int i = 1; i < N; i++)
        power *= 10;

    deque<int> st;
    st.push_back(2);
    st.push_back(3);
    st.push_back(5);
    st.push_back(7);

    while (!st.empty()) {
        n = st.front();
        st.pop_front();

        if (n >= power) {
            cout << n << "\n";
            continue;
        }

        for (int i = 0; i < 10; i++) {
            if (is_prime(n*10 + i))
                st.push_back(n*10 + i);
        }
    }
}