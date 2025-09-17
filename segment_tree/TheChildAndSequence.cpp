#include <bits/stdc++.h>
using namespace std;

vector<long long> arr, tree, max_tree;

void build(int idx, int l, int r) {
    if (l == r) {
        tree[idx] = arr[l];
        max_tree[idx] = arr[l];
        return;
    }
    
    int mid = (l + r) / 2;
    build(2 * idx + 1, l, mid);
    build(2 * idx + 2, mid + 1, r);
    
    tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    max_tree[idx] = max(max_tree[2 * idx + 1], max_tree[2 * idx + 2]);
}

void update_point(int idx, int l, int r, int pos, long long x) {
    if (l == r) {
        tree[idx] = x;
        max_tree[idx] = x;
        return;
    }
    
    int mid = (l + r) / 2;
    if (pos <= mid) {
        update_point(2 * idx + 1, l, mid, pos, x);
    } else {
        update_point(2 * idx + 2, mid + 1, r, pos, x);
    }
    
    tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    max_tree[idx] = max(max_tree[2 * idx + 1], max_tree[2 * idx + 2]);
}

void update_mod(int idx, int l, int r, int ql, int qr, long long x) {
    if (l > qr || r < ql || max_tree[idx] < x) {
        return;
    }
    
    if (l == r) {
        tree[idx] %= x;
        max_tree[idx] = tree[idx];
        return;
    }
    
    int mid = (l + r) / 2;
    
    update_mod(2 * idx + 1, l, mid, ql, qr, x);
    update_mod(2 * idx + 2, mid + 1, r, ql, qr, x);
    
    tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
    max_tree[idx] = max(max_tree[2 * idx + 1], max_tree[2 * idx + 2]);
}

long long query_sum(int idx, int l, int r, int ql, int qr) {
    if (l > qr || r < ql) {
        return 0;
    }
    
    if (l >= ql && r <= qr) {
        return tree[idx];
    }
    
    int mid = (l + r) / 2;

    long long left_sum = query_sum(2 * idx + 1, l, mid, ql, qr);
    long long right_sum = query_sum(2 * idx + 2, mid + 1, r, ql, qr);
    
    return left_sum + right_sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    arr.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    tree.resize(4 * n);
    max_tree.resize(4 * n);
    build(0, 0, n - 1);
    
    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int l, r;
            cin >> l >> r;

            cout << query_sum(0, 0, n - 1, l - 1, r - 1) << '\n';
        } else if (type == 2) {
            int l, r;
            long long x;
            cin >> l >> r >> x;
            
            update_mod(0, 0, n - 1, l - 1, r - 1, x);
        } else {
            int k;
            long long x;
            cin >> k >> x;

            update_point(0, 0, n - 1, k - 1, x);
        }
    }
    
    return 0;
}