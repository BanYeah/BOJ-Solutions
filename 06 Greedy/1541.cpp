#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    bool minus = false;
    int ans = 0, n = 0;

    string exp;
    cin >> exp;
    for (int i = 0; i < exp.length(); i++) {
        if (exp.at(i) == '+' || exp.at(i) == '-') {
            if (minus) {
                ans -= n;
                n = 0;
            } else {
                ans += n;
                n = 0;
            }

            if (exp.at(i) == '-')
                minus = true;
        } else {
            n *= 10;
            n += exp.at(i) - '0';
        }
    }

    if (minus) 
        ans -= n;
    else
        ans += n;

    cout << ans << "\n";
}