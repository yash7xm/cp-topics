#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200005;
vector<vector<int>> adj;
vector<ll> L, R;
vector<array<ll, 2>> dp;

void dfs(int v, int parent) {
  dp[v][0] = dp[v][1] = 0;

  for (int u : adj[v]) {
    if (u == parent) continue;

    dfs(u, v);

    ll takeL = max(dp[u][0] + llabs(L[v] - L[u]),
                    dp[u][1] + llabs(L[v] - R[u]));

    ll takeR = max(dp[u][0] + llabs(R[v] - L[u]),
                    dp[u][1] + llabs(R[v] - R[u]));

    dp[v][0] += takeL;
    dp[v][1] += takeR;
    }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    adj.assign(n + 1, {});
    L.assign(n + 1, 0);
    R.assign(n + 1, 0);
    dp.assign(n + 1, {0, 0});

    for (int i = 1; i <= n; ++i) {
      cin >> L[i] >> R[i];
    }

    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << max(dp[1][0], dp[1][1]) << "\n";
    }

    return 0;
}

