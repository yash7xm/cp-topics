#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

vector<ll> tree;

ll query(int idx, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) return 0;  // no overlap
    if (l >= ql && r <= qr) return tree[idx];  // full overlap
    
    int mid = (l + r) / 2;
    ll left_res = query(2*idx + 1, l, mid, ql, qr);
    ll right_res = query(2*idx + 2, mid + 1, r, ql, qr);
    return (left_res + right_res) % mod;
}

void update(int idx, int l, int r, int pos, ll cnt) {
    if (l == r) {
        tree[idx] = (tree[idx] + cnt) % mod;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(2*idx + 1, l, mid, pos, cnt);
    else update(2*idx + 2, mid + 1, r, pos, cnt);

    tree[idx] = (tree[2*idx + 1] + tree[2*idx + 2]) % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n), allVals(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        allVals[i] = arr[i];
    }

    // coordinate compression
    sort(allVals.begin(), allVals.end());
    allVals.erase(unique(allVals.begin(), allVals.end()), allVals.end());

    auto getId = [&](int x) {
        return int(lower_bound(allVals.begin(), allVals.end(), x) - allVals.begin());
    };

    int MAX_ID = allVals.size();
    tree.assign(4 * MAX_ID, 0);

    for (int i = 0; i < n; ++i) {
        int x = getId(arr[i]);
        ll cnt = (x > 0 ? query(0, 0, MAX_ID-1, 0, x-1) : 0); // subsequences ending before x
        cnt = (cnt + 1) % mod; // include arr[i] itself
        update(0, 0, MAX_ID-1, x, cnt);
    }

    cout << query(0, 0, MAX_ID-1, 0, MAX_ID-1) % mod << "\n";

    return 0;
}
