#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

class SegmentTree {
private:
    vector<ll> tree; 
    vector<ll> arr;     
    int n;

    void build(int idx, int l, int r) {
        if (l == r) {
            tree[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2*idx+1, l, mid);
        build(2*idx+2, mid+1, r);
        tree[idx] = tree[2*idx+1] + tree[2*idx+2];
    }

    ll query(int idx, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return 0; 
        if (ql <= l && r <= qr) return tree[idx]; 

        int mid = (l + r) / 2;
        ll leftRes = query(2*idx+1, l, mid, ql, qr);
        ll rightRes = query(2*idx+2, mid+1, r, ql, qr);

        return leftRes + rightRes;
    }

    void update(int idx, int l, int r, int pos, ll val) {
        if (l == r) {
            arr[l] = val;
            tree[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2*idx+1, l, mid, pos, val);
        else update(2*idx+2, mid+1, r, pos, val);
        tree[idx] = tree[2*idx+1] + tree[2*idx+2];
    }

public:
    SegmentTree(const vector<ll>& input) {
        arr = input;
        n = arr.size();
        tree.resize(4 * n); 
        build(0, 0, n-1);     
    }

    ll getSum(int l, int r) {
        return query(0, 0, n-1, l, r);
    }

    void setValue(int pos, ll val) {
        update(0, 0, n-1, pos, val);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    vector<ll> arr(n);
    for(int i=0; i<n; ++i) cin >> arr[i];

    SegmentTree st(arr);

    for(int j=0; j<m; ++j) {
        int t;
        cin >> t;

        if(t == 1) {
            int i;
            ll v;
            cin >> i >> v;
            st.setValue(i, v);
        } else {
            int l,r;
            cin >> l >> r;
            cout << st.getSum(l, r-1) << "\n";
        }
    }

    return 0;
}
