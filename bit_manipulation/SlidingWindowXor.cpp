#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  int x, a, b, c;
  cin >> x >> a >> b >> c;

  int final_xor = 0;

  int num_windows = n - k + 1;

  for (int i = 1; i <= n; ++i) {

    int first_window = (1 > i - k + 1) ? 1 : (i - k + 1);
    int last_window = (i < num_windows) ? i : num_windows;

    int count = last_window - first_window + 1;

    if (count & 1) {
      final_xor ^= x;
    }

    x = (1LL * a * x + b) % c;
  }

  cout << final_xor << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}