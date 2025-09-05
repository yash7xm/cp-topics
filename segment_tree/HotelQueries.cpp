#include <bits/stdc++.h>
using namespace std;

vector<int> h, tree;

void build(int idx, int l, int r) {
	if(l == r) {
		tree[idx] = h[l];
		return;
	}

	int mid = (l + r) / 2;

	build(2*idx + 1, l, mid);
	build(2*idx + 2, mid + 1, r);

	tree[idx] = max(tree[2*idx + 1], tree[2*idx + 2]);
}

void update(int idx, int l, int r, int pos, int g) {
	if(l == r) {
		tree[idx] -= g;
		return;
	}

	int mid = (l + r) / 2;

	if(pos <= mid) {
		update(2*idx + 1, l, mid, pos, g);
	} else {
		update(2*idx + 2, mid + 1, r, pos, g);
	}

	tree[idx] = max(tree[2*idx + 1], tree[2*idx + 2]);
}

int query(int idx, int l, int r, int g) {
	if(l == r) {
		if(tree[idx] < g) {
			return -1;
		}
		return l;
	}

	if(tree[idx] < g) {
		return -1;
	}

	int mid = (l + r) / 2;

	if(tree[2*idx + 1] >= g) {
		return query(2*idx + 1, l, mid, g);
	} else {
		return query(2*idx + 2, mid + 1, r, g);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,m;
    cin >> n >> m;

    h.resize(n);
    for(int i=0; i<n; ++i) {
    	cin >> h[i];
    }

    tree.resize(4 * n);
    build(0, 0, n-1);

    for(int i=0; i<m; ++i) {
    	int g;
    	cin >> g;

    	int res = query(0, 0, n-1, g);
    	if(res != -1) {
    		update(0, 0, n-1, res, g);
    	}

    	cout << res + 1 << endl;
    }

    return 0;
}