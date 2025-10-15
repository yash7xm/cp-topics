#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll power(ll a, ll b, ll mod) {
  ll res = 1;
  a %= mod;

  while(b) {
    if(b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }

  return res;
}

ll nCr_mod_p(int n, int r, int p) {
  if (r > n) return 0;
  ll num = 1, den = 1;
  for(int i=0; i<r; ++i) {
    num = (num * (n - i)) % p;
    den = (den * (i + 1)) % p;
  }

  // Fermat's Little Theorem: a^(p-2) = a^-1 mod p
  return (num * power(den, p - 2, p)) % p;
}

ll nCr_lucas(ll n, ll r, int p) {
  if(r == 0) return 1;
  ll ni = n % p;
  ll ri = r % p;

  return (nCr_lucas(n / p, r / p, p) * nCr_mod_p(ni, ri, p)) % p;
}

ll egcd(ll a, ll b, ll &x, ll &y) {
  if(b == 0) { x = 1; y = 0; return a; }
  ll x1, y1;
  ll g = egcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return g;
}

ll modInverse(ll a, ll m) {
  ll x, y;
  egcd(a, m, x, y);
  x %= m;
  if(x < 0) x += m;
  return x;
}

ll CRT(vector<ll> &rem, vector<ll> &mod) {
  ll M = 1, ans = 0;
  int k = mod.size();
  for(int i=0; i<k; ++i) M *= mod[i];

  for(int i=0; i<k; ++i) {
    ll Mi = M / mod[i];
    ll inv = modInverse(Mi % mod[i], mod[i]);
    ans = (ans + rem[i] * Mi % M * inv % M) % M;
  }

  return (ans % M + M) % M;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  vector<int> primes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

  while(t--) {
    ll n, r, m;
    cin >> n >> r >> m;

    if(r > n) {
      cout << 0 << "\n";
      continue;
    }

    // Factorize M into small primes
    vector<ll> moduli, residues;
    ll temp = m;
    for(int p : primes) {
      if(temp % p == 0) {
        moduli.push_back(p);
        temp /= p;
      }
    }

    // Compute nCr mod each prime (Lucas theorem)
    for(ll p : moduli) {
      residues.push_back(nCr_lucas(n, r, p));
    }

    // Combine all using CRT 
    cout << CRT(residues, moduli) << "\n";
  }

  return 0;
}
