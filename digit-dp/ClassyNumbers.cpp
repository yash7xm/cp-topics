#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> digits;
ll dp[20][4][2][2];   // pos, nonZeroCount, tight, leadingZero
int len;

ll dfs(int pos, int nz, int tight, int leadingZero) {
    if (pos == len) {
        return (nz <= 3) ? 1 : 0;
    }

    ll &res = dp[pos][nz][tight][leadingZero];
    if (res != -1) return res;

    res = 0;
    int limit = tight ? digits[pos] : 9;

    for (int d = 0; d <= limit; d++) {
        int nextTight = tight && (d == limit);
        int nextLZ = leadingZero && (d == 0);
        int nextNZ = nz + ((d == 0 && nextLZ) ? 0 : (d != 0));

        // simpler: if (leadingZero && d==0) --> nextNZ = nz
        if (leadingZero && d == 0) nextNZ = nz;

        if (nextNZ <= 3) {
            res += dfs(pos + 1, nextNZ, nextTight, nextLZ);
        }
    }
    return res;
}

ll solveUpTo(ll x) {
    if (x < 0) return 0;
    digits.clear();

    if (x == 0) digits.push_back(0);
    while (x > 0) {
        digits.push_back(x % 10);
        x /= 10;
    }
    reverse(digits.begin(), digits.end());
    len = digits.size();

    memset(dp, -1, sizeof(dp));
    return dfs(0, 0, 1, 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        ll L, R;
        cin >> L >> R;
        cout << solveUpTo(R) - solveUpTo(L - 1) << "\n";
    }
}

