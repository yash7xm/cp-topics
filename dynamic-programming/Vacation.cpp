#include <bits/stdc++.h>
using namespace std;

// Space Optimized
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> arr(3, vector<int>(n));
    for(int j=0; j<n; ++j) {
    	cin >> arr[0][j] >> arr[1][j] >> arr[2][j];
    }

    long long a = arr[0][0];
    long long b = arr[1][0];
    long long c = arr[2][0];

    for(int j=1; j<n; ++j) {
    	long long na = arr[0][j] + max(b, c);
    	long long nb = arr[1][j] + max(a,c);
    	long long nc = arr[2][j] + max(a,b);

    	a = na;
    	b = nb;
    	c = nc;
    }

   	long long res = max(a, max(b, c));

   	cout << res << endl;

    return 0;
}


// Space not optimized
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n;
//     cin >> n;

//     vector<vector<int>> arr(3, vector<int>(n));
//     for(int j=0; j<n; ++j) {
//     	cin >> arr[0][j] >> arr[1][j] >> arr[2][j];
//     }

//     vector<vector<long long>> dp(3, vector<long long>(n, 0));
//     dp[0][0] = arr[0][0];
//     dp[1][0] = arr[1][0];
//     dp[2][0] = arr[2][0];

//     for(int j=1; j<n; ++j) {
//     	dp[0][j] = arr[0][j] + max(dp[1][j-1], dp[2][j-1]);
//     	dp[1][j] = arr[1][j] + max(dp[0][j-1], dp[2][j-1]);
//     	dp[2][j] = arr[2][j] + max(dp[0][j-1], dp[1][j-1]);
//     }

//    	long long res = max(dp[0][n-1], max(dp[1][n-1], dp[2][n-1]));

//    	cout << res << endl;

//     return 0;
// }






