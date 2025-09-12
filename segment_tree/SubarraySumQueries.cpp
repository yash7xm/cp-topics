#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node {
	ll sum, maxsubsum, prefix, suffix;
};

vector<int> arr;
vector<Node> tree;
 
Node merge(const Node& left, const Node& right) {
    Node node;

    node.sum = left.sum + right.sum;

    node.prefix = max(left.prefix, left.sum + right.prefix);
    node.suffix = max(right.suffix, right.sum + left.suffix);

    node.maxsubsum = max({left.maxsubsum, right.maxsubsum, left.suffix + right.prefix});

    return node;
}

void build(int idx, int l, int r) {
	if(l == r) {
		tree[idx] = {arr[l], arr[l], arr[l], arr[l]};
		return;
	}

	int mid = (l + r) / 2;

	build(2*idx + 1, l, mid);
	build(2*idx + 2, mid + 1, r);

	tree[idx] = merge(tree[2*idx + 1], tree[2*idx + 2]);
}

void update(int idx, int l, int r, int pos, int x) {
	if(l == r) {
		tree[idx] = {x, x, x, x};
		return;
	}

	int mid = (l + r) / 2;

	if(pos <= mid) {
		update(2*idx + 1, l, mid, pos, x);
	} else {
		update(2*idx + 2, mid + 1, r, pos, x);
	}

	tree[idx] = merge(tree[2*idx + 1], tree[2*idx + 2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    arr.resize(n);
    for(int i=0; i<n; ++i) {
    	cin >> arr[i];
    }

    tree.resize(4 * n);
    build(0, 0, n-1);

    while(m--) {
    	int pos, x;
    	cin >> pos >> x;

    	update(0, 0, n - 1, pos - 1, x);

    	cout << max(0LL, tree[0].maxsubsum) << endl;
    }

    return 0;
}