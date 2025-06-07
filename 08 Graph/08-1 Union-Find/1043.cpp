#include <iostream>
#include <vector>

using namespace std;

int party[50];
int arr[51] = {};

int Find(int x) {
    if (arr[x] == x)
        return x;
    
    int symbol = Find(arr[x]);
    arr[x] = symbol;
    return symbol;
}

void Union(int a, int b) {
    int symbol_a = Find(a);
    int symbol_b = Find(b);

    arr[symbol_a] = symbol_b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        arr[i] = i;

    int T, t, prev_t;
    cin >> T; // 진실을 아는 사람 수

    if (T == 0) { // 진실을 아는 사람이 없는 경우
        cout << M << "\n";
        return 0;
    }

    for (int i = 0; i < T; i++) {
        cin >> t;

        if (i != 0) Union(t, prev_t);
        prev_t = t;
    }

    int P, p, prev_p; 
    for (int i = 0; i < M; i++) { // 파티 횟수
        cin >> P;                 // 파티에 오는 사람 수

        for (int j = 0; j < P; j++) {
            cin >> p;

            if (j == 0) party[i] = p;
            else Union(p, prev_p);
            prev_p = p;
        }
    }

    int sum = 0;
    for (int i = 0; i < M; i++) {
        int symbol_t = Find(t);
        int symbol_p = Find(party[i]);

        if (symbol_t != symbol_p)
            sum++;
    }
    cout << sum << "\n";
}