// 16770번: The Bucket List
// https://www.acmicpc.net/problem/16770

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int *needBuckets = new int[1001]();
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int s, t, b;
        cin >> s >> t >> b;

        for (int j = s; j <= t; j++)
            needBuckets[j] += b;
    }

    int maxBuckets = needBuckets[0];
    for (int i = 0; i < 1001; i++)
    {
        if (maxBuckets < needBuckets[i])
            maxBuckets = needBuckets[i];
    }
    cout << maxBuckets;

    delete[] needBuckets;
}