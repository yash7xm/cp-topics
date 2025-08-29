#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree;

    void update(int idx, int l, int r, int pos) {
        if (l == r) {
            tree[idx] += 1;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2*idx+1, l, mid, pos);
        else update(2*idx+2, mid+1, r, pos);
        tree[idx] = tree[2*idx+1] + tree[2*idx+2];
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0; 
        if (ql <= l && r <= qr) return tree[idx];
        int mid = (l + r) / 2;
        return query(2*idx+1, l, mid, ql, qr) +
               query(2*idx+2, mid+1, r, ql, qr);
    }

public:
    SegmentTree(int size) {
        n = size;
        tree.assign(4*n, 0);
    }

    void add(int pos) {
        update(0, 1, n, pos);
    }

    int rangeSum(int l, int r) {
        if (l > r) return 0;
        return query(0, 1, n, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    SegmentTree st(n);
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        // count how many greater than p[i] have appeared
        ans[i] = st.rangeSum(p[i]+1, n);
        // mark p[i] as seen
        st.add(p[i]);
    }

    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";

    return 0;
}
