#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int countDivisors(ll x) {
  ll ans = 1;
  for(ll i = 2; i * i <= x; ++i) {
    int alpha = 0; 
    while(x % i == 0) {
      alpha++;
      x /= i;
    } 
    ans *= (alpha + 1);
  }
  if(x > 1) ans *= 2;

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<ll> a(n);
  for(int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  long long g = 0;
  for(int i = 0; i < n; ++i) {
    g = gcd(a[i], g);
  }

  cout << countDivisors(g) << "\n";

  return 0;
}
