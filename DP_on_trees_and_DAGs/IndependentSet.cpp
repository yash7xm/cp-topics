#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 100005;

vector<int> adj[MAXN];
long long dp[MAXN][2]; // dp[v][0] = white, dp[v][1] = black

void dfs(int v, int parent) {
  dp[v][0] = dp[v][1] = 1; // base case 

  for(int u : adj[v]) {
    if(u == parent) continue;

    dfs(u, v);

    // If v is white -> children can be white or black 
    dp[v][0] = (dp[v][0] * (dp[u][0] + dp[u][1]) % MOD) % MOD;

    // If v is black -> children must be white 
    dp[v][1] = (dp[v][1] * dp[u][0]) % MOD;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for(int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1, 0);

  long long ans = (dp[1][0] + dp[1][1]) % MOD;

  cout << ans << "\n";
}
