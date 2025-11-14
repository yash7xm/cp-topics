#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<vector<pair<int, ll>>> adj, rev;
vector<int> order, comp;
vector<bool> used;
vector<ll> sccValue;
vector<vector<pair<int, ll>>> dag;
vector<ll> dp;
int s;

// Function to compute toltal mushrooms collectible on one edge 
ll collectMushrooms(ll w) {
  ll k= (ll) (sqrtl((long double) w * 2 + 0.25) - 0.5);

	return (k * (6 * w - (k + 1) * (k + 2))) / 6 + w;
}

// First DFS for Kosaraju (store order) 
void dfs1(int v) {
  used[v] = true;
  for(auto [u, w] : adj[v]) {
    if(!used[u]) dfs1(u);
  }
  order.push_back(v);
}

// Second DFS for Kosaraju (assign components)
void dfs2(int v, int c) {
  comp[v] = c;
  for(auto [u, w] : rev[v]) {
    if(comp[u] == -1) {
      dfs2(u, c);
    }
  }
}

// DFS for DP on DAG 
ll dfsDP(int v) {
  if(dp[v] != -1) return dp[v];
  ll best = 0;
  for(auto [u, w] : dag[v]) {
    best = max(best, w + dfsDP(u));
  }

  return dp[v] = sccValue[v] + best;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> m;
  adj.assign(n + 1, {});
  rev.assign(n + 1, {});

  for(int i = 0; i < m; ++i) {
    int x, y;
    ll w;
    cin >> x >> y >> w;
    adj[x].push_back({y, w});
    rev[y].push_back({x, w});
  }

  cin >> s;

  // Kosaraju step 1
  used.assign(n + 1, false);
  for(int i = 1; i <= n; ++i) {
    if(!used[i]) dfs1(i);
  }

  // Kosaraju step 2
  comp.assign(n + 1, -1);
  int sccCount = 0;
  for(int i = n - 1; i >= 0; --i) {
    int v = order[i];
    if(comp[v] == -1) {
      dfs2(v, sccCount++);
    }
  }

  // Step 3: compute mushroom sum for each SCC 
  sccValue.assign(sccCount, 0);
  for(int v = 1; v <= n; ++v) {
    for(auto [u, w] : adj[v]) {
      if(comp[v] == comp[u]) {
        sccValue[comp[v]] += collectMushrooms(w);
      }
    }
  }

  // Setp 4: build DAG between SCCs 
  dag.assign(sccCount, {});
  for(int v = 1; v <= n; ++v) {
    for(auto [u, w] : adj[v]) {
      if(comp[v] != comp[u]) {
        dag[comp[v]].push_back({comp[u], w});
      }
    }
  }

  // Setp 5: DP on dag
  dp.assign(sccCount, -1);
  ll result = dfsDP(comp[s]);

  cout << result << "\n";
  return 0;
}
