// 5717번: 상근이의 친구들
// https://www.acmicpc.net/problem/5717

#include <iostream>

using namespace std;

int main()
{
    int M, F;
    while (true)
    {
        cin >> M >> F;
        if (M == 0 && F == 0)
            break;
        cout << M + F << endl;
    }
}