#include <bits/stdc++.h>
using namespace std;

int solve(int l, int r) {
  int xr = l ^ r;

  if(xr == 0) return 0;

  int num_bits = 32 - __builtin_clz(xr);

  return (1 << num_bits) - 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int l, r;
  cin >> l >> r;

  cout << solve(l, r) << "\n";
  return 0;
}
