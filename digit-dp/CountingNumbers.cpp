#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> digits;
ll dp[20][11][2][2];
// pos(0...18), prev(0...9 and 10 = special), tight(0/1), leadingZero(0/1)

ll dfs(int pos, int prevDigit, int tight, int leadingZero) {
  if(pos == (int)digits.size()) {
    return 1; // one valid number built
  }

  ll &res = dp[pos][prevDigit][tight][leadingZero];
  if(res != -1) return res;
  res = 0;

  int limit = tight ? digits[pos] : 9;
  for(int d = 0; d <= limit; ++d) {
    
    // If number has started, apply adjacency rule
    if(!leadingZero) {
      if(d == prevDigit) continue; // adjcanet equal digits not allowed
    }

    int nextTight = tight && (d == limit);
    int nextLeadingZero = (leadingZero && d == 0);

    int nextPrev;
    if(nextLeadingZero) nextPrev = 10; // still no previous digit
    else nextPrev = d;  // real previous digit
    
    res += dfs(pos + 1, nextPrev, nextTight, nextLeadingZero);
  }

  return res;
}

ll countUpTo(ll x) {
  if(x < 0) return 0;

  digits.clear();
  if(x == 0) digits.push_back(0);

  while(x > 0) {
    digits.push_back(x % 10);
    x /= 10;
  }

  reverse(digits.begin(), digits.end());

  memset(dp, -1, sizeof(dp));

  return dfs(0, 10, 1, 1); // start: no prevDigit (10), tight = 1, leadingZero = 1
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << countUpTo(b) - countUpTo(a - 1) << "\n";
}
