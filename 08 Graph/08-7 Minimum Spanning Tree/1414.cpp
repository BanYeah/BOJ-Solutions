#include <iostream>
#include <queue>

using namespace std;

int getLength(char c) {
    if (c == '0')
        return 0;
    else if ('a' <= c && c <= 'z')
        return c - 'a' + 1;
    else
        return c - 'A' + 27;
}

class Edge {
    public:
        int u;
        int v;
        int w;

        Edge(int u, int v, int w)
            : u(u), v(v), w(w) {}

        bool operator<(const Edge& other) const {
            return w > other.w; // Min-heap
        }
};

class UnionFind {
    public:
        // Constructor
        UnionFind(int N) {
            for (int i = 0; i < N; i++)
                arr[i] = i;
        }

        // Find: return symbol
        int Find(int x) {
            if (arr[x] == x) return x;
        
            int symbol = Find(arr[x]);
            arr[x] = symbol;
            return symbol;
        }

        // Union
        void Union(int a, int b) {
            int symbol_a = Find(a);
            int symbol_b = Find(b);

            arr[symbol_a] = symbol_b;
        }

        bool isUnion(int a, int b) {
            int symbol_a = Find(a);
            int symbol_b = Find(b);

            return symbol_a == symbol_b;
        }
    private:
        int arr[50];
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    char c;
    int length, total_length = 0;
    priority_queue<Edge> pq;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c;

            length = getLength(c);
            if (length != 0) {
                pq.push(Edge(i, j, length));
                total_length += length;
            }
        }
    }

    UnionFind uf = UnionFind(N);
    while (!pq.empty()) {
        Edge e = pq.top();
        pq.pop();

        if (uf.isUnion(e.u, e.v))
            continue;
        
        uf.Union(e.u, e.v);
        total_length -= e.w;
    }

    // 모든 컴퓨터가 연결되어 있는지 확인
    bool fullyConnected = true;
    for (int i = 0; i < N; i++) {
        if (!uf.isUnion(0, i)) {
            fullyConnected = false;
            break;
        }
    }

    if (!fullyConnected)
        cout << -1 << "\n";
    else
        cout << total_length << "\n";
}