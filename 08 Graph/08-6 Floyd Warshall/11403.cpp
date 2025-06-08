#include <iostream>

using namespace std;

int matrix[100][100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cin >> matrix[i][j];
    }

    for (int k = 0; k < N; k++) { // K: 경유지
        for (int i = 0; i < N; i++) { // I: 출발지
            for (int j = 0; j < N; j++) { // J: 도착지
                if (matrix[i][k] == 1 && matrix[k][j] == 1)
                    matrix[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}