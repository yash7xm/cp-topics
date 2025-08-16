#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i=0; i<n; ++i) {
    	cin >> arr[i];
    }

    vector<bool> dp(k+1, false);

    for(int i=1; i<=k; ++i) {
    	for(int j=0; j<n; ++j) {
    		if(i >= arr[j]) {
    			if(dp[i-arr[j]] == false) {
    				dp[i] = true;
    				break;
    			}
    		}
    	}
    }

    cout << (dp[k] ? "First" : "Second") << endl;

    return 0;
}