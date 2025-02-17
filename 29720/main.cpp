// 29720번: 그래서 님 푼 문제 수가?
// https://www.acmicpc.net/problem/29720

#include <iostream>

using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    int minD = N - (M * K);
    int maxD = N - (M * (K - 1) + 1);
    cout << (minD > 0 ? minD : 0) << ' ' << (maxD > 0 ? maxD : 0) << endl;
}