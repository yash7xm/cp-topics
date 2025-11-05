#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);
  vector<int> indeg(n + 1, 0);
  vector<int> dp(n + 1, 0);

  for(int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    indeg[y]++;
  }

  //Topological Sort 
  queue<int> q;
  for(int i = 1; i <= n; ++i) {
    if(indeg[i] == 0) q.push(i);
  }

  vector<int> topo;
  while(!q.empty()) {
    int u = q.front(); q.pop();
    topo.push_back(u);
    for(int v : adj[u]) {
      indeg[v]--;
      if(indeg[v] == 0) q.push(v);
    }
  }

  // DP in Topological order 
  for(int u : topo) {
    for(int v : adj[u]) {
      dp[v] = max(dp[v], dp[u] + 1);
    }
  }

  int ans = 0;
  for(int i = 1; i <= n; ++i) {
    ans = max(ans, dp[i]);
  }

  cout << ans << "\n";
}
