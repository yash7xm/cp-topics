#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return abs(a);
    return gcd(b, a % b);
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> a(n, vector<ll>(m));
    vector<string> type(n);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        cin >> type[i];
    }
    
    ll S0 = 0, S1 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (type[i][j] == '0') {
                S0 += a[i][j];
            } else {
                S1 += a[i][j];
            }
        }
    }
    ll D = S0 - S1;
    if (D == 0) {
        cout << "YES\n";
        return;
    }
    
    // Create a grid `diff` where diff[i][j] = 1 for '0', -1 for '1'
    vector<vector<int>> diff(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            diff[i][j] = (type[i][j] == '0') ? 1 : -1;
        }
    }
    
    // Build prefix sum for `diff`
    vector<vector<int>> pre(n+1, vector<int>(m+1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pre[i+1][j+1] = diff[i][j] + pre[i][j+1] + pre[i+1][j] - pre[i][j];
        }
    }
    
    // Function to get the sum of a submatrix [r1, r2) x [c1, c2)
    auto get_sum = [&](int r1, int c1, int r2, int c2) {
        return pre[r2][c2] - pre[r1][c2] - pre[r2][c1] + pre[r1][c1];
    };
    
    ll g = 0;
    int q = (n - k + 1) * (m - k + 1);
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= m - k; j++) {
            int d = get_sum(i, j, i+k, j+k);
            g = gcd(g, d);
        }
    }
    
    if (g == 0) {
        if (D == 0) cout << "YES\n";
        else cout << "NO\n";
    } else {
        if (D % g == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
}