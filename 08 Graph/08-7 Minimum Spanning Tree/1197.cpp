#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Edge {
    public:
        int u;
        int v;
        int w;

        Edge(int u, int v, int w)
            :u(u), v(v), w(w) {}
        
        bool operator<(const Edge& other) const {
            return w > other.w;
        }
};

class UnionFind {
    public:
        // Constructor
        UnionFind(int N) {
            for (int i = 1; i <= N; i++)
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
        int arr[10001];
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin >> V >> E;

    priority_queue<Edge> pq;

    int u, v, w;
    for (int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        pq.push(Edge(u, v, w));
    }

    UnionFind uf(V);
    int weight_sum = 0;
    while (!pq.empty()) {
        Edge e = pq.top();
        pq.pop();

        if (uf.isUnion(e.u, e.v)) 
            continue;
        
        weight_sum += e.w;
        uf.Union(e.u, e.v);
    }

    cout << weight_sum << "\n";
}