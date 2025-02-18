// 10420번: 기념일 1
// https://www.acmicpc.net/problem/10420

#include <iostream>

using namespace std;

int Cal(int year, int month)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            return 29;
        else
            return 28;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    N--; // 오늘부터 1일!

    int year = 2014, month = 4, day = 2;
    if (N < 29)
        day += N;
    else
    {
        month = 5, day = 1, N -= 29;

        while (N)
        {
            int cal = Cal(year, month);
            if (N < cal)
                day += N, N = 0;
            else
            {
                if (month < 12)
                    month += 1;
                else
                    month = 1, year += 1;
                day = 1, N -= cal;
            }
        }
    }

    cout << year << "-";

    if (month < 10)
        cout << "0";
    cout << month << "-";

    if (day < 10)
        cout << "0";
    cout << day << endl;

    return 0;
}