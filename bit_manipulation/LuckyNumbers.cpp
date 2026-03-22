#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n;
  cin >> n;

  vector<ll> list;

  for(int len = 2; len <= 10; len += 2) {
    for(int mask = 0; mask < (1 << len); ++mask) {
      if(__builtin_popcount(mask) == len / 2) {
        ll curr_num = 0;

        for(int bit = 0; bit < len; ++bit) {
          curr_num *= 10;

          if((mask & (1 << bit)) != 0) {
            curr_num += 7;
          } else {
            curr_num += 4;
          }
        }

        list.push_back(curr_num);
      }
    }
  }

  sort(list.begin(), list.end());

  for(ll num : list) {
    if(num >= n) {
      cout << num << "\n";
      return;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
