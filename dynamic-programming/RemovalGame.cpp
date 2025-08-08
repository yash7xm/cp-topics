//Tabulation Appraoch
// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;

//     vector<int> arr(n);
//     for(int i=0; i<n; ++i) {
//     	cin >> arr[i];
//     }

//     vector<vector<ll>> dp(n, vector<ll>(n));

//     for(int g=0; g<n; ++g) {
//     	for(int i=0, j = g; j < n; ++i, ++j) {
//     		if(g == 0) {
//     			dp[i][j] = arr[i];
//     		} else if(g == 1) {
//     			dp[i][j] = max(arr[i], arr[j]);
//     		} else {
//     			ll val1 = arr[i] + min(dp[i+2][j], dp[i+1][j-1]);
//     			ll val2 = arr[j] + min(dp[i+1][j-1], dp[i][j-2]);

//     			dp[i][j] = max(val1, val2);
//     		}
//     	}
//     }

//     cout << dp[0][n-1] << endl;

//     return 0;
// }


// Memoized Approach
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> arr;
vector<vector<ll>> dp;

ll solve(int l, int r) {
    if (l > r) return 0;
    if (dp[l][r] != -1) return dp[l][r];

    if (l == r) return dp[l][r] = arr[l];
    if (r - l == 1) return dp[l][r] = max(arr[l], arr[r]);

    ll val1 = arr[l] + min(solve(l + 2, r), solve(l + 1, r - 1));
    ll val2 = arr[r] + min(solve(l + 1, r - 1), solve(l, r - 2));

    return dp[l][r] = max(val1, val2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    dp.assign(n, vector<ll>(n, -1));
    cout << solve(0, n - 1) << "\n";

    return 0;
}
