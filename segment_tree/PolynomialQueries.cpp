#include <bits/stdc++.h>
using namespace std;

struct Lazy {
    long long a, d; // first term, common difference
};

vector<long long> tree;
vector<Lazy> lazy;
vector<long long> arr;

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

// sum of AP: a + (a+d) + ... for n terms
long long ap_sum(long long a, long long d, long long n) {
    return n * (2 * a + (n - 1) * d) / 2;
}

void apply(int idx, int l, int r, long long a, long long d) {
    int n = (r - l + 1);
    tree[idx] += ap_sum(a, d, n);
    lazy[idx].a += a;
    lazy[idx].d += d;
}

void push(int idx, int l, int r) {
    if (lazy[idx].a == 0 && lazy[idx].d == 0) return;
    if (l == r) {
        lazy[idx] = {0, 0};
        return;
    }
    int mid = (l + r) / 2;
    int left_len = mid - l + 1;

    // left child gets same (a, d)
    apply(2 * idx + 1, l, mid, lazy[idx].a, lazy[idx].d);

    // right child starts later, so first term shifts
    long long new_a = lazy[idx].a + left_len * lazy[idx].d;
    apply(2 * idx + 2, mid + 1, r, new_a, lazy[idx].d);

    lazy[idx] = {0, 0};
}

void update(int idx, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return;
    if (ql <= l && r <= qr) {
        long long a = l - ql + 1; // first term at position l
        apply(idx, l, r, a, 1);
        return;
    }
    push(idx, l, r);
    int mid = (l + r) / 2;
    update(2 * idx + 1, l, mid, ql, qr);
    update(2 * idx + 2, mid + 1, r, ql, qr);
    tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
}

long long query(int idx, int l, int r, int ql, int qr) {
    if (ql > r || qr < l) return 0;
    if (ql <= l && r <= qr) return tree[idx];
    push(idx, l, r);
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
    for (int i = 0; i < n; i++) cin >> arr[i];

    tree.assign(4 * n, 0);
    lazy.assign(4 * n, {0, 0});
    build(0, 0, n - 1);

    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        --a, --b;
        if (type == 1) {
            update(0, 0, n - 1, a, b);
        } else {
            cout << query(0, 0, n - 1, a, b) << "\n";
        }
    }
    return 0;
}
