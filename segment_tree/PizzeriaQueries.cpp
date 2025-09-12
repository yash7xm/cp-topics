#include <bits/stdc++.h>
using namespace std;

void update(int idx, int l, int r, int pos, int x, vector<int>& segTree) {
	if(l == r) {
		segTree[idx] = x;
		return;
	}

	int mid = (l + r) / 2;

	if(pos <= mid) {
		update(2*idx + 1, l, mid, pos, x, segTree);
	} else {
		update(2*idx + 2, mid + 1, r, pos, x, segTree);
	}

	segTree[idx] = min(segTree[2*idx + 1], segTree[2*idx + 2]);
}

int query(int idx, int l, int r, int ql, int qr, vector<int>& segTree) {
	if(l > qr || r < ql) return INT_MAX;

	if(l >= ql && r <= qr) {
		return segTree[idx];
	}

	int mid = (l + r) / 2;

	int left_res = query(2*idx + 1, l, mid, ql, qr, segTree);
	int right_res = query(2*idx + 2, mid + 1, r, ql, qr, segTree);

	return min(left_res, right_res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for(int i=0; i<n; ++i) {
    	cin >> arr[i];
    }

    vector<int> segTree1(4 * n, INT_MAX), segTree2(4 * n, INT_MAX);

    for(int i=0; i<n; ++i) {
    	update(0, 0, n-1, i, arr[i] - (i + 1), segTree1);
    	update(0, 0, n-1, i, arr[i] + (i + 1), segTree2);
    }

    while(q--) {
    	int type;
    	cin >> type;

    	if(type == 1) {
    		int k, x;
    		cin >> k >> x;
    		update(0, 0, n-1, k-1, x - k, segTree1);
    		update(0, 0, n-1, k-1, x + k, segTree2);
    	} else {
    		int k;
    		cin >> k;

    		int left = query(0, 0, n-1, 0, k-1, segTree1);
    		int right = query(0, 0, n-1, k-1, n-1, segTree2);

    		cout << min(left + k, right - k) << endl;
    	}
    }

    return 0;
}