#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int n;
vector<vector<int>> adj;
vector<int> color;
vector<int> dp0, dp1;

void dfs(int v, int parent) {
    ll cur0 = 1, cur1 = 0;

    for (int u : adj[v]) {
        if (u == parent) continue;

        dfs(u, v);

        ll a = dp0[u];
        ll b = dp1[u];
        ll sum = (a + b) % MOD;

        ll new_cur0 = (cur0 * sum) % MOD;
        ll new_cur1 = ((cur0 * b) % MOD + (cur1 * sum) % MOD) % MOD;

        cur0 = new_cur0;
        cur1 = new_cur1;
    }

    if (color[v] == 1) {        // black node
        dp0[v] = 0;
        dp1[v] = (int)(cur0 % MOD);
    } else {                    // white node
        dp0[v] = (int)(cur0 % MOD);
        dp1[v] = (int)(cur1 % MOD);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    adj.assign(n, {});
    color.resize(n);
    dp0.assign(n, 0);
    dp1.assign(n, 0);

    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        adj[p].push_back(i);
        adj[i].push_back(p);
    }

    for (int i = 0; i < n; ++i)
        cin >> color[i];

    dfs(0, -1);

    cout << dp1[0] % MOD << "\n";
    return 0;
}

