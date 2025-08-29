#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    int n;
    vector<int> tree;

    void update(int idx, int l, int r, int pos, int delta) {
        if (l == r) {
            tree[idx] += delta;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2*idx+1, l, mid, pos, delta);
        else update(2*idx+2, mid+1, r, pos, delta);
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

    void add(int pos, int delta) {
        update(0, 1, n, pos, delta);
    }

    int rangeSum(int l, int r) {
        if (l > r) return 0;
        return query(0, 1, n, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    // collect all values
    vector<tuple<char,int,int>> queries;
    vector<int> allVals;
    allVals.reserve(n + 2*q);

    for (int i = 0; i < n; i++) allVals.push_back(p[i]);

    for (int i = 0; i < q; i++) {
        char type;
        cin >> type;
        if (type == '!') {
            int k, x;
            cin >> k >> x;
            queries.push_back({type, k, x});
            allVals.push_back(x);
        } else {
            int a, b;
            cin >> a >> b;
            queries.push_back({type, a, b});
            allVals.push_back(a);
            allVals.push_back(b);
        }
    }

    // coordinate compression
    sort(allVals.begin(), allVals.end());
    allVals.erase(unique(allVals.begin(), allVals.end()), allVals.end());

    auto getId = [&](int x) {
        return int(lower_bound(allVals.begin(), allVals.end(), x) - allVals.begin()) + 1;
    };

    int MAX_ID = allVals.size();
    SegmentTree st(MAX_ID);

    // initialize frequencies
    vector<int> salaryId(n);
    for (int i = 0; i < n; i++) {
        salaryId[i] = getId(p[i]);
        st.add(salaryId[i], 1);
    }

    // process queries
    for (auto [type, a, b] : queries) {
        if (type == '!') {
            int k = a, x = b;
            int newId = getId(x);
            st.add(salaryId[k - 1], -1);
            salaryId[k - 1] = newId;
            st.add(newId, +1);
        } else {
            int l = getId(a);
            int r = getId(b);
            cout << st.rangeSum(l, r) << "\n";
        }
    }

    return 0;
}
