#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(vector<int>& arr, ll k) {
	ll supervisor = 0;
	for(int i=0; i<arr.size(); ++i) {
		if(arr[i] > k) return false;

		supervisor += k - arr[i];
	}

	return supervisor >= k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; ++i) {
    	cin >> arr[i];
    }

    ll lo = 1;
    ll hi = accumulate(arr.begin(), arr.end(), 0LL);
    ll ans = hi;

    while(lo <= hi) {
    	ll mid = lo + (hi - lo) / 2;
    	if(check(arr, mid)) {
    		ans = mid;
    		hi = mid - 1;
    	} else {
    		lo = mid + 1;
    	}
    }

    cout << ans << endl;

    return 0;
}