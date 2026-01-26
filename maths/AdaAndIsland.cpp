#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> vis;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int dfs(int x, int y) {
    vis[x][y] = true;
    int cnt = 1;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
            !vis[nx][ny] && grid[nx][ny] == '#') {
            cnt += dfs(nx, ny);
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        grid.resize(n);
        for (int i = 0; i < n; i++) cin >> grid[i];

        vis.assign(n, vector<bool>(m, false));

        long long numerator = 0;
        long long denominator = 1LL * n * m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '#' && !vis[i][j]) {
                    long long sz = dfs(i, j);
                    numerator += sz * sz;
                }
            }
        }

        if (numerator == 0) {
            cout << 0 << "\n";
            continue;
        }

        long long g = __gcd(numerator, denominator);
        numerator /= g;
        denominator /= g;

        if (denominator == 1) {
            cout << numerator << "\n";
        } else {
            cout << numerator << " / " << denominator << "\n";
        }
    }
}

