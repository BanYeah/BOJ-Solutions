// 27387번: Ghost Leg
// https://www.acmicpc.net/problem/27387

#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    int *permutation = new int[n + 1]();
    int *rungs = new int[m];
    for (int i = 0; i < m; i++)
        cin >> rungs[i];

    for (int i = 1; i <= n; i++)
    {
        int pos = i;
        for (int j = 0; j < m; j++)
        {
            if (pos == rungs[j])
                pos = rungs[j] + 1;
            else if (pos == rungs[j] + 1)
                pos = rungs[j];
        }

        permutation[pos] = i;
    }

    for (int i = 1; i <= n; i++)
        cout << permutation[i] << endl;
}