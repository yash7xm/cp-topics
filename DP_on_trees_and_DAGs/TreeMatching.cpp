#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
int n;
long long dp[MAXN][2];
bool vis[MAXN];

void dfs(int v, int parent) {
    dp[v][0] = 0;
    dp[v][1] = 0;

    long long sum = 0;
    for(int u : adj[v]) {
      if(u == parent) continue;
      dfs(u, v);
      sum += max(dp[u][0], dp[u][1]);
    }

    dp[v][0] = sum;

    long long best = 0;
    for(int u : adj[v]) {
      if(u == parent) continue;

      long long candidate = 1 + dp[u][0] + (sum - max(dp[u][0], dp[u][1]));
      
      best = max(best, candidate);
    }

    dp[v][1] = best;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  for(int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1, 0);

  cout << max(dp[1][0], dp[1][1]) << "\n";

  return 0;
}
