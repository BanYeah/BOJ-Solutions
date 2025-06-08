#include <iostream>
#include <climits>

using namespace std;

int matrix[101][101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) matrix[i][j] = 0;
            else matrix[i][j] = INT_MAX;
        }
    }

    int A, B;
    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        matrix[A][B] = 1;
        matrix[B][A] = 1;
    }

    for (int k = 1; k <= N; k++) { // K: 경유지
        for (int i = 1; i <= N; i++) { // I: 출발지
            for (int j = 1; j <= N; j++) { // J: 도착지
                if (matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
                    continue;
                
                if (matrix[i][j] > matrix[i][k] + matrix[k][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }

    int min_kavin = INT_MAX, kavin = 1;
    for (int i = 1; i <= N; i++) {
        int sum_kavin = 0;
        for (int j = 1; j <= N; j++)
            sum_kavin += matrix[i][j];
        
        if (sum_kavin < min_kavin) {
            min_kavin = sum_kavin;
            kavin = i;
        }
    }

    cout << kavin << "\n";
}