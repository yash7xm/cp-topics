#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  ll x;
  cin >> x;

  ll num_of_bits = 64 - __builtin_clzll(x);

  ll count = 0;

  for(int i=0; i<num_of_bits; ++i) {
    if((x & (1LL << i)) == 0) {
      count += (1LL << i);
    }
  }

  cout << count << "\n";
}

void solve_OR() {
  ll x;
  cin >> x;

  ll num_of_bits = 64 - __builtin_clzll(x);

  ll res = 0;

  for(int i = 0; i < num_of_bits; ++i) {
    if((x & (1LL << i)) == 0) {
      res |= (1LL << i);
    }
  }

  cout << count << "\n";
}

void solve_xor() {
  ll x;
  cin >> x;

  ll num_of_bits = 64 - __builtin_clzll(x);

  ll full_mask = (1LL << num_of_bits) - 1;

  cout << x ^ full_mask << "\n"; 
}

void solve_diff() {
  ll x;
  cin >> x;

  ll num_of_bits = 64 - __builtin_clzll(x);

  ll full_mask = (1LL << num_of_bits) - 1;

  cout << full_mask - x << "\n"; 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while(t--) solve();

  return 0;
}
