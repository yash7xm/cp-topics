#include <bits/stdc++.h>
using namespace std;

vector<int> arr, tree;

void build(int idx, int l, int r) {
	if(l == r) {
		tree[idx] = 1;
		return;
	}

	int mid = (l + r) / 2;

	build(2*idx + 1, l, mid);
	build(2*idx + 2, mid + 1, r);

	tree[idx] = tree[2*idx + 1] + tree[2*idx + 2];
}

void update(int idx, int l, int r, int k) {
	if(l == r) {
		tree[idx] = 0;
		return;
	}

	int mid = (l + r) / 2;
	
	if(k <= tree[2*idx + 1]) {
		update(2*idx + 1, l, mid, k);
	} else {
		update(2*idx + 2, mid + 1, r, k-tree[2*idx + 1]);
	}

	tree[idx] = tree[2*idx + 1] + tree[2*idx + 2];
}

int query(int idx, int l, int r, int k) {
	if(l == r) {
		return arr[l];
	}

	int mid = (l + r) / 2;

	if(k <= tree[2*idx + 1]) {
		return query(2*idx + 1, l, mid, k);
	} else {
		return query(2*idx + 2, mid + 1, r, k-tree[2*idx + 1]);
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    arr.resize(n);
    for(int i=0; i<n; ++i) {
    	cin >> arr[i];
    }

    tree.resize(4 * n);
    build(0, 0, n-1);

    for(int i=0; i<n; ++i) {
    	int k;
    	cin >> k;

    	cout << query(0, 0, n-1, k) << " ";
    	update(0, 0, n-1, k);
    }

    return 0;
}