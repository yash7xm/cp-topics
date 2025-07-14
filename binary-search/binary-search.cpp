#include <bits/stdc++.h>
using namespace std;

bool binarySearch(vector<int>& arr, int x) {
	int n = arr.size();

	int lo = 0, hi = n-1;
	int ans = -1;

	while(lo <= hi) {
		int mid = lo + (hi - lo) / 2;
		if(arr[mid] == x) {
			return true;
		} else if(x > arr[mid]) {
			lo = mid + 1;
		} else {
			hi = mid - 1;
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n,k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i=0; i<n; ++i) {
    	cin >> arr[i];
    }

    while(k--) {
    	int x;
    	cin >> x;

    	bool found = binarySearch(arr, x);

    	cout << (found ? "YES" : "NO") << endl;
    }
}