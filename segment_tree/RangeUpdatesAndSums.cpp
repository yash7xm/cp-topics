#include <bits/stdc++.h>
using namespace std;

vector<long long> arr, tree, lazy_add, lazy_set;

void build(int idx, int l, int r) {
    if (l == r) {
        tree[idx] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * idx + 1, l, mid);
    build(2 * idx + 2, mid + 1, r);

    tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
}

void push(int idx, int l, int r) {
    // Handle set first (it overrides add)
    if (lazy_set[idx] != 0) {
        tree[idx] = (r - l + 1) * lazy_set[idx];
        if (l != r) {
            lazy_set[2 * idx + 1] = lazy_set[idx];
            lazy_set[2 * idx + 2] = lazy_set[idx];
            lazy_add[2 * idx + 1] = 0;
            lazy_add[2 * idx + 2] = 0;
        }
        lazy_set[idx] = 0; 
        lazy_add[idx] = 0;
    }

    // Handle add
    if (lazy_add[idx] != 0) {
        tree[idx] += (r - l + 1) * lazy_add[idx];
        if (l != r) {
            if (lazy_set[2 * idx + 1] != 0) lazy_set[2 * idx + 1] += lazy_add[idx];
            else lazy_add[2 * idx + 1] += lazy_add[idx];

            if (lazy_set[2 * idx + 2] != 0) lazy_set[2 * idx + 2] += lazy_add[idx];
            else lazy_add[2 * idx + 2] += lazy_add[idx];
        }
        lazy_add[idx] = 0;
    }
}

void update_sum(int idx, int l, int r, int ql, int qr, int v) {
    push(idx, l, r);
    if (l > qr || r < ql) return;

    if (ql <= l && r <= qr) {
        lazy_add[idx] += v;
        push(idx, l, r);
        return;
    }

    int mid = (l + r) / 2;

    update_sum(2 * idx + 1, l, mid, ql, qr, v);
    update_sum(2 * idx + 2, mid + 1, r, ql, qr, v);

    tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
}

void update_set(int idx, int l, int r, int ql, int qr, int v) {
    push(idx, l, r);
    if (l > qr || r < ql) return;

    if (ql <= l && r <= qr) {
        lazy_set[idx] = v;  
        lazy_add[idx] = 0;

        push(idx, l, r);
        return;
    }

    int mid = (l + r) / 2;

    update_set(2 * idx + 1, l, mid, ql, qr, v);
    update_set(2 * idx + 2, mid + 1, r, ql, qr, v);

    tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
}

long long query(int idx, int l, int r, int ql, int qr) {
    push(idx, l, r);
    if (l > qr || r < ql) return 0;

    if (ql <= l && r <= qr) return tree[idx];

    int mid = (l + r) / 2;
    return query(2 * idx + 1, l, mid, ql, qr) +
           query(2 * idx + 2, mid + 1, r, ql, qr);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    arr.resize(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    tree.assign(4 * n, 0);
    lazy_add.assign(4 * n, 0);
    lazy_set.assign(4 * n, 0); 

    build(0, 0, n - 1);

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b, x;
            cin >> a >> b >> x;

            update_sum(0, 0, n - 1, a - 1, b - 1, x);
        } else if (type == 2) {
            int a, b, x;
            cin >> a >> b >> x;

            update_set(0, 0, n - 1, a - 1, b - 1, x);
        } else {
            int a, b;
            cin >> a >> b;

            cout << query(0, 0, n - 1, a - 1, b - 1) << '\n';
        }
    }

    return 0;
}
