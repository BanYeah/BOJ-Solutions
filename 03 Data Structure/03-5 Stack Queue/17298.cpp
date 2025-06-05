#include <iostream>
#include <vector>

using namespace std;

int arr[1000000] = {};

typedef struct _node {
    int value;
    int index;
} Node;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, n;
    cin >> N;

    vector<Node> stack;
    for (int i = 0; i < N; i++) {
        cin >> n;

        while (!stack.empty()) {
            Node back = stack.back();
            if (back.value < n) {
                arr[back.index] = n;
                stack.pop_back();
            } else
                break;
        }

        stack.push_back({n, i});
    }

    while (!stack.empty()) {
        arr[stack.back().index] = -1;
        stack.pop_back();
    }

    for (int i = 0; i < N; i++) 
        cout << arr[i] << " ";
    cout << "\n";
}