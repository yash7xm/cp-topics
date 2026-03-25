#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> fact;

void precomupte_factorials() {
  ll curr = 6;
  int i = 4;

  fact.push_back(curr);

  while(true) {
    curr *= i;
    if(curr > 1000000000000LL) break;
    fact.push_back(curr);
    i++;
  }
}

void solve() {
  ll n;
  cin >> n;
  
  int k = __builtin_popcountll(n);
  int num_factorials = fact.size();

  for(int mask = 0; mask < (1 << num_factorials); ++mask) {
    ll sum = 0;
    for(int i = 0; i < num_factorials; ++i) {
      if((mask & (1 << i)) != 0) {
        sum += fact[i];
      }
    }

    if(sum <= n) {
      int power_of_two = __builtin_popcountll(n - sum);
      int factorials = __builtin_popcount(mask);
      k = min(k, power_of_two + factorials);
    }
  }

  cout << k << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  precomupte_factorials();

  while(t--) solve();

  return 0;
}
