#include <bits/stdc++.h>
using namespace std;

vector<int> tree, lazy;

void apply_flip(int idx, int l, int r) {
  tree[idx] = (r - l + 1) - tree[idx];
  lazy[idx] ^= 1;
}

void push(int idx, int l, int r) {
  if(!lazy[idx]) return;
  int mid = (l + r) / 2;

  apply_flip(2 * idx + 1, l, mid);
  apply_flip(2 * idx + 2, mid + 1, r);

  lazy[idx] = 0;
}

void update(int idx, int l, int r, int ql, int qr) {
  if(l > qr || r < ql) return;

  if(l >= ql && r <= qr) {
    apply_flip(idx, l, r);
    return;
  }

  push(idx, l, r);

  int mid = (l + r) / 2;

  update(2 * idx + 1, l, mid, ql, qr);
  update(2 * idx + 2, mid + 1, r, ql, qr);

  tree[idx] = tree[2 * idx + 1] + tree[2 * idx + 2];
}

int kth_one(int idx, int l, int r, int k) {
  if(l == r) return l;

  push(idx, l, r);

  int mid = (l + r) / 2;

  if(k < tree[2 * idx + 1]) {
    return kth_one(2 * idx + 1, l, mid, k);
  } else {
    return kth_one(2 * idx + 2, mid + 1, r, k - tree[2 * idx + 1]);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;
  cin >> n >> m;
  
  tree.resize(4 * n, 0);
  lazy.resize(4 * n, 0);

  while(m--) {
    int type;
    cin >> type;

    if(type == 1) {
      int l, r;
      cin >> l >> r;

      update(0, 0, n-1, l, r-1);
    } else {
      int k;
      cin >> k;

      cout << kth_one(0, 0, n-1, k) << '\n';
    }
  }

  return 0;
}
