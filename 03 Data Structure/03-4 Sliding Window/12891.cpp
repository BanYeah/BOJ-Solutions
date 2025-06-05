#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S, P;
    cin >> S >> P;

    vector<char> dna_string;
    char dna;
    for (int i = 0; i < S; i++) {
        cin >> dna;
        dna_string.push_back(dna);
    }

    int A, C, G, T;
    cin >> A >> C >> G >> T;
    
    int a = 0, c = 0, g = 0, t = 0, count = 0;
    for (int i = 0; i < P; i++) {
        switch (dna_string.at(i)) {
        case 'A':
            a++;
            break;
        case 'C':
            c++;
            break;
        case 'G':
            g++;
            break;
        case 'T':
            t++;
            break;
        }
    }
    if (a >= A && c >= C && g >= G && t >= T)
        count++;
    
    for (int i = P; i < S; i++) {
        switch (dna_string.at(i)) {
        case 'A':
            a++;
            break;
        case 'C':
            c++;
            break;
        case 'G':
            g++;
            break;
        case 'T':
            t++;
            break;
        }

        switch (dna_string.at(i-P)) {
        case 'A':
            a--;
            break;
        case 'C':
            c--;
            break;
        case 'G':
            g--;
            break;
        case 'T':
            t--;
            break;
        }

        if (a >= A && c >= C && g >= G && t >= T)
            count++;
    }
    cout << count << "\n";
}