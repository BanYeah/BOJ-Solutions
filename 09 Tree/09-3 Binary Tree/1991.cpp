#include <iostream>

using namespace std;

int bNode[27][2] = {};
// A는 인덱스 1

int getAlphaNum(char c) {
    if (c == '.') return 0;
    return c - 'A' + 1;
}

char getAlpha(int i) {
    return 'A' + i - 1;
}

void CLR(int i) { // 전위 순회
    if (i == 0) return;

    cout << getAlpha(i);
    CLR(bNode[i][0]);
    CLR(bNode[i][1]);
}

void LCR(int i) { // 중위 순회
    if (i == 0) return;

    LCR(bNode[i][0]);
    cout << getAlpha(i);
    LCR(bNode[i][1]);

}

void LRC(int i) { // 후위 순회
    if (i == 0) return;
    
    LRC(bNode[i][0]);
    LRC(bNode[i][1]);
    cout << getAlpha(i);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    char center, left, right;
    for (int i = 0; i < N; i++) {
        cin >> center >> left >> right;

        bNode[getAlphaNum(center)][0] = getAlphaNum(left);
        bNode[getAlphaNum(center)][1] = getAlphaNum(right);
    }

    CLR(1);
    cout << "\n";

    LCR(1);
    cout << "\n";

    LRC(1);
    cout << "\n";
}