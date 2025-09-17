#include <bits/stdc++.h>
using namespace std;

vector<long long> arr, tree, lazy;

void build(int idx, int l, int r) {
	if(l == r) {
		tree[idx] = arr[l];
		return;
	}

	int mid = (l + r) / 2;

	build(2 * idx + 1, l, mid);
	build(2 * idx + 2, mid + 1, r);

	tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
}

void push(int idx, int l, int r) {
	if(lazy[idx] != 0) {
		tree[idx] += (r - l + 1) * lazy[idx];

		if(l != r) {
			lazy[2 * idx + 1] += lazy[idx];
			lazy[2 * idx + 2] += lazy[idx];
		}

		lazy[idx] = 0;
	}
}

void update(int idx, int l, int r, int ql, int qr, int v) {
	push(idx, l, r);

	if(l > qr || r < ql) {
		return;
	}

	if(l >= ql && r <= qr) {
		lazy[idx] += v;
		push(idx, l, r);
		return;
	}

	int mid = (l + r) / 2;

	update(2 * idx + 1, l, mid, ql, qr, v);
	update(2 * idx + 2, mid + 1, r, ql, qr, v);

	tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
}

long long query(int idx, int l, int r, int ql, int qr) {
	push(idx, l, r);

	if(l > qr || r < ql) {
		return 0;
	}

	if(l >= ql && r <= qr) {
		return tree[idx];
	}

	int mid = (l + r) / 2;

	long long left_res = query(2 * idx + 1, l, mid, ql, qr);
	long long right_res = query(2 * idx + 2, mid + 1, r, ql, qr);

	return left_res + right_res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    arr.resize(n, 0);

    tree.resize(4 * n, 0);
    lazy.resize(4 * n, 0);

    build(0, 0, n-1);

    for(int i=0; i<m; ++i) {
    	int type;
    	cin >> type;

    	if(type == 1) {
    		int l, r, v;
    		cin >> l >> r >> v;

    		update(0, 0, n-1, l, r-1, v);
    	} else {
    		int l, r;
    		cin >> l >> r;

    		cout << query(0, 0, n-1, l, r-1) << endl;
    	}
    }

    return 0;
}