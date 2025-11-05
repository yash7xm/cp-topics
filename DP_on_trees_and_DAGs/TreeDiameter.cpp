// Intuitive DFS based approach

#include <bits/stdc++.h>
using namespace std;
 
const int MAXN = 200005;
vector<int> adj[MAXN];
int n;
 
pair<int, int> dfs(int node, int parent, int dist) {
  pair<int, int> res = {dist, node}; // {distance, node}
  
for(int nxt : adj[node]) {
    if(nxt == parent) continue;
    res = max(res, dfs(nxt, node, dist + 1));
  }
 
  return res;
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
 
  // 1st DFS: from any node (say 1)
  auto far1 = dfs(1, 0, 0);
 
  // 2nd DFS: from farthest node found
  auto far2 = dfs(far1.second, 0, 0);
 
  cout << far2.first << "\n"; // maximum distance = diameter
 
  return 0;
}



// DP on Trees Approach

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> adj[MAXN];
int n;
int dp[MAXN]; // dp[v] = height of subtree rooted at v 
int diameter = 0;

void dfs(int v, int parent) {
  int max1 = 0, max2 = 0; // top two max depths among children

  for(int u : adj[v]) {
    if(u == parent) continue;
    dfs(u, v);

    int depth = dp[u] + 1; // edge from v -> u 

    // keep track of the two largest depths    
    if(depth > max1) {
      max2 = max1;
      max1 = depth;
    } else if(depth > max2) {
      max2 = depth;
    }

    // update diameter through this node 
    diameter = max(diameter, max1 + max2);

    // store height for this node 
    dp[v] = max1;
  }
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

  cout << diameter << "\n";
}
