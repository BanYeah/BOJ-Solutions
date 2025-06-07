#include <iostream>
#include <queue>

using namespace std;

typedef struct _coordinate {
    char x; // 메모리 초과 위험으로 char 자료형 사용
    char y;
} Coord;

char boxes[100][100];
char visited[100][100] = {};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    char c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> c;
            boxes[i][j] = c - '0';
        }
    }

    queue<Coord> q;
    q.push({0, 0});
    q.push({-1, -1}); // level 표시용

    visited[0][0] = 1; // 바로 방문 표시

    int level = 0;
    while (!q.empty()) {
        Coord c = q.front();
        q.pop();

        if (c.x == -1 || c.y == -1) {
            level++;
            q.push({-1, -1}); // level 표시용
            continue;
        } else if (c.x == M - 1 && c.y == N - 1) {
            cout << level + 1 << "\n";
            return 0;
        }

        if (c.y - 1 >= 0 && boxes[c.y - 1][c.x] && !visited[c.y - 1][c.x]) {
            char new_y = c.y - 1;
            q.push({c.x, new_y}); // 상

            visited[new_y][c.x] = 1; // 바로 방문 표시
        }
        if (c.y + 1 < N && boxes[c.y + 1][c.x] && !visited[c.y + 1][c.x]) {
            char new_y = c.y + 1;
            q.push({c.x, new_y}); // 하

            visited[new_y][c.x] = 1;
        }
        if (c.x - 1 >= 0 && boxes[c.y][c.x - 1] && !visited[c.y][c.x - 1]) {
            char new_x = c.x - 1; 
            q.push({new_x, c.y}); // 좌

            visited[c.y][new_x] = 1;
        }
        if (c.x + 1 < M && boxes[c.y][c.x + 1] && !visited[c.y][c.x + 1]) {
            char new_x = c.x + 1;
            q.push({new_x, c.y}); // 우

            visited[c.y][new_x] = 1;
        }
    }
}