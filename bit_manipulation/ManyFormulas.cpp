#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  string s;
  cin >> s;

  int n = s.length();
  ll sum = 0;

  int gaps = n - 1;

  for(int mask = 0; mask < (1 << gaps); ++mask) {
    ll curr_sum = 0;
    ll curr_num = s[0] - '0';

    for(int bit = 0; bit < gaps; ++bit) {
      if((mask & (1 << bit)) != 0) {
        curr_sum += curr_num;
        curr_num = s[bit + 1] - '0';
      } else {
        curr_num = curr_num * 10 + (s[bit + 1] - '0');
      }
    }

    curr_sum += curr_num;
    sum += curr_sum;
  }

  cout << sum << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solve();

  return 0;
}
