// 3448번: 문자 인식
// https://www.acmicpc.net/problem/3448

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int total = 0, target = 0;
        char c;
        while (true)
        {
            if ((c = cin.get()) == '\n')
                c = cin.get();

            if (c == '\n')
                break;
            else
            {
                if (c == '#')
                    target++;
                total++;
            }
        }

        double ratio = (double(total - target) / total) * 100;
        if (ratio == int(ratio))
            cout << "Efficiency ratio is " << int(ratio) << "%." << endl;
        else if (round(ratio * 10) / 10 == int(round(ratio * 10) / 10))
            cout << "Efficiency ratio is " << int(round(ratio * 10) / 10) << "%." << endl;
        else
            cout << "Efficiency ratio is " << std::fixed << std::setprecision(1) << ratio << "%." << endl;
    }
}