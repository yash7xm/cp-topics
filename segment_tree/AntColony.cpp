#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Node {
	ll gcd, cnt;
};

vector<Node> tree;
vector<ll> arr;

ll gcd(ll a, ll b) {
	if(b == 0) {
		return a;
	}

	return gcd(b, a % b);
}

Node merge(const Node& L, const Node& R) {
    Node res;

    res.gcd = gcd(L.gcd, R.gcd);

    res.cnt = 0;
    
    if (res.gcd == L.gcd) res.cnt += L.cnt;
    if (res.gcd == R.gcd) res.cnt += R.cnt;

    return res;
}

void build(int idx, int l, int r) {
	if(l == r) {
		tree[idx] = {arr[l], 1};
		return;
	}

	int mid = (l + r) / 2;

	build(2*idx + 1, l, mid);
	build(2*idx + 2, mid + 1, r);

	tree[idx] = merge(tree[2*idx + 1], tree[2*idx + 2]);
}

Node query(int idx, int l, int r, int ql, int qr) {
	if(l > qr || r < ql) return {0, 0};

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

    int n;
    cin >> n;

    arr.resize(n);
    for(int i=0; i<n; ++i) {
    	cin >> arr[i];
    }

    tree.resize(4*n);
    build(0, 0, n-1);

    int t;
    cin >> t;

    while(t--) {
    	int l, r;
    	cin >> l >> r;
    	l--; r--;

    	Node res = query(0, 0, n-1, l, r);

    	cout << ((r-l+1) - res.cnt) << endl;
    }

    return 0;
}