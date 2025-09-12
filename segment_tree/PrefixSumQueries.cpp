#include <bits/stdc++.h>
using namespace std;

struct Node {
	long long prefixSum, sum;
};

const long long NEG_INF = -4e18;

vector<int> arr;
vector<Node> tree;

Node merge(const Node& L, const Node& R) {
	Node node;

	node.prefixSum = max(L.prefixSum, L.sum + R.prefixSum);
	node.sum = L.sum + R.sum;

	return node;
}

void build(int idx, int l, int r) {
	if(l == r) {
		tree[idx] = {arr[l], arr[l]};
		return;
	}

	int mid = (l + r) / 2;

	build(2*idx + 1, l, mid);
	build(2*idx + 2, mid + 1, r);

	tree[idx] = merge(tree[2*idx+1], tree[2*idx+2]);
}

void update(int idx, int l, int r, int pos, int x) {
	if(l == r) {
		tree[idx] = {x, x};
		return;
	}

	int mid = (l + r) / 2;

	if(pos <= mid) {
		update(2*idx + 1, l, mid, pos, x);
	} else {
		update(2*idx + 2, mid + 1, r, pos, x);
	}

	tree[idx] = merge(tree[2*idx+1], tree[2*idx+2]);
}

Node query(int idx, int l, int r, int ql, int qr) {
	if(l > qr || r < ql) return {NEG_INF, 0};

	if(l >= ql && r <= qr) {
		return tree[idx];
	}

	int mid = (l + r) / 2;

	Node left_res = query(2*idx + 1, l, mid, ql, qr);
	Node right_res = query(2*idx + 2, mid + 1, r, ql, qr);

	return merge(left_res, right_res);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    arr.resize(n);
    for(int i=0; i<n; ++i) {
    	cin >> arr[i];
    }

    tree.resize(4 * n);
    build(0, 0, n - 1);

    while(q--) {
    	int type;
    	cin >> type;

    	if(type == 1) {
    		int pos, x;
    		cin >> pos >> x;

    		update(0, 0, n-1, pos - 1, x);
    	} else {
    		int a, b;
    		cin >> a >> b;

    		Node res = query(0, 0, n-1, a-1, b-1);

    		cout << max(0LL, res.prefixSum) << endl;
    	}
    }

    return 0;
}