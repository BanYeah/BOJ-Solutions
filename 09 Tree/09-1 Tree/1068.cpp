#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[51];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int p, root;
    for (int i = 0; i < N; i++) {
        cin >> p;

        if (p == -1)
            root = i;
        else
            vec[p].push_back(i); // p -> i
    }

    int remove;
    cin >> remove;

    if (remove == root) {
        cout << 0 << "\n";
        return 0;
    }
        
    queue<int> q;
    q.push(root);

    int num_leaf = 0;
    while (!q.empty()) {
        p = q.front();
        q.pop();

        int num_child = 0;
        for (int c : vec[p]) {
            if (c == remove)
                continue;

            num_child++;
            q.push(c);
        }

        if (num_child == 0)
            num_leaf++;
    }
    cout << num_leaf << "\n";
}
