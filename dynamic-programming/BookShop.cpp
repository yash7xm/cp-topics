#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> price(n);
    vector<int> pages(n);

    for(int& i : price) cin >> i;
    for(int&i : pages) cin >> i;

    vector<int> dp(x+1, 0);

	for(int i=0; i<n; ++i) {
		for(int j=x; j>=price[i]; --j) {
			dp[j] = max(dp[j], dp[j-price[i]] + pages[i]);
		}
	}

	cout << dp[x] << endl;

    return 0;
}