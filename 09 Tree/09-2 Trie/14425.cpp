#include <iostream>
#include <string>

#define ALPHA_NUM 26

using namespace std;

class Node {
    public:
        Node *next[ALPHA_NUM];
        bool isEnd = false;

        // Constructor
        Node() {
            for (int i = 0; i < ALPHA_NUM; i++)
                next[i] = nullptr;
        }
};

class Trie {
    public:
        void insert(const string& str) {
            Node* cur = &root;
            for (int i = 0; i < str.length(); i++) {
                int alpha = str.at(i) - 'a';

                if (cur->next[alpha] == nullptr)
                    cur->next[alpha] = new Node;
                cur = cur->next[alpha];
            }
            cur->isEnd = true;
        }

        bool find(const string& str) {
            Node* cur = &root;
            for (int i = 0; i < str.length(); i++) {
                int alpha = str.at(i) - 'a';

                if (cur->next[alpha] == nullptr)
                    return false;
                cur = cur->next[alpha];
            }
            return cur->isEnd;
        }

        void clear() {
            for (int i = 0; i < ALPHA_NUM; i++) {
                if (root.next[i] != nullptr)
                    _clear(root.next[i]);
            }
        }

    private:
        Node root;

        void _clear(Node* n) {
            for (int i = 0; i < ALPHA_NUM; i++) {
                if (n->next[i] != nullptr)
                    _clear(n->next[i]);
            }
            delete n;
        }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    Trie trie;
    string str;
    for (int i = 0; i < N; i++) {
        cin >> str;
        trie.insert(str);
    }

    int sum = 0;
    for (int i = 0; i < M; i++) {
        cin >> str;
        if (trie.find(str))
            sum++;
    }
    trie.clear();

    cout << sum << "\n";
}