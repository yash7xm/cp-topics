#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50005;
const int MAXK = 505;

vector<int> adj[MAXN];
int n, k;
long long ans = 0;
int dp[MAXN][MAXK];

void dfs(int v, int p) {
  dp[v][0] = 1; // itself
  
  for(int to : adj[v]) {
    if(to == p) continue;

    dfs(to, v);

    // count pairs going through v 
    for(int d = 0; d < k; ++d) {
      ans += (long long)dp[v][k - d - 1] * dp[to][d];
    }

    // merge child's dp into parent dp 
    for(int d = 0; d < k; ++d) {
      dp[v][d + 1] += dp[to][d];
    }
  }


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  for(int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  dfs(1, 0);
  cout << ans << "\n";
  return 0;
}
