#include <bits/stdc++.h>
using namespace std;

struct Node {
    int matched, open, close;
    Node() : matched(0), open(0), close(0) {}
};

string s;
vector<Node> tree;

Node merge(const Node& L, const Node& R) {
    Node res;
    int new_matches = min(L.open, R.close);

    res.matched = L.matched + R.matched + new_matches;
    res.open = L.open + R.open - new_matches;
    res.close = L.close + R.close - new_matches;

    return res;
}

void build(int idx, int l, int r) {
    if (l == r) {
        if (s[l] == '(') tree[idx].open = 1;
        else tree[idx].close = 1;
        return;
    }

    int mid = (l + r) / 2;
    build(idx*2+1, l, mid);
    build(idx*2+2, mid+1, r);

    tree[idx] = merge(tree[idx*2+1], tree[idx*2+2]);
}

Node query(int idx, int l, int r, int ql, int qr) {
    if (qr < l || r < ql) return Node();

    if (ql <= l && r <= qr) return tree[idx];

    int mid = (l + r) / 2;
    Node left = query(idx*2+1, l, mid, ql, qr);
    Node right = query(idx*2+2, mid+1, r, ql, qr);

    return merge(left, right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s;
    int n = s.size();
    tree.resize(4*n);

    build(0, 0, n-1);

    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        Node res = query(0, 0, n-1, l, r);

        cout << res.matched * 2 << "\n";
    }
    return 0;
}
