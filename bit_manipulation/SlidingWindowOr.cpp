#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;

  int x, a, b, c;
  cin >> x >> a >> b >> c;

  int last_seen[30];
  for (int i = 0; i < 30; ++i) {
    last_seen[i] = -1;
  }

  int final_xor = 0;

  for (int i = 1; i <= n; ++i) {

    int temp = x;
    while (temp > 0) {
      int bit = __builtin_ctz(temp);
      last_seen[bit] = i;
      temp &= temp - 1;
    }

    if (i >= k) {
      int current_window_or = 0;
      int window_start = i - k + 1;

      for (int bit = 0; bit < 30; ++bit) {
        current_window_or |= ((last_seen[bit] >= window_start) << bit);
      }

      final_xor ^= current_window_or;
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