#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = (1LL << 62);

int n;
ll m;
vector<vector<int>> g;
vector<ll> dp, ans;

void dfs1(int v, int p) {
  dp[v] = 1;

  for(int u : g[v]) {
    if(u == p) continue;

    dfs1(u, v);
    dp[v] = (dp[v] * (dp[u] + 1)) % m;
  }
}

void dfs2(int v, int p, ll up) {
  // up = number of ways from the parent side, assuming v is black
  // ans[v] = dp[v] * up (but up already includes parent part)
  ans[v] = (dp[v] * up) % m;

  int k = g[v].size();

  // prefix and suffix products of (dp[u] + 1)
  vector<ll> pref(k), suff(k);

  for(int i = 0; i < k; ++i) {
    int u = g[v][i];
    ll val = (u == p ? 1 : (dp[u] + 1) % m);
    pref[i] = val;
    if(i) pref[i] = (pref[i] * pref[i-1]) % m;
  }

  for(int i = k - 1; i >= 0; --i) {
    int u = g[v][i];
    ll val = (u == p ? 1 : (dp[u] + 1) % m);
    suff[i] = val;
    if(i + 1 < k) suff[i] = (suff[i] * suff[i+1]) % m;
  }

  // Go to each child
  for(int i = 0; i < k; ++i) {
    int u = g[v][i];
    if(u == p) continue;

    ll left = (i == 0 ? 1 : pref[i-1]);
    ll right = (i + 1 == k ? 1 : suff[i+1]);

    ll without_u = (left * right) % m;

    // new_up = ways coming from parent side + siblings
    ll new_up = (up * without_u) % m;

    // now u sees parent contributions as (new_up)
    dfs2(u, v, (new_up + 1) % m);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  g.resize(n + 1);
  dp.resize(n + 1);
  ans.resize(n + 1);

  for(int i = 0; i < n - 1; ++i) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  // First DFS: compute dp
  dfs1(1, -1);

  // Second DFS: rerooting (up value for root = 1)
  dfs2(1, -1, 1);

  for(int i = 1; i <= n; ++i) {
    cout << ans[i] % m << "\n";
  }

  return 0;
}
