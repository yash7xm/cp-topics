#include <bits/stdc++.h>
using namespace std;

vector<int> merge(const vector<int>& left, const vector<int>& right) {
    int l = 0, r = 0;
    int n = left.size(), m = right.size();
    
    vector<int> res;
    res.reserve(n + m);
    
    while (l < n && r < m) {
        if (left[l] <= right[r]) {
            res.push_back(left[l]);
            l++;
        } else {
            res.push_back(right[r]);
            r++;
        }
    }
    
    while (l < n) {
        res.push_back(left[l]);
        l++;
    }
    
    while (r < m) {
        res.push_back(right[r]);
        r++;
    }
    
    return res;
}

vector<vector<int>> tree;
vector<int> arr;

void build(int idx, int l, int r) {
    if (l == r) {
        tree[idx] = {arr[l]};
        return;
    }
    
    int mid = (l + r) / 2;
    
    build(2 * idx + 1, l, mid);
    build(2 * idx + 2, mid + 1, r);
    
    tree[idx] = merge(tree[2 * idx + 1], tree[2 * idx + 2]);
}

int query(int idx, int l, int r, int ql, int qr, int k) {
    if (r < ql || l > qr) return 0;
    
    if (l >= ql && r <= qr) {
        int total = tree[idx].size();
        int notGreater = upper_bound(tree[idx].begin(), tree[idx].end(), k) - tree[idx].begin();
        return total - notGreater;
    }
    
    int mid = (l + r) / 2;
    
    int left_res = query(2 * idx + 1, l, mid, ql, qr, k);
    int right_res = query(2 * idx + 2, mid + 1, r, ql, qr, k);
    
    return left_res + right_res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    arr.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    tree.resize(4 * n);
    build(0, 0, n - 1);
    
    int q;
    cin >> q;
    
    for (int i = 0; i < q; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        
        cout << query(0, 0, n - 1, l - 1, r - 1, k) << "\n";
    }
    
    return 0;
}