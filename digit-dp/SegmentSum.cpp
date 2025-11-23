#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 998244353;

vector<int> digits;
long long pow10[20];

pair<long long, long long> dp[20][1<<10][2][2];
bool vis[20][1<<10][2][2];
int K, N;

pair<long long,long long> dfs(int pos, int mask, int tight, int lz) {
    if (pos == N) {
        return {1, 0};
    }

    auto &res = dp[pos][mask][tight][lz];
    if (vis[pos][mask][tight][lz]) return res;
    vis[pos][mask][tight][lz] = true;

    res = {0, 0};

    int limit = tight ? digits[pos] : 9;
    int remaining = N - pos - 1;

    for (int d = 0; d <= limit; d++) {
        int nt = tight && (d == limit);

        int nextMask = mask;
        int nlz = lz;

        if (lz && d == 0) {
            // still leading zeros
            nlz = 1;
        } else {
            nlz = 0;
            nextMask = mask | (1 << d);
        }

        if (__builtin_popcount(nextMask) > K) continue;

        auto child = dfs(pos + 1, nextMask, nt, nlz);

        long long cnt = child.first;
        long long sm = child.second;

        long long add = (d * pow10[remaining]) % MOD;
        add = (add * cnt) % MOD;

        res.first = (res.first + cnt) % MOD;
        res.second = (res.second + sm + add) % MOD;
    }

    return res;
}

long long solveUpTo(long long x) {
    if (x < 0) return 0;

    digits.clear();
    if (x == 0) digits.push_back(0);
    while (x > 0) {
        digits.push_back(x % 10);
        x /= 10;
    }
    reverse(digits.begin(), digits.end());
    N = digits.size();

    memset(vis, 0, sizeof(vis));

    auto ans = dfs(0, 0, 1, 1);
    return ans.second % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long l, r;
    cin >> l >> r >> K;

    pow10[0] = 1;
    for (int i = 1; i < 20; i++) {
        pow10[i] = (pow10[i-1] * 10) % MOD;
    }

    long long ans = (solveUpTo(r) - solveUpTo(l - 1)) % MOD;
    if (ans < 0) ans += MOD;

    cout << ans << "\n";
}

