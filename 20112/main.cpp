// 20112번: 사토르 마방진
// https://www.acmicpc.net/problem/20112

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    char **MaBangGin = new char *[N];
    for (int i = 0; i < N; i++)
        MaBangGin[i] = new char[N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> MaBangGin[i][j];

    int flag = true;
    for (int i = 0; i < N && flag; i++)
        for (int j = 0; j < N && flag; j++)
            if (MaBangGin[i][j] != MaBangGin[j][i])
                flag = false;

    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}