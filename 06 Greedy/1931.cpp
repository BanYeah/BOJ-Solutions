#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Meet {
    public:
        int start;
        int end;
        Meet(int s, int e)
        : start(s), end(e) {}

        static bool Compare(Meet a, Meet b) {
            if (a.end == b.end)
                return a.start < b.start;
            return a.end < b.end;
        }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, s, e;
    cin >> N;

    vector<Meet> meets;
    for (int i = 0; i < N; i++) {
        cin >> s >> e;
        meets.push_back(Meet(s, e));
    }

    sort(meets.begin(), meets.end(), Meet::Compare);

    int meet_num = 0, end_time = 0;
    for (int i = 0; i < N; i++) {
        if (meets.at(i).start >= end_time) {
            meet_num++;
            end_time = meets.at(i).end;
        }
    }
    cout << meet_num << "\n";
}