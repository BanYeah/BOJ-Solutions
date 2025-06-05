#include <iostream>

using namespace std;

long long arr[1025][1025] = {}; // 전역 변수 선언으로 스택 메모리 제한 회피해야

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, n;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> n;
            arr[i][j] = n - arr[i-1][j-1] + arr[i][j-1] + arr[i-1][j];
        }
    }

    int x1, y1, x2, y2;
    for (int i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << arr[x2][y2] - arr[x1-1][y2] - arr[x2][y1-1] + arr[x1-1][y1-1] << "\n";
        // '(x, y)는 x행 y열을 의미한다.' 문제 조건 제대로 읽어야...
    }
}