#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> digits;

// dp[pos][tight] -> pair(count_of_numbers, sum_of_digits_of_those_numbers)
pair<ll,ll> dp[20][2];
bool vis[20][2];

pair<ll,ll> dfs(int pos, int tight) {
    if (pos == (int)digits.size()) {
        return {1, 0};   // 1 number: the empty suffix; sum=0
    }
    if (vis[pos][tight]) return dp[pos][tight];

    ll cnt = 0, sum = 0;
    int limit = tight ? digits[pos] : 9;

    for (int d = 0; d <= limit; d++) {
        int nt = (tight && d == limit);
        auto child = dfs(pos + 1, nt);

        cnt += child.first;
        sum += child.second + d * child.first;
    }

    vis[pos][tight] = true;
    return dp[pos][tight] = {cnt, sum};
}

ll solve(ll n) {
    if (n < 0) return 0;

    digits.clear();
    if (n == 0) digits.push_back(0);
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    reverse(digits.begin(), digits.end());

    memset(vis, 0, sizeof(vis));
    return dfs(0, 1).second;  // we want the sum part
}

int main() {
    while (true) {
        ll a, b;
        cin >> a >> b;
        if (a == -1 && b == -1) return 0;

        cout << solve(b) - solve(a - 1) << "\n";
    }
    return 0;
}

