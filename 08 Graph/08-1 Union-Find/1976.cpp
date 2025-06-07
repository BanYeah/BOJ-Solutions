#include <iostream>

using namespace std;

int arr[201] = {};

int Find(int x) {
    if (arr[x] == x)
        return x;
    
    int symbol = Find(arr[x]);
    arr[x] = symbol;
    return symbol;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, n, m;
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        arr[i] = i;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> n;

            if (i == j)
                continue;
            else if (n == 1) { // Union
                int symbol_i = Find(i);
                int symbol_j = Find(j);

                arr[symbol_i] = symbol_j;
            }
        }
    }

    int symbol;
    for (int i = 0; i < M; i++) {
        cin >> m;
        if (i == 0) symbol = Find(m);
        else if (symbol != Find(m)) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}