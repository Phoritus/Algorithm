#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f, Node* l = nullptr, Node* r = nullptr) {
        ch = c;
        freq = f;
        left = l;
        right = r;
    }
};

struct Compare {
    bool operator()(Node* l, Node* r) {
        if (l->freq == r->freq) {
            return l->ch > r->ch;
        }
        return l->freq > r->freq;
    }
};

void build_map(Node* root, string code, map<char, string>& encoding_map) {
    if (!root) return;
    if (root->ch != '\0') {
        encoding_map[root->ch] = code;
    } else {
        build_map(root->left, code + "0", encoding_map);
        build_map(root->right, code + "1", encoding_map);
    }
}

Node* build_tree(string text) {
    map<char, int> counter;
    for (char ch : text) counter[ch]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto const& p : counter) {
        pq.push(new Node(p.first, p.second));
    }

    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *parent = new Node('\0', left->freq + right->freq, left, right);
        pq.push(parent);
    }
    return pq.top();
}

string decode(string encoded, Node* root) {
    if (!root) return "";
    string decoded = "";
    Node* curr = root;
    for (char bit : encoded) {
        if (bit == '0') curr = curr->left;
        else curr = curr->right;

        if (curr->ch != '\0') {
            decoded += curr->ch;
            curr = root;
        }
    }
    return decoded;
}

int main() {
    string text = "XXXXXYYYYYYYYYWWWWWWWWWWWWZZZZZZZZZZZZZVVVVVVVVVVVVVVVVUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUUU";
    
    Node* root = build_tree(text);
    map<char, string> encoding_map;
    build_map(root, "", encoding_map);
    
    cout << "--- BINARY CODES ---" << endl;
    for (auto const& p : encoding_map) {
        cout << p.first << " : " << p.second << endl;
    }
    
    string test = "WXYZ";
    string encoded = "";
    for (char ch : test) encoded += encoding_map[ch];
    cout << "\nEncoded: " << encoded << endl;
    
    string to_decode = "0101011011000";
    cout << "Decoded: " << decode(to_decode, root) << endl;
    
    return 0;
}