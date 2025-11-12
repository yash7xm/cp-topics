#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> color;
vector<vector<int>> adj;
vector<bool> used;
vector<int> comp;
vector<vector<int>> compGraph;
vector<int> dp;
int compCount = 0;
int answer = 0;

// DFS #1 — find connected components of same color
void dfsColor(int v, int col, int cmp) {
    if (used[v] || color[v] != col) return;
    used[v] = true;
    comp[v] = cmp;

    for (int u : adj[v]) {
        dfsColor(u, col, cmp);
    }
}

// DFS #2 — compute diameter in component graph
void dfsDiameter(int v, int parent = -1) {
    int best1 = 0, best2 = 0; // two largest depths among children

    for (int u : compGraph[v]) {
        if (u == parent) continue;
        dfsDiameter(u, v);
        int depth = dp[u] + 1;
        if (depth > best1) {
            best2 = best1;
            best1 = depth;
        } else if (depth > best2) {
            best2 = depth;
        }
    }

    dp[v] = best1;
    answer = max(answer, best1 + best2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    color.resize(n);
    adj.assign(n, {});
    used.assign(n, false);
    comp.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> color[i];

    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // Step 1: group nodes of the same color into components
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            dfsColor(i, color[i], compCount++);
        }
    }

    // Step 2: build component graph (edges between different colors)
    compGraph.assign(compCount, {});
    for (int v = 0; v < n; ++v) {
        for (int u : adj[v]) {
            if (comp[v] != comp[u]) {
                compGraph[comp[v]].push_back(comp[u]);
            }
        }
    }

    // Step 3: find diameter of component graph
    dp.assign(compCount, 0);
    dfsDiameter(0);

    cout << (answer + 1) / 2 << "\n";
    return 0;
}

