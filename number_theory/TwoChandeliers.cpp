#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll ext_gcd(ll a, ll b, ll &x, ll &y) {
  if(b == 0) {
    x = 1; y = 0;
    return a;
  }
  ll x1, y1;
  ll g = ext_gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}

ll chinese_remainder(ll r1, ll m1, ll r2, ll m2) {
  ll x, y;
  ll g = ext_gcd(m1, m2, x, y);

  if((r2 - r1) % g != 0) return -1;

  ll lcm = m1 / g * m2;
  ll temp = r1 + x * ((r2 - r1) / g) % (m2 / g) * m1;
  ll t = (temp % lcm + lcm) % lcm;

  return t;
}

ll count_same_days(ll limit, const vector<ll> &sameDays, ll period) {
  ll count = 0;
  for(ll firstDay : sameDays) {
    if(firstDay == -1 || firstDay > limit) continue;

    count += 1 + (limit - firstDay) / period;
  }

  return count;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  ll k;

  cin >> n >> m >> k;
  
  vector<int> a(n), b(m);

  for(int i=0; i<n; ++i) cin >> a[i];
  for(int i=0; i<m; ++i) cin >> b[i];

  ll g = gcd(n, m);
  ll l = n / g * m;

  int maxVal = 2 * max(n, m) + 5;
  vector<ll> posA(maxVal, -1);
  for(int i=0; i<n; ++i) {
    posA[a[i]] = i;
  }

  vector<ll> sameDays;
  for(int j=0; j<m; ++j) {
    int color = b[j];
    if(posA[color] == -1) continue;

    ll t0 = chinese_remainder(posA[color], n, j, m);
    sameDays.push_back(t0);
  }

  ll low = 1, high = k * (ll)max(n, m);
  ll ans = high;

  while(low <= high) {
    ll mid = (low + high) / 2;

    ll same = count_same_days(mid - 1, sameDays, l);
    ll diff = (mid) - same;

    if(diff >= k) {
      ans = mid;
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }

  cout << ans << "\n";
  return 0;
}
