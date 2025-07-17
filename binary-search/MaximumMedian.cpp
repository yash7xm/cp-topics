#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool check(vector<int>&arr, int median, int k) {
	int n = arr.size();
	int moves = 0;

	for(int i=n/2; i<n; ++i) {
		if(arr[i] < median) {
			moves += median - arr[i];

			if(moves > k) return false;
		}
	}

	return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i=0; i<n; ++i) {
    	cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    ll lo = arr[n/2];
    ll hi = arr[n-1] + k;
    ll ans = lo;

    while(lo <= hi) {
    	ll mid = lo + (hi - lo) / 2;
    	if(check(arr, mid, k)) {
    		ans = mid;
    		lo = mid + 1;
    	} else {
    		hi = mid - 1;
    	}
    }

    cout << ans << endl;

    return 0;
}