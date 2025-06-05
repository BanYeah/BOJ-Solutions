#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, n;
    cin >> N;

    vector<int> stack;
    deque<char> stdout_buffer;

    int max_n = 0;
    for (int i = 0; i < N; i++) {
        cin >> n;

        if (n > max_n) {
            for (int j = max_n + 1; j <= n; j++) {
                stack.push_back(j);
                stdout_buffer.push_back('+');
            }
            stack.pop_back();
            stdout_buffer.push_back('-');

            max_n = n;
        }
        else {
            if (n != stack.back()) {
                cout << "NO\n";
                return 0;
            }
            stack.pop_back();
            stdout_buffer.push_back('-');
        }
    }

    while (!stdout_buffer.empty()) {
        cout << stdout_buffer.front() << "\n";
        stdout_buffer.pop_front();
    }
}