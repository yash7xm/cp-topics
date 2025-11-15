#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> digits;
ll dp[12][2][10001][100];
// dp[pos][tight][sumMod][numMod]

int k, len;

ll dfs(int pos, int tight, int sumMod, int numMod) {
  if(pos == len) {
    return (sumMod % k == 0 && numMod % k == 0) ? 1 : 0;
  }

  ll &res = dp[pos][tight][sumMod][numMod];
  if(res != -1) return res;

  res = 0;
  int limit = tight ? digits[pos] : 9;

  for(int d = 0; d <= limit; ++d) {
    int nextTight = tight && (d == limit);
    int nextSum = (sumMod + d) % k;
    int nextNum = (numMod * 10 + d) % k;

    res += dfs(pos + 1, nextTight, nextSum, nextNum);
  }

  return res;
}

ll solveUpTo(ll x) {
  if(x < 0) return 0;

  digits.clear();
  if(x == 0) digits.push_back(0);

  while(x > 0) {
    digits.push_back(x % 10);
    x /= 10;
  }

  reverse(digits.begin(), digits.end());
  len = digits.size();

  memset(dp, -1, sizeof(dp));

  return dfs(0, 1, 0, 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for(int tc = 1; tc <= t; ++tc) {
    ll a, b;
    cin >> a >> b >> k;

    ll ans = solveUpTo(b) - solveUpTo(a - 1);
    cout << "Case " << tc << ": " << ans << "\n";
  }

  return 0;
}

