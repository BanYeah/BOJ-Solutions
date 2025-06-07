#include <iostream>

using namespace std;

int arr[1000001] = {};

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

    int N, M;
    cin >> N >> M;

    for (int i = 0; i <= N; i++)
        arr[i] = i;
    
    int op, a, b;
    for (int i = 0; i < M; i++) {
        cin >> op >> a >> b;

        int symbol_a = Find(a);
        int symbol_b = Find(b);

        if (op == 0) // Union
            arr[symbol_b] = symbol_a;
        else { // Find
            if (symbol_a == symbol_b)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
}